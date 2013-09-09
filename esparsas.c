/* Arquivo esparsas.c */

#include "esparsas.h"
#include <stdlib.h>

/* Coloca NUL na memoria apontada por m */
void IniciaMatriz(PontMatriz m){
     *m = NUL;
}



/* Libera a memoria de todos os elementos (normais e cabecas) da matriz 
   apontada por m e coloca NUL na posicao de memoria apontada por m */
void LiberaMatriz(PontMatriz m){
   PontCab c = *m;
   PontCab aux;
   PontElem e,auxe;
   while(c != NULL){
      e = c -> abaixo;
      while(e != NULL){
         auxe = e -> abaixo;
         free(e);
         e = auxe;
      }      
      aux = c -> direita;
      free(c);
      c = aux;
   }
   *m = NUL;
}
void BuscaSeqExc(PontMatriz m, int i , int j, PontCab ant, PontCab c, PontElem ante , PontElem e){
   ant = NULL;
   ante = NULL;
   c = *m;
   while(c != NULL && c -> coluna < j){
      ant = c;
      c = c -> direita;
   }
   
   if(c == NULL) return;
   
   e = c -> abaixo;
   while(e != NULL && e -> linha < i){
      ante = e;
      e = e -> abaixo;
   }
   
}
/* Simula 'm[i][j] = x', isto e:
   caso o elemento m[i][j] ja exista atribuiu o valor x a ele (caso x=0, 
      elimina este elemento da matriz);
   caso o elmeneto m[i][j] nao exista e x!=0 insere o elemento na estrutura */
void AtribuiMatriz(PontMatriz m, int i, int j, float x){
   PontCab ant,c;
   PontElem ante,e;

   BuscaSeqExc(m,i,j,ant,c,ante,e);

   if(x != 0){//inserir/modificar elemento da matriz
      if(e != NULL){// mudar o valor do registro apenas;
         e -> valor = x;
         return;
      }
      // a partir daqui esse malloc eh nescessario
      e = (PontElem) malloc(sizeof(ElemMatriz));
      e -> valor = x;
      e -> linha = i;
      e -> abaixo = NULL;

      if(ante != NULL){// inserir no meio da coluna
         e -> abaixo = ante -> abaixo;
         ante -> abaixo = e;
         return;
      }

      if(c != NULL){ //inserir no começo da coluna
         e -> abaixo = c -> abaixo;
         c -> abaixo = e;
         return;
      }

      // a partir daqui esse malloc eh nescessario
      c = (PontCab) malloc(sizeof(CabMatriz));
      c -> coluna = j;
      c -> abaixo = e;

      if(ant != NULL){//inserir no meio da lista de cabs
         c -> direita = ant -> direita;
         ant -> direita = c;
         return;
      }
      //inserir no começo da matriz (ultimo caso ,verificação desnecessaria)
      *m = c;

   }else{//remover elemento da matriz
      if(e == NULL) return;//nada para fazer caso o elemento não exista
      if(ante == NULL){// é o primeiro elemento da coluna
         c -> abaixo = e -> abaixo;
      }else{
         ante -> abaixo = e -> abaixo;
      }
      if(e -> abaixo == NULL){// é o unico elemento da coluna
         if(ant == NULL){// é a primeira coluna da matriz
            *m = c -> direita;
         }else{
            ant -> direita = c -> direita;
         }
         free(c);
      }
      free(e); // nesse ponto não devem existir na estrutura referencias à e

   }

}

/* Devolve o equivalente a 'm[i][j]' */
float ValorMatriz(Matriz m, int i, int j){
   PontCab ant,c;
   PontElem ante,e;

   BuscaSeqExc(m,i,j,ant,c,ante,e);
   if(e == NULL){
      return 0;
   }
   return e -> valor;
}

/* Retorna as dimensoes maximas de 'm' nas memorias apontadas em 
   'l' (numero de linhas) e 'c' (numero de colunas). Se m==NUL retorna 0 e 0 nas
   memorias apontadas por l e c */
void OrdemMatriz(Matriz  m, int* l, int* c){
   PontCab cab = *m;
   PontElem e;
   *l = 0;
   while(c -> direita!= NULL){
      cab = cab -> direita;
      e = cab -> abaixo;
      while (e -> abaixo != NULL){
         e = e -> abaixo;
      }
      if( e!= NULL && *l < e -> linha)  *l = e -> linha;
   }

   if( cab != NULL) *c = cab -> coluna; 
   else *c = cab -> coluna;
}

/* Devolve o numero total de nos (elementos do tipo EleMatriz) alocados para 
   representar a matriz esparsa apontada por 'm' */
int NumeroNos(Matriz m){

/* Completar */

   return 0;
}

/* Devolve o numero total de cabecalhos (elementos do tipo CabMatriz) alocados 
   para representar a matriz esparsa apontada por 'm' */
int NumeroCabecalhos(Matriz m){

/* Completar */

   return 0;
}

/* Devolve o tamanho em bytes de um nó (ElemMatriz) usado na representação */
int TamanhoNo(){

/* Completar */

   return 0;
}

/* Devolve o tamanho em bytes de um cabecalho (CabMatriz) usado na representação */
int TamanhoCabecalho(){

/* Completar */

   return 0;
}

/* Devolve o endereco do primeiro PontCab de uma nova matriz correspondendo a 
   soma das matrizes apontadas por a e b: a+b.
   Tente fazer uma implementacao eficiente (nao faz sentido tentar somar dois
   elementos que nao existem (que teriam valor zero) na matriz. */
Matriz SomaMatriz(Matriz a, Matriz b) {

/* Completar */

   return NUL;    
}
 