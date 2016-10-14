#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
}No;

typedef struct _Cabecalho{
  No *inicio;
  No *final;
}Cabecalho;

void inserir(Cabecalho *lista, int valor){
    No *novo;
    novo = (No*) malloc(sizeof(No));
    novo->info = valor;

    if(lista->inicio == NULL){
      lista.final = novo;
      lista.inicio = novo;
      lista.final->prox = lista->inicio;
    }else{
      novo->prox = lista->inicio;
      lista.inicio = novo;
    }
}

int main(){
  int valor, i;
  Cabecalho lista;
  lista = (Cabecalho)malloc(sizeof(Cabecalho));

  for(i=0; i<5; i++){
    scanf("%d", &valor);
    inserir(&lista, valor);
  }
  printf("%d", lista.inicio->info);
  printf("%d", lista.inicio->prox->info);
  printf("%d", lista.inicio->prox->prox->info);
  printf("%d", lista.inicio->prox->prox->prox->info);
  printf("%d", lista.inicio->prox->prox->prox->prox->info);
  printf("%d", lista.inicio->prox->prox->prox->prox->prox->info);
  printf("%d", lista.inicio->prox->prox->prox->prox->prox->prox->info);
}
