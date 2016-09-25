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

    novo = (No*)malloc(sizeof(No));
    novo->prox = NULL;

    novo->aluno.matricula = matricula;
    strcpy(novo->aluno.nome, nome);

    aux = lista;

    if(lista == NULL){
        lista = novo;
    }else{
        while(aux->prox != NULL && aux->aluno.matricula < novo->aluno.matricula){
            aux = aux->prox;
        }
        if(aux->prox == NULL){
            aux->prox = novo;
        }else{
            novo->prox = aux->prox;
            aux = novo;
        }
    }

    return lista;
}

void exibir(No *lista){
    No *aux;
    aux = lista;
    while(aux != NULL){
        printf("%s", aux->aluno.nome);
        printf("%d\n", aux->aluno.matricula);
        aux = aux->prox;
    }
}

int main(){
    int matricula, i;
    char nome[30];
    No *lista;
    lista = NULL;

    for(i=0; i<3; i++){
        scanf("%s", nome);
        scanf("%d", &matricula);

        lista = inserir(lista, nome, matricula);
    }
    exibir(lista);

    return 0;
}
