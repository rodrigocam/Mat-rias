#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Aluno{
  char nome[30];
  int matricula;
}Aluno;

typedef struct _No{
  Aluno aluno;
  struct _No *prox;
}No;

No* inserir(No *lista, char *nome, int matricula){
  No *novo, *aux;

  aux = lista;
  novo = (No*)malloc(sizeof(No));
  novo->prox = NULL;
  strcpy(novo->aluno.nome, nome);
  novo->aluno.matricula = matricula;

  if(lista == NULL){
    lista = novo;
  }else if(lista->aluno.matricula > novo->aluno.matricula){
    novo->prox = lista;
    lista = novo;
  }else{
    while(aux->prox != NULL && aux->prox->aluno.matricula < novo->aluno.matricula){
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

No* remover(No *lista){
  No *aux, *lixo;

  aux = lista;

  lixo = aux->prox;
  aux->prox = aux->prox->prox;

  free(lixo);

}

void exibir(No *lista){
  No *aux;
  aux = lista;
  if(aux == NULL);

  printf("%s %d\n", aux->aluno.nome, aux->aluno.matricula);
  exibir(aux->prox);
}

int main(){
    int matricula, i;
    char nome[30], opcao;
    No *lista;

    lista = NULL;

    // printf("%d\n", scanf("%c %s %d", &opcao, nome, &matricula) getchar());
    // printf("%d\n", scanf("%c %s %d", &opcao, nome, &matricula)getchar);
    // printf("%d\n", scanf("%c %s %d", &opcao, nome, &matricula)getchar);
    while(scanf("%c %s %d", &opcao, nome, &matricula) == 3 && getchar()){

      if(opcao == 'I'){
        lista = inserir(lista, nome, matricula);
       }
       //else{
      //   buscarRemover(lista, matricula);
      // }
      exibir(lista);
    }
}
