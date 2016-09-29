#include <stdio.h>

int Binom(int n, int k){
  if(n == k || k == 0)
    return 1;
  return Binom(n-1, k-1) + Binom(n-1, k);
}

int main(){
  int n, k;

  scanf("%d %d", &n, &k);
  printf("%d\n", Binom(n, k));
}
