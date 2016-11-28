#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Arv{
  int inf;
  int qtdNo;
  struct _Arv *sae;
  struct _Arv *sad;
}Arv;

Arv * inserir(int num, Arv *arv){
    if(arv == NULL){
      Arv *novo;
      novo = (Arv*)malloc(sizeof(Arv));
      novo->inf = num;
      novo->sae = NULL;
      novo->sad = NULL;
      novo->qtdNo = 0;
      arv = novo;
      arv->qtdNo++;
    }else{
      if(num < arv->inf){
        arv->sae = inserir(num, arv->sae);
      }else{
        arv->sad = inserir(num, arv->sad);
      }
    }
    return arv;
}

int altura(Arv *arv){
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

int main(){
  Arv *arv = NULL;
  int n, num, i, e;
  double aux;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &num);
    arv = inserir(num, arv);
  }

  aux =  n/(pow(2, altura(arv)) - 1);
  e = aux*100;
  printf("Eficiencia de uso: %d%%\n", e);
  return 0;
}
