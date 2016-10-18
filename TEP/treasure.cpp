#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

typedef struct _Point{
  double x;
  double y;
}Point;

using namespace std;

int main(){
    Point point;
    double x = 0, y = 0;
    string input;

    while(cin >> input && input.compare("END") != 0){
      for(int i=0; i<5; i++){
        if(input.c_str()[i] != ','){
          printf("%c\n", input.c_str()[i]);
          i++;
        }else{
          break;
        }
      }
    }
}
