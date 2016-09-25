#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  float info;
  struct _No *prox;
}No;

No* inserirOrdenado(No *lista, float valor){
  No *novo, *aux;
  novo = (No*)malloc(sizeof(No));
  novo->info = valor;
  novo->prox = NULL;
  aux = lista;
  if(lista == NULL){
    lista = novo;
  }else if(novo->info > lista->info){
    novo->prox = lista;
    lista = novo;
  }else{
    while(aux->prox != NULL && novo->info <  aux->prox->info){
      aux = aux->prox;
    }
    if(aux->prox == NULL){
      aux->prox = novo;
    }else{
      novo->prox = aux->prox;
      aux->prox = novo;
    }

  }
  return lista;
}

void exibir(No *lista){
  No *aux;
  aux=lista;
  while(aux != NULL){
    printf("%.2f ", aux->info);
    aux = aux->prox;
  }
}

int main(){
  No *lista;
  int i;
  int n;
  float m;
  float h;
  float imc;
  lista = NULL;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%f %f", &m, &h);
    imc = m/(h*h);
    lista = inserirOrdenado(lista, imc);
  }
  exibir(lista);
  return 0;
}
