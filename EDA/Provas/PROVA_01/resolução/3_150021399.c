#include <stdio.h>
#include <stdlib.h>

int main(){
    int folha, intervalo, frente, i;

    scanf("%d", &folha);
    scanf("%d", &intervalo);
    for(i=1; i<intervalo; i++){
        if(i==1){
            frente = folha+i;

        }else{
            frente = folha+i+1;
            i++;
        }

    }

    if(frente >= folha+intervalo){
        printf("0\n");
    }else{
        printf("%d\n", frente);
    }

    return 0;
}
