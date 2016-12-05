#include <stdio.h>
#include <stdlib.h>

typedef struct _No{
  int inf;
  int fb;
  struct _No *sae;
  struct _No *sad;
}No;

int altura(No *arv){
  int p1 = 0, p2 = 0;
  if(arv == NULL){
    return 0;
  }
  p1 = altura(arv->sae);
  p2 = altura(arv->sad);
  if(p1 > p2){
    return p1+1;
  }else{
    return p2+1;
  }
}

void calculaFb(No *raiz){
  if(raiz != NULL){
    raiz->fb = (altura(raiz->sae)+1) - (altura(raiz->sad)+1);
    calculaFb(raiz->sae);
    calculaFb(raiz->sad);
  }
}

No * inserir(No *raiz, int num){
  if(raiz == NULL){
    No *novo = (No*)malloc(sizeof(No));
    novo->sae = NULL;
    novo->sad = NULL;
    novo->fb = 1;
    novo->inf = num;
    raiz = novo;
  }else{
    if(num < raiz->inf){
      raiz->sae = inserir(raiz->sae, num);
    }else{
      raiz->sad = inserir(raiz->sad, num);
    }
  }
  calculaFb(raiz);
  return raiz;
}

void exibir(No *raiz){
  if(raiz != NULL){
    exibir(raiz->sae);
    printf("%d\n", raiz->inf);
    exibir(raiz->sad);
  }
}

int verificaBalanceio(No *raiz){
  No *aux;
  if(raiz != NULL){
    if(raiz->fb > 1 || raiz->fb < -1 ){
      return -1;
    }
    verificaBalanceio(raiz->sae);
    verificaBalanceio(raiz->sad);
  }
}

int main(){
  int i, option = 1, n, v = 1;
  No *arv;

  while(option > 0){
    printf("Escolha uma opcao: 1 - inserir  2 - exibir  3 - verificar balanceamento  0 - sair\n");
    scanf("%d", &option);
    switch (option){
      case 1: scanf("%d", &n); arv = inserir(arv, n); break;
      case 2: exibir(arv); break;
      case 3: v += verificaBalanceio(arv);
              if(v==0){
                printf("Arvore nao balanceada!\n");
              }else{
                printf("Arvore balenceada!\n");
              }break;
            }
  }
  return 0;
}
