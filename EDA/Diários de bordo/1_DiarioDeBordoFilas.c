/* ---- Autores ----
Rodrigo Oliveira Campos - 15/0021399
Josué Nascimento - 15/0038933 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int ini;
    int fim;
    int vetor [7];
}Fila;

typedef struct no{
  int info;
  struct no * prox;
  struct no * ant;
}No;

typedef struct{
  No* inicio;
  No* fim;
  int quantidade;
}Cabecalho;

Cabecalho * filaListaSimplesInit(){
    Cabecalho * cabecalho =  (Cabecalho*)malloc(sizeof(Cabecalho));
    cabecalho->fim =NULL;
    cabecalho->inicio= NULL;
    cabecalho->quantidade=0;
    return cabecalho;
}

Cabecalho* filaListaSimplesInserir(Cabecalho* cabecalho , int num){
    No* novo = (No*)malloc(sizeof(No));
    novo->ant=NULL;
    novo->prox=NULL;
    novo->info=num;
    if(cabecalho->quantidade==0){
        cabecalho->fim=novo;
        cabecalho->inicio=novo;
    }else{
        novo->ant=cabecalho->fim;
        cabecalho->fim->prox=novo;
        cabecalho->fim=novo;
    }
    cabecalho->quantidade++;
    return cabecalho;
}

Cabecalho * filaListaSimplesRemover(Cabecalho* cabecalho){
    No* aux = cabecalho->inicio;
    cabecalho->inicio=aux->prox;
    cabecalho->inicio->ant =NULL;
    free(aux);
    return cabecalho;
}

void filaListaSimplesExibir(Cabecalho*  cabecalho){
    No* aux = cabecalho->inicio;
    while(aux!=NULL){
        printf("%d\n" , aux->info);
        aux=aux->prox;
    }
}

Cabecalho * filaListaCircularInserir(Cabecalho * cab, int num){
    No * novo = (No*) malloc(sizeof(No));
    novo->ant= NULL;
    novo->prox=NULL;
    novo->info=num;
    if(cab->quantidade==0){
        cab->inicio=novo;
        cab->fim=novo;
        novo->prox=cab->inicio;
        novo->ant=cab->fim;
    }else{
        novo->ant=cab->fim;
        cab->fim->prox=novo;
        cab->fim=novo;
        cab->fim->prox=cab->inicio;
    }
    cab->quantidade++;
    return cab;
}

Cabecalho * filaListaCircularRemover(Cabecalho * cab){
  No *aux = cab->inicio;
  cab->inicio = aux->prox;
  aux->ant=NULL;
  cab->fim->prox=cab->inicio;
  cab->inicio->ant=cab->fim;
  aux->prox=NULL;
  free(aux);
  return cab;
}

void filaListaCircularExibir(Cabecalho *cab){
No * aux =cab->inicio;
do{
    printf("%d\n" , aux->info);
    aux = aux->prox;

}while(aux!=cab->fim);
    if(aux == cab->fim){
        printf("%d\n" , cab->fim->info);
    }
}


Fila * filaVetorInicializa(){
    Fila * fila = malloc(sizeof(Fila));
    fila->fim=0;
    fila->ini=0;
    return fila;
}

Fila * filaVetorInserir(Fila * fila , int num){

    if(fila->fim==7){
        printf("Fila cheia!\n");
    }else{
      fila->vetor[fila->fim]= num;
      fila->fim++;

    }
    return fila;
}
Fila * filaVetorRemover(Fila * fila){
    if(fila->ini==fila->fim){
        printf("Fila vazia\n");
    }else{
    fila->ini++;
    }
    return fila;
}
void filaVetorExibir(Fila * fila ){
    int i;
    if(fila->ini == fila->fim){
      printf("Lista vazia!\n");
    }else{
      for(i = fila->ini ; i<fila->fim ; i++){
          printf("%d\n" , fila->vetor[i]);
      }
    }
}

Fila* filaVetorCircularInserir(Fila * fila, int num){
    if(fila->fim == 7 && fila->ini == 0){
        printf("Fila cheia!\n");
    }else{
        if(fila->ini != 0 && fila->fim == 7){
            fila->vetor[fila->fim] = num;
            fila->fim = 0;
        }else{
            fila->vetor[fila->fim] = num;
            fila->fim++;
        }
    }
}

Fila * filaVetorCircularRemover(Fila * fila){
    if(fila->ini == fila->fim){
        printf("Lista vazia!\n");
    }else{
        if(fila->ini == 7){
            fila->ini = 0;
        }else{
            fila->ini++;
        }
    }
}

void filaVetorCircularExibir(Fila * fila ){
    int i;
    if(fila->fim < fila->ini){
        for(i=fila->ini; i<8; i++){
            printf("%d\n", fila->vetor[i]);
        }
        for(i=0; i<fila->fim; i++){
            printf("%d\n", fila->vetor[i]);
        }
    }else{
        for(i = fila->ini ; i<fila->fim ; i++){
            printf("%d\n" , fila->vetor[i]);
        }
    }
}

int main(){
    int i, numero;
    char opcao, estrutura;
    Fila *fila;
    Cabecalho *cab;

    cab = filaListaSimplesInit();

    fila = filaVetorInicializa();

    do{
        //Opcao - Letra "I" para inserir, "R" remover, "P" exibir
        //Estrutura - Letra "A" para usar vetor, "B" vetor circular, "C" lista simples, "D" lista circular
        scanf("%c %c", &opcao, &estrutura);
        if(opcao == 'I' && estrutura == 'A'){
            scanf("%d", &numero);
            fila = filaVetorInserir(fila, numero);
        }else if(opcao == 'R' && estrutura == 'A'){
            fila = filaVetorRemover(fila);
        }else if(opcao == 'P' && estrutura == 'A'){
            filaVetorExibir(fila);
        }else if(opcao == 'I' && estrutura == 'B'){
            scanf("%d", &numero);
            filaVetorCircularInserir(fila, numero);
        }else if(opcao == 'R' && estrutura == 'B'){
            filaVetorCircularRemover(fila);
        }else if(opcao == 'P' && estrutura == 'B'){
            filaVetorCircularExibir(fila);
        }else if(opcao == 'I' && estrutura == 'C'){
            scanf("%d", &numero);
            cab = filaListaSimplesInserir(cab, numero);
        }else if(opcao == 'R' && estrutura == 'C'){
            cab = filaListaSimplesRemover(cab);
        }else if(opcao == 'P' && estrutura == 'C'){
            filaListaSimplesExibir(cab);
        }else if(opcao == 'I' && estrutura == 'D'){
            scanf("%d", &numero);
            cab = filaListaCircularInserir(cab, numero);
        }else if(opcao == 'R' && estrutura == 'D'){
            cab = filaListaCircularRemover(cab);
        }else if(opcao == 'P' && estrutura == 'D'){
            filaListaCircularExibir(cab);
        }
        getchar();
    }while(opcao != 'F');


    return 0;
}
