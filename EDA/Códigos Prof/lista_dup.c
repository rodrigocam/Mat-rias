#include <stdio.h>
#include <stdlib.h>

struct _no {
	int 		info;
	struct _no	*ant;
	struct _no 	*prox;
};
typedef struct _no no;

int  main () {
	int valor, i;
	no *l, *p, *fim;
	
	l = NULL; 
	i=0;
	while (i<7) {
		scanf("%d",&valor);
		p = (struct _no *)  malloc(sizeof(no));
		p->info = valor;
		p->ant  = NULL;
		p->prox = l;
		if (l == NULL)
			fim = p;
		else
			l->ant  = p;
		l=p;
		i++;
	} /* fim-while */
	printf("Valores da lista em ordem inversa de digitacao...\n");
	p=l;
	while (p!=NULL) {

		printf("%d\n", p->info);

		p=p->prox;
	} /* fim-main */
	p=fim;
	printf("Valores da lista em ordem normal de digitacao...\n");
	while (p!=NULL) {

		printf("%d\n", p->info);
		
		p=p->ant;
	} /*fim-main */
	return(0);
} /* fim-main */
