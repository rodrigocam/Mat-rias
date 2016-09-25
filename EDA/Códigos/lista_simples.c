#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
}No;

No* inserirInicio(No *lista, int valor){
  No *novo;
  novo = (No*)malloc(sizeof(No));
  novo->prox = NULL;
  novo->info = valor;
  if(lista == NULL){
    lista = novo;
  }else{
    novo->prox = lista;
    lista = novo;
  }
  return lista;
}

No* inserirFinal(No *lista, int valor){
  No *novo, *aux;
  // aux = (No*)malloc(sizeof(No));
  novo = (No*)malloc(sizeof(No));
  novo->prox =  NULL;
  novo->info = valor;
  aux=lista;
  if(lista == NULL){
    lista = novo;
  }else{
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = novo;
  }
  return lista;
}

void exibir(No *lista){
  No *aux;
  aux = lista;
  while(aux != NULL){
    printf("%d ", aux->info);
    aux = aux->prox;
  }
}

int main(){
  int i, n, valor;
  No *lista;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &valor);
    lista = inserirFinal(lista, valor);
  }
  exibir(lista);
}
