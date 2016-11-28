#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
  struct _No *ant;
}No;

typedef struct _Cabec{
  int qtd;
  No *topo;
}Cabec;

void empilhar(Cabec *lista, int info){
  No *novo;
  novo = (No*)malloc(sizeof(No));
  novo->prox = novo->ant = NULL;
  novo->info = info;

  if(lista->topo == NULL){
    lista->topo = novo;
  }else{
    lista->topo->prox = novo;
    novo->ant = lista->topo;
    lista->topo = novo;
  }
  lista->qtd++;
}

void desempilhar(Cabec *lista){
  No *aux;
  aux = lista->topo;
  lista->topo = lista->topo->ant;
  lista->topo->prox = NULL;
  lista->qtd--;
  free(aux);
}

void exibir(Cabec *lista){
  No *aux;
  int i;
  aux = lista->topo;

  for(i=0; i<lista->qtd; i++){
    printf("%d\n", aux->info);
    aux = aux->ant;
  }
}

int main(){
  int i, num;
  Cabec *lista;
  lista = (Cabec*)malloc(sizeof(Cabec));
  lista->qtd = 0;
  lista->topo = NULL;
  for(i=0; i<5; i++){
    scanf("%d", &num);
    empilhar(lista, num);
  }
  exibir(lista);
  desempilhar(lista);
  exibir(lista);
  return 0;
}
