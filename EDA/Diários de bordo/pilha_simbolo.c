#include <stdio.h>
#include <stdlib.h>

typedef struct _Pilha{
  char vet[105];
  int topo;
}Pilha;

void verifica(Pilha *pilha, char c){
  switch(c){
    case ')': if(pilha->vet[pilha->topo-1] == '('){
                pilha->topo--;
              }else{
                pilha->vet[pilha->topo++] = c;
              }
    break;
    case ']':if(pilha->vet[pilha->topo-1] == '['){
              pilha->topo -= 2;
            }else{
              pilha->vet[pilha->topo++] = c;
            }
    break;
    case '}':if(pilha->vet[pilha->topo-1] == '{'){
              pilha->topo -= 2;
            }else{
              pilha->vet[pilha->topo++] = c;
            }
    break;
    default: pilha->vet[pilha->topo++] = c;
  }
}

char* leString(){
  char *vet, c;
  int i = 0;
  vet = (char*)malloc(105*sizeof(char));
  do{
    scanf("%c", &c);
    if(c != ' ' && c != '\n'){
      vet[i] = c;
      i++;
    }
  }while(c != '\n');
  vet[i] = '\0';
  return vet;
}

int main(){
  char *string;
  int i;
  Pilha *pilha;

  pilha = (Pilha*)malloc(sizeof(Pilha));
  pilha->topo = 0;

  string = leString();


  for(i=0; string[i] != '\0'; i++){
      verifica(pilha, string[i]);
  }

  if(pilha->topo > 0){
    printf("NO\n");
  }else{
    printf("YES\n");
  }
  return 0;
}
