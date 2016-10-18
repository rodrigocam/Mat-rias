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
            break;
            case '+' : if(pilha[topo-1] == '*' || pilha[topo-1] == '/'){
                            posfix[j++] = pilha[topo--];
                            pilha[topo++] = infix[i];
                        }
            break;
            case '-' : if(pilha[topo-1] == '*' || pilha[topo-1] == '/'){
                            posfix[j++] = pilha[topo--];
                            pilha[topo++] = infix[i];
                        }
            break;
            case '*' : posfix[j++] = infix[i];
            break;
            case '/' : posfix[j++] = infix[i];
            break;

            default : posfix[j++] =  infix[i];
        }
    }
    return posfix;
}

int main(){
    char s[20], *posfix;

    scanf("%s", s);
    posfix = infixToPosFix(s);
    printf("%s", posfix);
    return 0;
}
