/* Arquivo esparsas.c */

#include "esparsas.h"
#include <malloc.h>

/* Coloca NUL na memoria apontada por m */
void IniciaMatriz(PontMatriz m){
     *m = NUL;
}

/* Libera a memoria de todos os elementos (normais e cabecas) da matriz 
   apontada por m e coloca NUL na posicao de memoria apontada por m */
void LiberaMatriz(PontMatriz m){
    
    if (*m != NUL) {
    
        PontCab auxCab = *m;
        PontCab freeCab;
        PontElem auxElem, freeElem;
        
        while (auxCab != NULL) {
            auxElem = auxCab->abaixo;
            
            while (auxElem != NULL) {
                freeElem = auxElem;
                auxElem = freeElem->abaixo;
                free(freeElem);
            }
            
            freeCab = auxCab;
            auxCab = freeCab->direita;
            free(freeCab);
        }
        *m = NUL;
	} 

}

/* Simula 'm[i][j] = x', isto e:
   caso o elemento m[i][j] ja exista atribuiu o valor x a ele (caso x=0, 
      elimina este elemento da matriz);
   caso o elmeneto m[i][j] nao exista e x!=0 insere o elemento na estrutura */
void AtribuiMatriz(PontMatriz m, int i, int j, float x){

    PontCab auxCab = *m;
    PontElem auxElem, proxElem, prevElem;
    int countElemCol = 0; //auxilia no reajuste de ligacoes

    if (i > 0 && j > 0) {   //Validar se e uma posicao valida

        if (x == 0) { // Novo valor e 0
            
            while (auxCab != NULL && j > auxCab->coluna) {
                
                if (j == auxCab->coluna) {   // Coluna existe
                    auxElem = auxCab->abaixo;
                    
                    while (auxElem != NULL && i > auxElem->linha) {
                        countElemCol += 1;
                        
                        if (i == auxElem->linha) { // Elemento ja existe
                            
                            if (auxElem->abaixo == NULL && countElemCol == 1) {
                                free(auxElem);
                                free(auxCab);
                                auxCab = NULL;
                                
                            } else if(auxElem->abaixo == NULL) {
                                prevElem.abaixo = NULL;
                                free(auxElem);
                                
                            } else {
                                proxElem = aux->abaixo;
                                prevElem.abaixo = proxElem;
                                free(auxElem);
                                auxCab = NULL;
                            }
                        
                        }
                        
                        prevElem = auxElem;
                        auxElem = auxElem->abaixo;
                    }
                }
                
                auxCab = auxCab->direita;
            }
            
        } else { // Valor diferente de 0
            //falta caso 2 :D
        }
    }
}

/* Devolve o equivalente a 'm[i][j]' */
float ValorMatriz(Matriz m, int i, int j){

   if (m != NUL && i > 0 && j > 0) {
       
       PontCab auxCab = m;
       
       while (auxCab != NULL && auxCab->coluna != j) {
           auxCab = auxCab->direita;
       }
       
       if (auxCab != NULL && auxCab->coluna == j) {

           PontElem auxElem = auxCab->abaixo;

           while (auxElem != NULL && auxElem->linha != i) {
               auxElem = auxElem->abaixo;
           }
           
           if (auxElem != NULL && auxElem->linha == i) {
               return auxElem->valor;
           }
       }
   
   }

   return 0;
}

/* Retorna as dimensoes maximas de 'm' nas memorias apontadas em 
   'l' (numero de linhas) e 'c' (numero de colunas). Se m==NUL retorna 0 e 0 nas
   memorias apontadas por l e c */
void OrdemMatriz(Matriz  m, int* l, int* c){

/* Completar */

}

/* Devolve o numero total de nos (elementos do tipo EleMatriz) alocados para 
   representar a matriz esparsa apontada por 'm' */
int NumeroNos(Matriz m){

    int numElems = 0;
    
    if (m != NUL) {
        
        PontCab auxCab = m;
        PontElem auxElem = auxCab->abaixo;
        
        while (auxCab != NULL) {
            while (auxElem != NULL) {
                numElems += 1;
                auxElem = auxElem->abaixo;
            }
            
            auxCab = auxCab->direita;
        }
    }
    
    return numElems;


}

/* Devolve o numero total de cabecalhos (elementos do tipo CabMatriz) alocados 
   para representar a matriz esparsa apontada por 'm' */
int NumeroCabecalhos(Matriz m){
    
    int numCabs = 0;
    
    if (m != NUL) {
        
        PontCab auxCab = m;
        
        while (auxCab != NULL) {
            numCabs += 1;
            auxCab = auxCab->direita;
        }    
    }
    
    return numCabs;
    
}

/* Devolve o tamanho em bytes de um nó (ElemMatriz) usado na representação */
int TamanhoNo(){

    return sizeof(ElemMatriz);

}

/* Devolve o tamanho em bytes de um cabecalho (CabMatriz) usado na representação */
int TamanhoCabecalho(){

    return sizeof(CabMatriz);

}

/* Devolve o endereco do primeiro PontCab de uma nova matriz correspondendo a 
   soma das matrizes apontadas por a e b: a+b.
   Tente fazer uma implementacao eficiente (nao faz sentido tentar somar dois
   elementos que nao existem (que teriam valor zero) na matriz. */
Matriz SomaMatriz(Matriz a, Matriz b) {

/* Completar */

   return NUL;    
}
 
