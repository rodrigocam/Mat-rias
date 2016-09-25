#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
}No;

No* insere(No *lista, int valor){
    No *novo;
    novo = (No*)malloc(sizeof(No));
    novo->info = valor;
    novo->prox = lista;
    lista = novo;
    return lista;
}

No* ordena(No *lista){
    int qtd = 0;
    int i, temp;
    No *aux;
    aux = lista;
    while(aux != NULL){
      qtd++;
      aux = aux->prox;
    }
    aux = lista;
    for(i=qtd; i>=0; i--){
      aux = lista;
      while(aux != NULL){
        if(aux->prox != NULL && aux->info > aux->prox->info){
          temp = aux->prox->info;
          aux->prox->info = aux->info;
          aux->info = temp;
        }
        aux = aux->prox;
      }
    }
    return lista;
}

void exibir(No *lista){
  No* aux;
  aux = lista;
  while(aux != NULL){
    printf("%d ", aux->info);
    aux = aux->prox;
  }
}

int main(){
  No *lista;
  int valor, i;

  for(i=0; i<7; i++){
    scanf("%d", &valor);
    lista = insere(lista, valor);
  }
  lista = ordena(lista);
  exibir(lista);
}
