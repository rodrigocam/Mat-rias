#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
}No;

No* inserir(No *lista, int valor){
  No *novo;
  novo = (No*)malloc(sizeof(No));
  novo->info = valor;
  novo->prox = NULL;

  if(lista == NULL){
    lista = novo;
  }else{
    novo->prox = lista;
    lista = novo;
  }
  return lista;
}

void exibir(No *lista){
  No *aux;
  aux = lista;

  if(aux != NULL){
    printf("%d\n", aux->info);
    exibir(aux->prox);
  }
}

void exibirInverso(No *lista){
  No *aux;
  aux = lista;
  
  if(aux != NULL){
    exibirInverso(aux->prox);
    printf("%d\n", aux->info);
  }
}

No* destruir(No *lista){
  No *aux, *lixo;
  aux = lista;
  if(aux != NULL){
    lixo = aux;
    aux = aux->prox;
    lixo->prox = NULL;
    free(lixo);
    destruir(aux);
  }else{
    lista = NULL;
  }
}

int main(){
  int i, valor;
  No *lista;
  lista = NULL;

  for(i=0; i<7; i++){
    scanf("%d", &valor);
    lista = inserir(lista, valor);
  }
  //destruir(lista);
  exibirInverso(lista);
  printf("\n\n");
  exibir(lista);
}
