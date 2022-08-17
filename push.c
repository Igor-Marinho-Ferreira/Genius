#include <stdio.h>
#include <stdlib.h>

struct no{
	char elem;
	struct no *prox;
};

void push(int valor, struct no **t){
	struct no *novo;
	novo = (struct no *) malloc (sizeof(struct no));
	novo->elem = valor;
	if( (*t) == NULL ){
		(*t) = novo;
		(*t)->prox = NULL;
	} else {
		novo->prox = (*t);
		(*t)=novo;
	}
}
