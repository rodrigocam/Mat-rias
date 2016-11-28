#include <stdio.h>
#include <stdlib.h>

/*Autor: Rodrigo Oliveira */

typedef struct _Pilha{
  int topo;
  int *vet;
  int peso;
}Pilha;

void inserir(Pilha *pilha, int caixa){
  if(pilha->topo == 0){
    pilha->vet[pilha->topo++] = caixa;
    pilha->peso += caixa;
  }else if(pilha->vet[pilha->topo-1] >= caixa && pilha->topo < 6){
    pilha->vet[pilha->topo++] = caixa;
    pilha->peso += caixa;
  }
}

void remover(Pilha *pilha){
  pilha->topo--;
}

int main(){
  int i, n, caixa;
  Pilha *pilha;
  pilha = (Pilha*)malloc(sizeof(Pilha));
  pilha->topo = 0;
  pilha->peso = 0;
  scanf("%d", &n);
  pilha->vet = (int*) malloc(n*sizeof(int));
  for(i=0; i<n; i++){
    scanf("%d", &caixa);
    inserir(pilha, caixa);
  }
  printf("MASSA EMPILHADA: %d kg\n", pilha->peso);

  return 0;
}
