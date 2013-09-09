/* Arquivo esparsas.h */

#define NUL 0

typedef struct MatrAux {
  int linha;
  float valor;
  struct MatrAux *abaixo;
} ElemMatriz, *PontElem;

typedef struct CabAux {
  int coluna;
  struct CabAux *direita;
  PontElem abaixo;
} CabMatriz, *PontCab, *Matriz;

typedef Matriz* PontMatriz;

void IniciaMatriz(PontMatriz m);
/* Coloca NUL na memoria apontada por m */

void LiberaMatriz(PontMatriz m);
/* Libera a memoria de todos os elementos (normais e cabecas) da matriz 
   apontada por m e coloca NUL na posicao de memoria apontada por m */

void AtribuiMatriz(PontMatriz m, int i, int j, float x);
/* Simula 'm[i][j] = x', isto e:
   caso o elemento m[i][j] ja exista atribuiu o valor x a ele (caso x=0, 
      elimina este elemento da matriz);
   caso o elmeneto m[i][j] nao exista e x!=0 insere o elemento na estrutura */

float ValorMatriz(Matriz m, int i, int j);
/* Devolve o equivalente a 'm[i][j]' */

void OrdemMatriz(Matriz  m, int *l, int *c);
/* Retorna as dimensoes maximas de 'm' nas memorias apontadas em 
   'l' (numero de linhas) e 'c' (numero de colunas). Se m==NUL retorna 0 e 0 nas
   memorias apontadas por l e c */

int NumeroNos(Matriz m);
/* Devolve o numero total de nos (elementos do tipo ElemMatriz) alocados para 
   representar a matriz esparsa apontada por 'm' */

int NumeroCabecalhos(Matriz m);
/* Devolve o numero total de cabecalhos (elementos do tipo CabMatriz) alocados 
   para representar a matriz esparsa apontada por 'm' */

int TamanhoNo();
/* Devolve o tamanho em bytes de um nó (EleMatriz) usado na representação */

int TamanhoCabecalho();
/* Devolve o tamanho em bytes de um cabecalho (CabMatriz) usado na representação */

Matriz SomaMatriz(Matriz  a, Matriz b) ;
/* Devolve o endereco do primeiro PontCab de uma nova matriz correspondendo a 
   soma das matrizes apontadas por a e b: a+b.
   Tente fazer uma implementacao eficiente (nao faz sentido tentar somar dois
   elementos que nao existem (que teriam valor zero) na matriz. */
 
