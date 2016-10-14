#include <stdio.h>
#include <stdlib.h>

void inserir(int *vet, int *inicio, int *fim, int elemento){
  if(*inicio == *fim){
    vet[*inicio] = elemento;
    *fim+=1;
  }else if(*fim == 7 && *inicio == 0){
    printf("Lista cheia!\n");
  }else if(*fim == 7 && *inicio != 0){
      vet[*fim] = elemento;
      *fim = 0;
  }else{
    if(*fim+1 != *inicio){
      vet[*fim] = elemento;
      *fim+=1;
    }else{
      printf("Lista cheia!\n");
    }
  }
}

void remover(int *vet, int *inicio, int *fim){
  if(*inicio == *fim){
    printf("Lista vazia!\n");
  }else if(*inicio < 7){
    printf("%d removido!\n", vet[*inicio]);
    *inicio+=1;
  }else if(*inicio == 7){
    printf("%d removido!\n", vet[*inicio]);
    *inicio=0;
  }
}

void exibir(int *vet, int inicio, int fim){
  int i;
  if(fim < inicio){
    for(i=inicio; i<8; i++){
      printf("%d\n", vet[i]);
    }
    for(i=0; i<fim; i++){
      printf("%d\n", vet[i]);
    }
  }else if(inicio == fim){
    printf("Lista vazia!\n");
  }else{
    for(i=inicio; i<fim; i++){
      printf("%d\n", vet[i]);
    }
  }
}

int main(){
  int i, opcao, elemento, vet[4], inicio = 0, fim = 0;

  do{
    printf("Digite uma opcao (1 - inserir elemento, 2 - remover elemento, 3 - exibir comprimento, 4 - exibir fila, 0 - sair): ");
    scanf("%d", &opcao);
    if(opcao == 1){
      scanf("%d", &elemento);
      inserir(vet, &inicio, &fim, elemento);
    }else if(opcao == 2){
      remover(vet, &inicio, &fim);
    }else if(opcao == 3){
      if(fim < inicio){
        printf("%d\n", 8-inicio+fim-1);
      }else{
        printf("%d\n", fim-inicio);
      }
    }else if(opcao == 4){
      exibir(vet, inicio, fim);
    }
  }while(opcao != 0);
}
