#include <stdio.h>
#include <stdlib.h>

int Fat(int n){
  if(n == 0)
    return 1;
  return n*Fat(n-1);
}

int main(){
  int n;

  scanf("%d", &n);
  printf("%d\n", Fat(n));
}
