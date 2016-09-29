#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
}No;

No* inserir(No *lista, int valor){
    No *novo;
    novo = (No*) malloc(sizeof(No));
    novo->info = valor;

    if(lista == NULL){
      lista = novo;
      novo->prox = lista;
    }else{
      novo->prox = lista;
      lista = novo;
    }
    return lista;
}

int main(){
  int valor, i;
  No *lista;
  lista = NULL;

  for(i=0; i<5; i++){
    scanf("%d", &valor);
    lista = inserir(lista, valor);
  }
  printf("%d", lista->info);
  printf("%d", lista->prox->info);
  printf("%d", lista->prox->prox->info);
  printf("%d", lista->prox->prox->prox->info);
  printf("%d", lista->prox->prox->prox->prox->info);
  printf("%d", lista->prox->prox->prox->prox->prox->info);
  printf("%d", lista->prox->prox->prox->prox->prox->prox->info);
}
