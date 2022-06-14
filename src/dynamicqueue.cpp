#include "dynamicqueue.hpp"
using namespace std;

void FFVazia(Fila *f){
	f -> first = (Block*) malloc (sizeof(Block));
	f -> last  = f -> first;
	f -> first -> prox = NULL;
}

void Swap(Block *a, Block *b){
	Item aux;
	aux = a -> data;
	a -> data = b -> data;
	b -> data = aux;
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

    int size = rand() % 15 + 2;
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

void break_apart_in_half(Fila *queue, Fila *first_half_queue, int size) {
    Item aux_item;
    
    for (int i = 0; i < (size / 2); i++) {
        Desenfileira(queue, &aux_item);
        Enfileira(first_half_queue, aux_item);
    }

    cout << endl << endl << "\t\t    - Here is the first half of the list: " << endl << endl << "\t";
    FImprime(first_half_queue);
    cout << endl << endl << "\t\t    - Here is the second half of the list: " << endl << endl << "\t";
    FImprime(queue);
}

void pull_together_two_queues(Fila *queue_first_half, Fila *queue_second_half, Fila *final_queue) {
    Item aux;
    while (!queue_is_empty(queue_first_half)) {
        Desenfileira(queue_first_half, &aux);
        Enfileira(final_queue, aux);
    }
    
    while(!queue_is_empty(queue_second_half)) {
        Desenfileira(queue_second_half, &aux);
        Enfileira(final_queue, aux);
    }

    cout << endl << endl << "\t";
    FImprime(final_queue);
}

void problem_3_a() {
    cout << endl << endl << "-------------------------------------------------------------------------------------";
    cout << endl << endl << "\t\t\t\t    Loading..." << endl << endl;
    Fila queue_1, queue_2;
    
    FFVazia(&queue_1);
    FFVazia(&queue_2);

    int size = define_queue_size();

    fill_queue(&queue_1, size);
    sleep(1);
    fill_queue(&queue_2, size);
   
    cout << endl << "\t\t\t  - This is the first Queue: " << endl << endl << "\t";
    FImprime(&queue_1);

    Fila first_half_queue_1;
    FFVazia(&first_half_queue_1);
    break_apart_in_half(&queue_1, &first_half_queue_1, size);
    
    cout << endl << endl << endl << "\t\t\t  - This is the second Queue: " << endl << endl << "\t";
    FImprime(&queue_2);

    Fila first_half_queue_2;
    FFVazia(&first_half_queue_2);
    break_apart_in_half(&queue_2, &first_half_queue_2, size);

    Fila final_queue_1;
    FFVazia(&final_queue_1);
    cout << endl << endl << endl << "\t\t\t   This is the first half of the" << endl << "\t\t";
    cout << "first Queue with the last half of the second Queue: " << endl << "\t";
    pull_together_two_queues(&first_half_queue_1, &queue_2, &final_queue_1);

    cout << endl << endl << endl << "\t\t\t   This is the first half of the" << endl << "\t\t";
    cout << "second Queue with the last half of the first Queue: " << endl << "\t";
    Fila final_queue_2;
    FFVazia(&final_queue_2);
    pull_together_two_queues(&first_half_queue_2, &queue_1, &final_queue_2);
    cout << endl << endl;
}

void insertNewValue(Fila *f, Item d){
	int aux, opt = -1;

	while(opt != 0){
		if(opt == 1){
			cout << "Valor inserido com sucesso." << endl << endl;
		}

		cout << "Digite 1 se deseja adicionar um novo valor a fila." << endl;
		cout << "Digite 0 se não deseja adicionar mais nenhum valor a fila." << endl << endl;

		cout << "Opção: ";
		cin >> opt;
		cout << endl;

		if(opt == 1){
			cout << "Insira o valor que deseja adicionar a fila: ";
			cin >> aux;

			d.val = aux;
			Enfileira(f, d);

			cout << endl;
		}

		else if(opt == 0){
			cout << "Saindo da função de inserção de novos valores a fila..." << endl << endl;
		}

		else{
			cout << "Opção inválida." << endl << endl;
		}

		system("clear");
	}
}

void equation(Fila *f, Item d){
	Block *aux;
	int sum = 0, cont = 0;
	int average;

	aux = f->first->prox;

	while(aux != NULL){
		sum += aux->data.val;
		cont += 1;

		aux = aux->prox;
	}

	average = sum/cont;

	d.val = average;
	Enfileira(f, d);

	cout << endl << "O resultado da equação de média aritmética aplicada a essa fila, desconsiderando casas decimais, é igual a: " << average << endl << endl;
}

void descendingSort(Fila *Index){
	Block *i, *j;

	i = Index->first->prox;

	while(i != NULL){
		j = i->prox;

		while(j != NULL){
			if(j->data.val > i->data.val){
				Swap(i, j);
			}

			j = j->prox;
		}

		i = i->prox;
	}
}

void equation_c(Fila *Index, Fila *f, Item d){
	Block *aux;
	int sum = 0, cont = 0;
	int average;

	aux = f->first->prox;

	while(aux != NULL){
		sum += aux->data.val;
		cont += 1;

		aux = aux->prox;
	}

	average = sum/cont;

	d.val = average;
	Enfileira(f, d);
	Enfileira(Index, d);

	descendingSort(Index);

	cout << endl << "O resultado da equação de média aritmética aplicada a essa fila, desconsiderando casas decimais, é igual a: " << average << endl << endl;
}