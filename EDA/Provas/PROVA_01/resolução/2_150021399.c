#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, i,j;
    char *string, *stringReversa;

    scanf("%d", &n);
    j = n;
    string = (char*)malloc(n*sizeof(char));
    stringReversa = (char*)malloc(n*sizeof(char));
    scanf("%s", string);

    for(i=0; i<n; i++){
        stringReversa[i] = string[j-1];
        j--;
    }

    if(strcmp(string, stringReversa) == 0){
        printf("%s E UM PALINDROMO\n", string);
    }else{
        printf("%s NAO E UM PALINDROMO\n", string);
    }

    return 0;
}
