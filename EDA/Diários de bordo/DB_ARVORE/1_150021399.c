#include <stdio.h>
#include <stdlib.h>

typedef struct _Arv{
  int inf;
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
    arv = novo;
  }else{
    if(num < arv->inf){
      arv->sae = inserir(num, arv->sae);
    }else{
      arv->sad = inserir(num, arv->sad);
    }
  }
  return arv;
}

int achar(int num, Arv *arv){
  int n = 1;

  if(arv == NULL){
    printf("VALOR NAO LOCALIZADO NA ARVORE\n");
    return -200;
  }else{
    if(arv->inf == num){
      return n;
    }else if(num < arv->inf){
      n += achar(num, arv->sae);
    }else if(num > arv->inf){
      n += achar(num, arv->sad);
    }
  }
  return n;
}

void exibir(Arv *arv){
  if(arv != NULL){
    printf("%d\n", arv->inf);
    exibir(arv->sae);
    exibir(arv->sad);
  }
}

int main(){
  int p, n, i, num, aux;
  Arv *arv = NULL;

  scanf("%d", &p);
  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &num);
    arv = inserir(num, arv);
  }
  aux = achar(p, arv);
  if(aux > 0){
    printf("%d\n", aux);
  }
  /*printf("%d\n", achar(p, arv));
  //printf("WTF %d\n", arv->sae->inf);
  exibir(arv);*/
  return 0;
}
