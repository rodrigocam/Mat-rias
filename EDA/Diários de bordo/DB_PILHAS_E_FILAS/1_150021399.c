#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Autor: Rodrigo Oliveira */

typedef struct _Pessoa{
  char nome[30];
  int ticket;
}Pessoa;

typedef struct _Fila{
  Pessoa **vet;
  int inicio;
  int fim;
}Fila;

Fila* inicializa(int n){
  Fila *fila;
  int i;
  fila = (Fila*) malloc (sizeof(Fila));
  fila->vet = (Pessoa**) malloc (n*sizeof(Pessoa*));
  for(i = 0 ; i<n; i++){
    fila->vet[i] = (Pessoa*) malloc (n*sizeof(Pessoa));
  }
  fila->inicio = 0;
  fila->fim = 0;

  return fila;
}

void insere(Fila *fila, Pessoa* pessoa){
  fila->vet[fila->fim++] = pessoa;
}

void remover(Fila *fila){
  if(fila->inicio == fila->fim){
    printf("Fila vazia!\n");
  }else{
    fila->inicio++;
  }
}
int main(){
  int i, tFila, cestas;
  char nome[30];
  Pessoa* pessoa;
  Fila *fila1, *fila2;
  scanf("%d %d", &cestas, &tFila);
  fila1 = inicializa(tFila);
  fila2 = inicializa(tFila*tFila);
  for(i=0; i<tFila; i++){
    pessoa = (Pessoa*) malloc (sizeof(Pessoa));
    scanf("%s", nome);
    strcpy(pessoa->nome, nome);
    getchar();
    scanf("%d", &pessoa->ticket);
    getchar();
    insere(fila2, pessoa);
  }
  i = 0;
  while(cestas > 0 && fila2->fim != fila2->inicio){
    if(fila2->vet[i]->ticket > 1){
      fila2->vet[i]->ticket--;
      insere(fila2, fila2->vet[i]);
      insere(fila1, fila2->vet[i]);
      remover(fila2);
    }else{
      insere(fila1, fila2->vet[i]);
      remover(fila2);
    }
    i++;
    --cestas;
  }
  if(cestas > 0){
    printf("AS CESTAS ATENDERAM A TODOS OS CIDADAOS\n");
  }else{
    printf("%s RECEBEU A ULTIMA CESTA\n", fila1->vet[fila1->fim-1]->nome);
  }


  return 0;
}
