#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
  struct _No *ant;
}No;

typedef struct _Cabecalho{
  int qtd;
  No *inicio;
  No *fim;
}Cabecalho;

Cabecalho* inserir(Cabecalho *lista, int valor){
  No *novo, *aux;
  novo = (No*)malloc(sizeof(No));
  novo->info = valor;
  novo->prox = NULL;
  novo->ant = NULL;
  aux = lista->inicio;

  if(lista->inicio == NULL){
    lista->inicio = novo;
    lista->fim = novo;
  }else{
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux;
    lista->fim = novo;
  }
  lista->qtd++;
  return lista;
}

No* buscar(Cabecalho *lista, int valor){
  No *aux;
  if(lista->inicio != NULL){
    aux = lista->inicio;
    while(aux->info != valor && aux != NULL){
      aux = aux->prox;
    }
    if(aux->info == valor){
      return aux;
    }
  }
  return;
}

Cabecalho* remover(Cabecalho *lista, int valor){
  No *aux, *lixo;
  aux = buscar(lista, valor);
  if(aux->ant != NULL && aux->prox != NULL){
    lixo = lista->fim;
    aux->info = lista->fim->info;
    lista->fim = lista->fim->ant;
    lista->fim->prox = NULL;
    free(lixo);
  }else if(aux->ant != NULL && aux->prox == NULL){
    lixo = lista->fim;
    lista->fim = lista->fim->ant;
    lista->fim->prox = NULL;
    free(lixo);
  }else if(aux->ant == NULL && aux->prox != NULL){
    lixo = lista->fim;
    lista->inicio->info = lista->fim->info;
    lista->fim = lista->fim->ant;
    lista->fim->prox = NULL;
    free(lixo);
  }else if(aux->ant == NULL && aux->prox == NULL){
    lixo = lista->inicio;
    lista->inicio = NULL;
    lista->fim = NULL;
    free(lixo);
  }
  lista->qtd--;
  return lista;
}

void exibir(Cabecalho *lista){
  No *aux;
  printf("V = [");
  if(lista->inicio != NULL){
    for(aux = lista->inicio; aux != NULL; aux = aux->prox){
      if(aux->prox == NULL){
        printf("%d", aux->info);
      }else{
        printf("%d, ", aux->info);
      }
    }
  }
  printf("]\n");
}

int main(){
  Cabecalho *lista;
  int i, qtdMax, qtdElementos, acoes, processo;
  char opcao;

  lista = (Cabecalho*)malloc(sizeof(Cabecalho));

  scanf("%d %d", &qtdMax, &qtdElementos);

  for(i=0; i<qtdElementos; i++){
    scanf("%d", &processo);
    lista = inserir(lista, processo);
  }

  scanf("%d", &acoes);
  for(i=0; i<acoes; i++){
    scanf("%d %c", &processo, &opcao);
    if(opcao == 'n' && lista->qtd < qtdMax){
      lista = inserir(lista, processo);
    }else if(opcao == 't' && lista->qtd > 0){
      lista = remover(lista, processo);
    }
  }
  exibir(lista);
  return(0);
}
