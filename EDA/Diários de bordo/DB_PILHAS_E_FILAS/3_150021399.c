#include <stdio.h>
#include <stdlib.h>

char* infixToPosFix(char infix[]){
    char pilha[20], *posfix;
    int i, j, topo = 0;
    posfix = (char*) malloc(20*sizeof(char));
    for(i=0,j=0; infix[i] != '\0'; i++){
        switch(infix[i]){
            case '(' : pilha[topo++] = infix[i]; break;
            case ')' : while(pilha[topo-1] != '('){
                            posfix[j++] = pilha[--topo];
                        }
                         --topo;
            break;
            case '+' : if(pilha[topo-1] == '*' || pilha[topo-1] == '/'){
                            posfix[j++] = pilha[--topo];
                            pilha[topo++] = infix[i];
                        }else{
                          pilha[topo++] = infix[i];
                        }
            break;
            case '-' : if(pilha[topo-1] == '*' || pilha[topo-1] == '/'){
                            posfix[j++] = pilha[--topo];
                            pilha[topo++] = infix[i];
                        }else{
                          pilha[topo++] = infix[i];
                        }
            break;
            case '*' : if(pilha[topo-1] == '*' || pilha[topo-1] == '/'){
                          posfix[j++] = pilha[--topo];
                          pilha[topo++] = infix[i];
                        }else{
                          pilha[topo++] = infix[i];
                        }
            break;
            case '/' : if(pilha[topo-1] == '*' || pilha[topo-1] == '/'){
                          posfix[j++] = pilha[--topo];
                          pilha[topo++] = infix[i];
                        }else{
                          pilha[topo++] = infix[i];
                        }
            break;

            default : posfix[j++] =  infix[i];
        }
    }
    while(topo > 0){
      posfix[j++] = pilha[--topo];
    }
    return posfix;
}

int calculate(char *posfix){
  int topo = 0, i, aux;
  int pilha[20];
  for(i = 0; posfix[i] != '\0'; i++){
    switch(posfix[i]){
      case '*' : aux = (pilha[topo-2]) * (pilha[topo-1]);
                 topo -= 2;
                 pilha[topo++] = aux; break;

      case '/' : aux = (pilha[topo-2]) / (pilha[topo-1]);
                 topo -= 2;
                 pilha[topo++] = aux; break;

      case '+' : aux = (pilha[topo-2]) + (pilha[topo-1]);
                 topo -= 2;
                 pilha[topo++] = aux; break;

      case '-' : aux = (pilha[topo-2]) - (pilha[topo-1]);
                 topo -= 2;
                 pilha[topo++] = aux; break;

      default: pilha[topo++] = posfix[i] - 48;
    }
  }
  return aux;
}

int main(){
    char s[20], *posfix;

    scanf("%s", s);
    posfix = infixToPosFix(s);
    printf("%d", calculate(posfix));

    return 0;
}
