#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Pilha{
    int topo;
    char vet[20];
}Pilha;

Pilha* pilhaInicializar(Pilha *pilha){
  pilha = (Pilha*)malloc(sizeof(Pilha));
  pilha->topo = 0;
  return pilha;
}

//void pilhaInserir(Pilha *pilha, char c){
  //pilha->vet[pilha->topo] = c;
  //pilha->topo++;
//}

//void pilhaRemover(Pilha *pilha){
  //pilha->topo--;
//  }

int main(void){
  char s[20];
  int i;
  Pilha *pilha;
  //s = (char*)malloc(sizeof(char)*20);
  pilha = pilhaInicializar(pilha);
  //printf("a");
  scanf("%s", s);
  printf("b");
  for(i=0; i<strlen(s); i++){
    printf("c");
    switch(s[i]){
      case ')' : if (pilha->topo != 0 && pilha->vet[pilha->topo-1] == '('){
        --pilha->topo;
      }else{
        return 0;
      }
      case ']' : if(pilha->topo != 0 && pilha->vet[pilha->topo-1] == '['){
        --pilha->topo;
      }else{
        return 0;
      }
      case '}' : if(pilha->topo != 0 && pilha->vet[pilha->topo-1] == '{'){
        --pilha->topo;
      }else{
        return 0;
      }
      default : pilha->vet[pilha->topo++] = s[i];
    }
  }
  if(pilha->topo == 0){
    printf("String correta!\n");
  }else{
    printf("String incorreta!\n");
  }
  return 0;
}
