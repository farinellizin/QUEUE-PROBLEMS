#include "dynamicqueue.hpp"
using namespace std;

void FFVazia(Fila *f){
	f -> first = (Block*) malloc (sizeof(Block));
	f -> last  = f -> first;
	f -> first -> prox = NULL;
}

void Enfileira(Fila *f, Item d){
	f -> last -> prox = (Block*) malloc (sizeof(Block));
	f -> last = f -> last -> prox;
	f -> last -> data = d;
	f -> last -> prox = NULL;
}

void Desenfileira(Fila *f, Item *d){
	Block *aux;

	if(f -> first == f -> last || f == NULL || f -> first -> prox == NULL){
		//printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f -> first -> prox;
	f -> first -> prox = aux -> prox;
    if (f -> first -> prox == NULL) {
        f -> last = f -> first;
    }
	d -> val = aux -> data.val;
	free(aux);
}

void FImprime(Fila *f){
	Block *aux;

	aux = f -> first -> prox;
	while(aux != NULL){
		cout << aux -> data.val << " ";
		aux = aux -> prox;
	}
}

bool queue_is_empty(Fila *f) {
    if (f -> first == f -> last || f -> first -> prox == NULL || f == NULL) {
        return true; 
    } else {
        return false;
    }
}