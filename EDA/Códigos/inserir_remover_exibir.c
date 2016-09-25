#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int info;
  struct _No *prox;
}No;

No* inserir(No *lista, int valor){
  No* novo, *aux;
  novo = (No*)malloc(sizeof(No));
  novo->info = valor;
  novo->prox = NULL;
  aux = lista;
  if(lista == NULL){
    lista = novo;
  }else if(lista->info > novo->info){
    novo->prox = lista;
    lista = novo;
  }else{
    while(aux->prox != NULL && aux->prox->info < novo->info){
      aux = aux->prox;
    }
    if(aux->prox == NULL){
      aux->prox = novo;
    }else{
      novo->prox = aux->prox;
      aux->prox = novo;
    }
  }
  printf("\nElemento inserido com sucesso!!\n");
  return lista;
}

No* remover(No *lista, int valor){
  No *aux, *lixo;
  aux = lista;
  if(lista != NULL){
    if(lista->info == valor){
      lixo = lista;
      lista = lista->prox;
      free(lixo);
      printf("\nElemento removido com sucesso!!\n");
    }else{
      while(aux->prox != NULL && valor != aux->prox->info){
        aux = aux->prox;
      }
      if(aux->prox == NULL && aux->info != valor){
        printf("\nO elemento nao esta na lista!\n");
      }else{
        lixo = aux->prox;
        aux->prox = aux->prox->prox;
        free(lixo);
        printf("\nElemento removido com sucesso!!\n");
      }
    }
  }else{
    printf("\nLista vazia!!\n");
  }
  return lista;
}

void exibir(No *lista){
  No *aux;
  aux=lista;
  if(lista != NULL){
    printf("\nElementos: ");
    while(aux != NULL){
      printf("%d ", aux->info);
      aux = aux->prox;
    }
    printf("\n");
  }else{
    printf("\nLista vazia!!\n");
  }
}

int main(){
  int opcao, valor;
  No *lista;
  lista = NULL;

  do{
    printf("\nDigite uma opção: 1 - inserir   2 - remover   3 - exibir   0 - sair __  ");
    scanf("%d", &opcao);
    if(opcao == 1){
      printf("\nDigite o valor a ser inserido: ");
      scanf("%d", &valor);
      lista = inserir(lista, valor);
    }else if(opcao == 2){
      printf("\nDigite o valor a ser removido: ");
      scanf("%d", &valor);
      lista = remover(lista, valor);
    }else if(opcao == 3){
      exibir(lista);
    }
  }while(opcao != 0);
}
