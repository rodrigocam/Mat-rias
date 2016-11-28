#include <stdio.h>
#include <stdlib.h>

typedef struct _Arv{
  int inf;
  struct _Arv *sae;
  struct _Arv *sad;
}Arv;

Arv* inserir(Arv *arv, int num){
  if(arv == NULL){
    Arv *novo;
    novo = (Arv*)malloc(sizeof(Arv));
    novo->inf = num;
    novo->sae = NULL;
    novo->sad = NULL;
    arv = novo;
  }else{
      if(num < arv->inf){
        arv->sae = inserir(arv->sae, num);
      }else{
        arv->sad = inserir(arv->sad, num);
      }
  }
  return arv;
}

void pre_ordem(Arv *arv){
  if(arv != NULL){
    printf("%d ", arv->inf);
    pre_ordem(arv->sae);
    pre_ordem(arv->sad);
  }
}

void em_ordem(Arv *arv){
  if(arv != NULL){
    em_ordem(arv->sae);
    printf("%d ", arv->inf);
    em_ordem(arv->sad);
  }
}

void pos_ordem(Arv *arv){
  if(arv != NULL){
    pos_ordem(arv->sae);
    pos_ordem(arv->sad);
    printf("%d ", arv->inf);
  }
}

int profundidade(Arv *arv){
  int p1 = 0, p2 = 0;
  if(arv == NULL){
    return 0;
  }
  p1 = profundidade(arv->sae);
  p2 = profundidade(arv->sad);
  if(p1 > p2){
    return p1+1;
  }else{
    return p2+1;
  }
}

int contar_folhas(Arv *arv){
  int f1 = 0, f2 = 0;
  if(arv == NULL){
    return 0;
  }
  f1 = contar_folhas(arv->sae);
  f2 = contar_folhas(arv->sad);

  if(f1 == 0 && f2 == 0){
    return 1;
  }else{
    return f1+f2;
  }
}

void mostrar_folhas(Arv *arv){
  if(arv != NULL && arv->sae == NULL && arv->sad == NULL){
    printf("%d ", arv->inf);
  }else if(arv != NULL){
    mostrar_folhas(arv->sae);
    mostrar_folhas(arv->sad);
  }
}

int main(){
  Arv *arv;
  int i, n, num;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &num);
    arv = inserir(arv, num);
  }
  /* Primeira questao */ printf("%d\n", profundidade(arv));
  /* Segunda questao  */ printf("%d\n", contar_folhas(arv));
  /* Terceira questao */ mostrar_folhas(arv); printf("\n");
  /* Quarta questao   */ pre_ordem(arv); printf("\n");
  /* Quinta questao   */ em_ordem(arv); printf("\n");
  /* Sexta questao    */ pos_ordem(arv); printf("\n");
  return 0;
}
