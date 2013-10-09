/* Arquivo esparsas.c */

#include "esparsas.h"
#include <stdlib.h>
#include <stdio.h>

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
        
        while (auxCab != NUL) {
            auxElem = auxCab->abaixo;
            
            while (auxElem != NUL) {
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
    PontCab prevCab, newCab;
    PontElem auxElem, proxElem, prevElem, newElem;
    int countElemCol = 0; //auxilia no reajuste de ligacoes

    if (i > 0 && j > 0) {   //Validar se e uma posicao valida 
        printf("1 - Posicao validada");
        if (x == 0) { // Novo valor e 0
            printf("2 - Valor é 0 %f \n", x);
            while (auxCab != NUL && j >= auxCab->coluna) {
                 printf("3 - While \n");
     
                if (j == auxCab->coluna) { 
                    printf("4 - j == auxCab \n");  // Coluna existe
                    auxElem = auxCab->abaixo;
                     
                    while (auxElem != NUL && i >= auxElem->linha) {
                        printf("5 - while \n");
              
                        countElemCol += 1;
                        
                        if (i == auxElem->linha) { // Elemento ja existe
                            printf("6 - i == auxElem \n");
                            if (auxElem->abaixo == NUL && countElemCol == 1) {
                                printf("7 - free");
                                free(auxElem);
                                free(auxCab);
                                auxElem = NUL;
                                auxCab = NUL;
                                
                            } else if(auxElem->abaixo == NUL) {
                                printf("8 - free");
                                prevElem->abaixo = NUL;
                                free(auxElem);
                                auxElem = NUL;
                                auxCab = NUL;
                                
                            } else {
                                printf("9 - free");
                                proxElem = auxElem->abaixo;
                                prevElem->abaixo = proxElem; 
                                free(auxElem);
                                auxElem = NUL;
                                auxCab = NUL;
                            }
                        
                        }
                        
                        if (auxElem != NUL) {
                            printf("auxElem !NULL");
                            prevElem = auxElem;
                            auxElem = auxElem->abaixo;
                        }
                    }
                }
                
                if (auxCab != NUL) {
                    printf("AuxCab !null");
                    auxCab = auxCab->direita;
                }
            }
            
        } else { // Valor diferente de 0
             printf("2 - Valor é != 0 %f", x);
             
            if (auxCab == NUL) {
                newElem = (PontElem) malloc(sizeof(ElemMatriz));
                newElem->valor = x;
                newElem->linha = i;
                newElem->abaixo = NUL;
                
                newCab = (PontCab) malloc(sizeof(CabMatriz));
                newCab->coluna = j;
                newCab->abaixo = newElem;
                newCab->direita = NUL;
              
            } else {
                while (auxCab != NUL && j > auxCab->coluna) { 
                    printf("3 - auxCab != NUL && j > auxCab->coluna");
                    prevCab = auxCab;
                    auxCab = auxCab->direita;
                }
                
                if (auxCab != NUL) { // o while parou por j ser <=
                    printf("4 - auxCab != NUL");
                    auxElem = auxCab->abaixo;
                    
                    if (j == auxCab->coluna) {
                        printf("5 - j==auxCab ");
                        while (auxElem != NUL && i > auxElem->linha) {
                            printf("6");
                 
                            prevElem = auxElem;
                            auxElem = auxElem->abaixo;
                        }
                        
                        if (auxElem != NUL) { // i <= linha
                            printf("7 - auxelem != NUL");
                            if (i == auxElem->linha) { //elemento existe, substitui valor
                                auxElem->valor = x;
                                
                            } else { // i < linha
                            printf("8 - i < linha");
                                newElem = (PontElem) malloc(sizeof(ElemMatriz));
                                newElem->valor = x;
                                newElem->linha = i;
                                newElem->abaixo = auxElem;
                                prevElem->abaixo = newElem;
                            }
                            
                        } else if (i > prevElem->linha){// o elem e o ultimo do cab e auxElem==NULL
                        printf("9-  o elem e o ultimo do cab e auxElem==NULL");
                            newElem = (PontElem) malloc(sizeof(ElemMatriz));
                            newElem->valor = x;
                            newElem->linha = i;
                            newElem->abaixo = NUL;
                            prevElem->abaixo = newElem;
                        }
                            
                    } else if (j < auxCab->coluna) {
                        printf("10 - aloca");
                        newElem = (PontElem) malloc(sizeof(ElemMatriz));
                        newElem->valor = x;
                        newElem->linha = i;
                        newElem->abaixo = NUL;
                        
                        newCab = (PontCab) malloc(sizeof(CabMatriz));
                        newCab->coluna = j;
                        newCab->abaixo = newElem;
                        newCab->direita = auxCab;
                        prevCab->direita = newCab;
                    } 
                    
                } else if (j > prevCab->coluna){ // o Cab nao existe e e o ultimo
                    printf("11 - j > prevCab");
                    newElem = (PontElem) malloc(sizeof(ElemMatriz));
                    newElem->valor = x;
                    newElem->linha = i;
                    newElem->abaixo = NUL;
                    
                    newCab = (PontCab) malloc(sizeof(CabMatriz));
                    newCab->coluna = j;
                    newCab->abaixo = newElem;
                    newCab->direita = NUL;
                    
                }
            }
        }
    }
}

/* Devolve o equivalente a 'm[i][j]' */
float ValorMatriz(Matriz m, int i, int j){

   if (m != NUL && i > 0 && j > 0) {
       
       PontCab auxCab = m;
       
       while (auxCab != NUL && auxCab->coluna != j) {
           auxCab = auxCab->direita;
       }
       
       if (auxCab != NUL && auxCab->coluna == j) {

           PontElem auxElem = auxCab->abaixo;

           while (auxElem != NUL && auxElem->linha != i) {
               auxElem = auxElem->abaixo;
           }
           
           if (auxElem != NUL && auxElem->linha == i) {
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
  
    PontCab auxCab = m;
    PontElem auxElem;
    
    *l = 0;
    *c = 0;
    
    while(auxCab != NUL) {
        
        if (*c < auxCab->coluna) {
            *c = auxCab->coluna;
        }
        
        auxElem = auxCab->abaixo;
        
        while(auxElem != NUL) {
        
            if (*l < auxElem->linha) {
                *l = auxElem->linha;
            }
            auxElem = auxElem->abaixo;
        }
        
        auxCab = auxCab->direita;
    }
}

/* Devolve o numero total de nos (elementos do tipo EleMatriz) alocados para 
   representar a matriz esparsa apontada por 'm' */
int NumeroNos(Matriz m){

    int numElems = 0;
    
    if (m != NUL) {
        
        PontCab auxCab = m;
        PontElem auxElem = auxCab->abaixo;
        
        while (auxCab != NUL) {
            while (auxElem != NUL) {
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
        
        while (auxCab != NUL) {
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

/* Faz um novo PontCab que possui as mesmas caracteristicas do passado
   como argumento, como se fosse uma copia. */
PontCab CopiaCab (PontCab cab) {
    
    PontElem newElem, prevNewElem, auxElem;
    PontCab newCab = (PontCab) malloc(sizeof(CabMatriz));
    newCab->coluna = cab->coluna;
    newCab->abaixo = NUL;
    newCab->direita = NUL;
   
    auxElem = cab->abaixo;
    
    while (auxElem != NUL) {
        newElem = (PontElem) malloc(sizeof(ElemMatriz));
        newElem->valor = auxElem->valor;
        newElem->linha = auxElem->linha;
        newElem->abaixo = NUL;
        
        if (newCab->abaixo == NUL) {
            newCab->abaixo = newElem;
        } else {
            prevNewElem->abaixo = newElem;
        }       
        
        prevNewElem = newElem;
        auxElem = auxElem->abaixo; 
        
    }
    
    return newCab;
    
}

/*Faz um novo PontCab, a partir da soma de dois outros PontCab */
PontCab SomaCabs (PontCab cabA, PontCab cabB) {

    PontElem newElem, prevNewElem, auxElemA, auxElemB;
    PontCab newCab = (PontCab) malloc(sizeof(CabMatriz));
    newCab->coluna = cabA->coluna;
    newCab->abaixo = NUL;
    newCab->direita = NUL;
    
    auxElemA = cabA->abaixo;
    auxElemB = cabB->abaixo;
    
    while (auxElemA != NUL || auxElemB != NUL) {
        newElem = (PontElem) malloc(sizeof(ElemMatriz));
        newElem->valor = NUL;
        newElem->linha = NUL;
        newElem->abaixo = NUL;
        
        if (auxElemA == NUL) {
            newElem->valor = auxElemB->valor;
            newElem->linha = auxElemB->linha;
            auxElemB = auxElemB->abaixo;
       
        } else if (auxElemB == NUL) {
            newElem->valor = auxElemA->valor;
            newElem->linha = auxElemA->linha;
            auxElemA = auxElemA->abaixo;
        
        } else{
            
            if (auxElemA->linha == auxElemB->linha) {
                newElem->valor = auxElemB->valor + auxElemA->valor;
                newElem->linha = auxElemB->linha;
                auxElemA = auxElemA->abaixo;
                auxElemB = auxElemB->abaixo;
            
            } else if (auxElemA->linha < auxElemB->linha) {
                newElem->valor = auxElemA->valor;
                newElem->linha = auxElemA->linha;
                auxElemA = auxElemA->abaixo;
            
            } else {
                newElem->valor = auxElemB->valor;
                newElem->linha = auxElemB->linha;
                auxElemB = auxElemB->abaixo;
            }
        }
        
        if (newCab->abaixo == NUL) {
            newCab->abaixo = newElem;
        
        } else {
            prevNewElem->abaixo = newElem;
        }
        
        prevNewElem = newElem;
    }
    
    return newCab;
}

/* Devolve o endereco do primeiro PontCab de uma nova matriz correspondendo a 
   soma das matrizes apontadas por a e b: a+b.
   Tente fazer uma implementacao eficiente (nao faz sentido tentar somar dois
   elementos que nao existem (que teriam valor zero) na matriz. */
Matriz SomaMatriz(Matriz a, Matriz b) {
 
    PontCab auxCabA = a;
    PontCab auxCabB = b;
    PontCab prevCab, newCab;
    Matriz newMatriz; 
    
    IniciaMatriz(&newMatriz);
        
    while (auxCabA != NUL || auxCabB != NUL) {
        
        if (auxCabA == NUL) {
            newCab = CopiaCab(auxCabB);
            auxCabB = auxCabB->direita;
        
        } else if (auxCabB == NUL) {
            newCab = CopiaCab(auxCabA);
            auxCabA = auxCabA->direita;
            
        } else {
            
            if (auxCabA->coluna == auxCabB->coluna) {
                newCab = SomaCabs(auxCabA, auxCabB);
                auxCabA = auxCabA->direita;
                auxCabB = auxCabB->direita;
            } else if (auxCabA->coluna < auxCabB->coluna) {
                newCab = CopiaCab(auxCabA);
                auxCabA = auxCabA->direita;
            } else { 
                newCab = CopiaCab(auxCabB);
                auxCabB = auxCabB->direita;
            }
        }
        
        if (newMatriz == NUL){
            newMatriz = newCab;
        } else {
            prevCab->direita = newCab;
        }
        
        prevCab = newCab;
    }
    
    return newMatriz;
    
}





 
