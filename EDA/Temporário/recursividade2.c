#include <stdio.h>
#include <stdlib.h>

int Fib(int n){
  if(n == 0){
    return 0;
  }else if( n == 1){
    return 1;
  }else{
    return Fib(n-2)+Fib(n-1);
  }
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%d\n", Fib(n));
}
