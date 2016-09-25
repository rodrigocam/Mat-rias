#include <stdio.h>
#include <stdlib.h>

struct _no {
	int 		info;
	struct _no 	*prox;
};
typedef struct _no no;

int  main () {
	int valor, i;
	no *l, *p;
	
	l = NULL; 
	i=0;
	while (i<7) {
		scanf("%d",&valor);
		p = (struct _no *)  malloc(sizeof(no));
		p->info = valor;
		p->prox = l;
		l=p;
		i++;
	} /* fim-while */
	printf("Valores da lista em ordem inversa de digitacao...\n");
	p=l;
	while (p!=NULL) {

		printf("%d\n", p->info);

		p=p->prox;
	} /* fim-main */
	return(0);
} /* fim-main */
