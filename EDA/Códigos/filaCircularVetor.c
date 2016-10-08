#include <stdio.h>
#include <stdlib.h>

void inserir(int *vet, int *inicio, int *fim, int elemento){
  if(*inicio == *fim){
    vet[*inicio] = elemento;
    *fim+=1;
  }else if(*fim == 8 && *inicio == 0){
    printf("Lista cheia!\n");
  }else if(*fim == 8 && *inicio != 0){
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

void exibir(int *vet, int inicio, int fim){
  int i;
  if(fim < inicio){
    for(i=inicio; i<8; i++){
      printf("%d\n", vet[i]);
    }
    for(i=0; i<fim; i++){
      printf("%d\n", vet[i]);
    }
  }else{
    for(i=inicio; i<fim; i++){
      printf("%d\n", vet[i]);
    }
  }
}

int main(){
  int i, n, vet[4], inicio = 0, fim = 0;

  for(i=0; i<10; i++){
    scanf("%d", &n);
    inserir(vet, &inicio, &fim, n);
  }
  exibir(vet, inicio, fim);
}
