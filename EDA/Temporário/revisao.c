#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
}No;

typedef struct _Cabecalho{
  int qtd;
  struct _No *inicio;
  struct _No *final;
}Cabecalho;

Cabecalho* insere(Cabecalho *lista, int valor){
   No *novo;
  novo = (No*)malloc(sizeof(No));
  novo->info= valor;
  if(lista == NULL){
    lista->inicio = novo;
    lista->final = novo;
  }else{
    novo->prox = lista->inicio;
    lista->inicio = novo;
  }
}

void exibe(Cabecalho *lista){
    No *aux;
    //for(aux = lista->inicio; aux != NULL; aux = aux->prox){
      printf("%d ", lista->final->info);
    //}
}

int main(){
  Cabecalho *lista;
  lista = (Cabecalho*) malloc (sizeof(Cabecalho));
  int i, valor;
  for(i=0; i<4; i++){
    scanf("%d", &valor);
    insere(lista, valor);
  }
  exibe(lista);
}
