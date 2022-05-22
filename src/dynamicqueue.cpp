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
		cout << aux -> data.val << "\t";
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

int define_queue_size() {
    srand(time(NULL));

    int size = rand() % 15 + 1;
    return size;
}

void fill_queue(Fila *queue, int size) {
    Item aux;
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        aux.val = rand () % 100 + 1;
        Enfileira(queue, aux);
    }
}

void break_apart_first_half(Fila *queue_1, Fila *first_half_queue_1, int size) {
    Block *aux;
    Item aux_item;
    aux = queue_1 -> first -> prox;
    
    for (int i = 0; i < (size / 2); i++) {
        aux_item.val = aux -> data.val;
        Enfileira(first_half_queue_1, aux_item);
        cout << endl << "TESTING PRINTING UNTIL HALF: " << aux -> data.val;
        aux = aux -> prox;
    }

    cout << endl << endl << "PRINTING QUEUE FILLED UNTIL HALF: " << endl << endl;
    FImprime(first_half_queue_1);
}

void problem_3_a() {
    Fila queue_1, queue_2;
    
    FFVazia(&queue_1);
    FFVazia(&queue_2);

    int size = define_queue_size();

    fill_queue(&queue_1, size);
    sleep(1);
    fill_queue(&queue_2, size);
    FImprime(&queue_1);
    cout << endl;
    FImprime(&queue_2);

    Fila first_half_queue_1;
    FFVazia(&first_half_queue_1);
    
    break_apart_first_half(&queue_1, &first_half_queue_1, size);
    //Fila second_half_queue_2;
    //FFVazia(&half_queue_2);
}