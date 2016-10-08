#include <stdio.h>
#include <stdlib.h>

void inserir(int *vet, int *inicio, int *fim, int elemento){
  if(*inicio == *fim){
    vet[*inicio] = elemento;
    *fim = 1;
  }else if(*fim == 8){
    printf("Fila cheia!\n");
  }else{
    vet[*fim] = elemento;
    *fim+=1;
  }
}

void remover(int *vet, int *inicio, int *fim){
  if(*inicio == *fim){
    printf("Lista vazia!\n");
  }else{
    printf("%d removido!\n", vet[*inicio]);
    *inicio+=1;
  }
}

void exibir(int *vet, int *inicio, int *fim){
  int i;
  for(i=*inicio; i<*fim; i++){
    printf("%d ", vet[i]);
    if(i==*fim-1){
      printf("\n");
    }
  }
}

int main(){
  int i, n, opcao, elemento, vet[8], inicio = 0, fim = 0;

  do{
    printf("Digite uma opcao (1 - inserir elemento, 2 - remover elemento, 3 - exibir comprimento, 4 - exibir fila, 0 - sair): ");
    scanf("%d", &opcao);
    if(opcao == 1){
      scanf("%d", &elemento);
      inserir(vet, &inicio, &fim, elemento);
    }else if(opcao == 2){
      remover(vet, &inicio, &fim);
    }else if(opcao == 3){
      printf("%d\n", fim-inicio);
    }else if(opcao == 4){
      exibir(vet, &inicio, &fim);
    }
  }while(opcao != 0);
}
