/* Arquivo testaesparsas.c */
#include <stdio.h>
#include "esparsas.h"

void LeMatriz(PontMatriz a) {
/* Inicializa e lê os elementos de 'a' */
  int i,j;
  float x;
  IniciaMatriz(a);
  do {
   scanf("%d %d %f",&i,&j,&x);
   if (i!=0)
     AtribuiMatriz(a,i,j,x);
  } while (i!=0);
}

void ImprimirListaDeCabecalhos(Matriz a){
  if (!a) return;
  PontCab c1 = a;
  PontElem e;
  printf("Indices das Colunas: %d", c1->coluna);
  c1 = c1->direita;
  while (c1){
    printf("->%d", c1->coluna);
    c1 = c1->direita;
  }
  printf("\n");
}

void EscreveMatriz(Matriz a) {
  int m,n,i,j;
  float x;
  OrdemMatriz(a,&m,&n);
  printf("Linha Maxima: %3d , Coluna Maxima: %3d\n",m,n);
  printf("Elementos Normais: %3d , Elementos Cabecalho: %3d\n",NumeroNos(a), NumeroCabecalhos(a));
  PontCab c = a;
  PontElem e;
  while (c){
    e = c->abaixo;
    while (e){
      printf("%3d %3d %6.1f\n",e->linha,c->coluna,e->valor);      
      e = e->abaixo;
    }
    c = c->direita;
  }      
}

float Custo(Matriz a) {
/* Calcula o custo em uso de memoria da representação esparsa em
   comparação com a usual, em porcentagem */
  int m,n;
  OrdemMatriz(a,&m,&n);
  if (m*n!=0)
    return 100.0*(NumeroNos(a)*TamanhoNo()+NumeroCabecalhos(a)*TamanhoCabecalho())
                  /(m*n*sizeof(float));
  else
    return 100;
}

int main() {
  Matriz a,b,c;
  LeMatriz(&a);
  EscreveMatriz(a);
  printf("Custo: %6.3f%%\n",Custo(a));
  ImprimirListaDeCabecalhos(a);
  LeMatriz(&b);
  EscreveMatriz(b);
  printf("Custo: %6.3f%%\n",Custo(b));
  ImprimirListaDeCabecalhos(b);
  c = SomaMatriz(a,b);
  if (c==NUL) 
    printf("A matriz soma esta vazia\n");
  else {
    EscreveMatriz(c);
    printf("Custo: %6.3f%%\n",Custo(c));
    ImprimirListaDeCabecalhos(c);    
    LiberaMatriz(&c);
  }
  LiberaMatriz(&a);
  LiberaMatriz(&b);
  printf("\n");
//  system("pause");
  return 0;
}
