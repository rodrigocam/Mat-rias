#include <stdio.h>
#include <stdlib.h>

typedef struct _Arv{
  int inf;
  struct _Arv *sae;
  struct _Arv *sad;
}Arv;

Arv * inserir(Arv *arv, int num){
  if(arv == NULL){
    Arv *novo = (Arv*)malloc(sizeof(Arv));
    novo->sae = NULL;
    novo->sad = NULL;
    novo->inf = num;
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

Arv * auxRemover(Arv *atual){
  Arv *arv1, *arv2;
  if(atual->sae == NULL){
    arv2 = atual->sad;
    free(atual);
    return arv2;
  }
  arv1 = atual;
  arv2 = atual->sae;

  while(arv2->sad != NULL){
    arv1 = arv2;
    arv2 = arv2->sad;
  }

  if(arv1 != atual){
    arv1->sad = arv2->sae;
    arv2->sae = atual->sae;
  }

  arv2->sad = atual->sad;
  free(atual);
  return arv2;
}

Arv* remover(Arv *arv, int num){
  if(arv == NULL) return 0;

  Arv *ant = NULL;
  Arv *atual = arv;

  while(atual != NULL){
    if(num == atual->inf){
      if(atual == arv){
        arv = auxRemover(atual);
        return arv;
      }else{
        if(ant->sad == atual){
          ant->sad = auxRemover(atual);
        }else{
          ant->sae = auxRemover(atual);
        }
      }
      return NULL;
    }
    ant = atual;
    if(num > atual->inf){
      atual = atual->sad;
    }else{
      atual = atual->sae;
    }
  }
}

void exibir(Arv *arv){
  if(arv != NULL){
    printf("%d\n", arv->inf);
    exibir(arv->sae);
    exibir(arv->sad);
  }
}

int main(){
  int n, i, status;
  Arv *arv;

  for(i=0; i<10; i++){
    scanf("%d", &n);
    arv = inserir(arv, n);
  }
  exibir(arv);
  scanf("%d", &n);
  arv = remover(arv, n);
  exibir(arv);

  return 0;
}
