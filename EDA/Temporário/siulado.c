#include <stdio.h>
#include <stdlib.h>

typedef struct _Arv{
  int info;
  int altura;
  struct _Arv *esq;
  struct _Arv *dir;
}Arv;
Arv* aloca(int info){
  Arv *arv;
  arv = (Arv*)malloc(sizeof(Arv));
  arv->info = info;
  arv->altura = 0;
  arv->esq = arv->dir = NULL;
  return arv;
}
int maior(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}

int altura(Arv *a){
  if(a == NULL)
    return -1;
  return a->altura;
}

Arv * rotacaoDireita(Arv *k2){
  Arv *k1;

  k1 = k2->esq;
  k2->esq = k1->dir;
  k1->dir = k2;

  k2->altura = maior(altura(k2->esq), altura(k2->dir))+1;
  k1->altura = maior(altura(k1->esq), k2->altura)+1;

  return k1;
}

Arv * rotacaoEsquerda(Arv *k1){
  Arv *k2;

  k2 = k1->dir;
  k1->dir = k2->esq;
  k2->esq = k1;

  k1->altura = maior(altura(k1->esq), altura(k1->dir))+1;
  k2->altura = maior(altura(k2->dir), k1->altura)+1;

  return k2;
}

Arv * rotacaoEsquerdaDireita(Arv *k3){
  k3->esq = rotacaoEsquerda(k3->esq);
  return rotacaoDireita(k3);
}

Arv * rotacaoDireitaEsquerda(Arv *k3){
  k3->dir = rotacaoDireita(k3->dir);
  return rotacaoEsquerda(k3);
}

Arv *insere(int info, Arv *arv){
  if(arv == NULL){
    arv = aloca(info);
  }else if(info < arv->info){
    arv->esq = insere(info, arv->esq);
    if(altura(arv->esq) - altura(arv->dir) == 2){
      if(info <arv->esq->info){
        arv = rotacaoDireita(arv);
      }else{
        arv = rotacaoEsquerdaDireita(arv);
      }
    }
  }else if(info > arv->info){
    arv->dir = insere(info, arv->dir);
    if(altura(arv->dir) - altura(arv->esq) == 2){
      if(info>arv->dir->info){
        arv = rotacaoEsquerda(arv);
      }else{
        arv = rotacaoDireitaEsquerda(arv);
      }
    }
  }
  arv->altura = maior(altura(arv->esq), altura(arv->dir))+1;
  return arv;
}

exibir(Arv *arv){
  if(arv != NULL){
    exibir(arv->esq);
    printf("%d\n", arv->info);
    exibir(arv->dir);
  }
}

int main(){
  int i, n;
  Arv *arv;

  for(i=0; i<8; i++){
    scanf("%d", &n);
    arv = insere(n, arv);
  }
  exibir(arv);
  return 0;
}
