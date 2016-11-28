#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
  struct _No *ant;
}No;

typedef struct _Cabec{
  int qtd;
  No *ini;
  No *fim;
}Cabec;

void inserir(Cabec *lista, int info){
  No *novo;
  novo = (No*)malloc(sizeof(No));
  novo->info = info;
  novo->prox = novo->ant = NULL;
  if(lista->ini == NULL){
    lista->ini = novo;
    lista->fim = novo;
  }else{
    lista->fim->prox = novo;
    novo->ant = lista->fim;
    lista->fim = novo;
  }
  lista->qtd++;
}

void remover(Cabec *lista){
  No *aux;
  aux = lista->fim;
  lista->fim = lista->fim->ant;
  lista->fim->prox = NULL;
  lista->qtd--;
  free(aux);
}

void exibir(Cabec *lista){
  No *aux;
  int i;
  aux = lista->ini;
  for(i = 0; i<lista->qtd; i++){
    printf("%d\n", aux->info);
    aux = aux->prox;
  }
}

int main(){
  int i, num;
  Cabec *lista;
  lista = (Cabec*)malloc(sizeof(Cabec));
  lista->qtd = 0;
  lista->ini = lista->fim = NULL;
  for(i=0; i<5; i++){
    scanf("%d", &num);
    inserir(lista, num);
  }
  exibir(lista);
  remover(lista);
  exibir(lista);

  return 0;
}
