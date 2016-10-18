#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define MAX 100
#define N 22
#define LIVRE 0
#define PAREDE -1

typedef int t_item;
typedef struct _Pos{
    int x;
    int y;
}Posicao;
typedef struct _Fila{
    int inicio;
    int fim;
    Posicao vet[MAX];
}Fila;
typedef struct _Pilha{
    int topo;
    Posicao vet[MAX];
}Pilha;

//Funções de manipulação de filas
void filaInicializar(Fila *fila){
    fila =(Fila*) malloc(sizeof(Fila));
    fila->inicio = fila->fim = 0;
}

void filaInserir(Fila *fila, Posicao posicao){
    if(fila->fim == 99){
        printf("Fila cheia!\n");
    }else{
        fila->vet[fila->fim] = posicao;
        fila->fim++;
    }
}

void filaRemover(Fila *fila){
    if(fila->fim == fila->inicio){
        printf("Fila vazia!\n");
    }else{
        fila->inicio++;
    }
}

//Funções de manipulação de pilhas
void pilhaInicializar(Pilha *pilha){
    pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = 0;
}

void pilhaInserir(Pilha *pilha, Posicao posicao){
    if(pilha->topo == 99){
        printf("Pilha cheia!\n");
    }else{
        pilha->vet[pilha->topo] = posicao;
        pilha->topo++;
    }
}

//Funções de manipulação do labirinto
void cria(int L[N][N]){
    int i, j;
    for(i=0; i<N; i++){
        L[i][0] = PAREDE;
        L[i][N-1] = PAREDE;
    }
    for(j=0; j<N; j++){
        L[0][j] = PAREDE;
        L[N-1][j] = PAREDE;
    }
    for(i=1; i<N-1; i++)
        for(j=1; j<N-1; j++)
            if(rand()%3==0) L[i][j] = PAREDE;
            else L[i][j] = LIVRE;
    L[1][1] = LIVRE;
    L[N-2][N-2] = LIVRE;
}

void exibe(int L[N][N]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++)
            switch(L[i][j]){
                case LIVRE : putchar(' '); break;
                case PAREDE : putchar('#'); break;
                default : putchar(126);
            }
        printf("\n");
    }
}

void anota(int L[N][N]){
    Fila *fila;
    Posicao posicao, temp;
    int c;
    printf("Entrou");
    filaInicializar(fila);

    //posicao = (Posicao*)malloc(sizeof(Posicao));
    //temp = (Posicao*)malloc(sizeof(Posicao));

    L[1][1] = 1;
    posicao.x = 1;
    posicao.y = 1;

    filaInserir(fila, posicao);


    // while(fila->inicio != fila->fim){
    //   temp = fila->vet[fila->inicio];
    //   c = L[temp.x][temp.y]+1;
    //   if(L[temp.x][temp.y+1] == 0){
    //     temp.x = posicao.x;
    //     temp.y = posicao.y+1;
    //     L[temp.x][temp.y] = c;
    //     filaInserir(fila, temp);
    //   }
    //   if(L[posicao.x][posicao.y-1] == 0){
    //     temp.x = posicao.x;
    //     temp.y = posicao.y-1;
    //     L[temp.x][temp.y] = c;
    //     filaInserir(fila, temp);
    //   }
    //   if(L[posicao.x+1][posicao.y] == 0){
    //     temp.x = posicao.x+1;
    //     temp.y = posicao.y;
    //     L[temp.x][temp.y] = c;
    //     filaInserir(fila, temp);
    //   }
    //   if(L[posicao.x-1][posicao.y] == 0){
    //     temp.x = posicao.x-1;
    //     temp.y = posicao.y;
    //     L[temp.x][temp.y] = c;
    //     filaInserir(fila, temp);
    //   }
    //   filaRemover(fila);
    // }
}

int main(){
    int L[N][N];
    char r;
    srand(time(NULL));
    do{
        system("cls");
        cria(L);
        exibe(L); 
        anota(L);
        //extrai(L);
        exibe(L);
        printf("Continua? (s/n) ");
        scanf("%c%*c", &r);
    }while(toupper(r) != 'N');
    return 0;
}
