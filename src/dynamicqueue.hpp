#ifndef DYNAMICQUEUE_HPP
#define DYNAMICQUEUE_HPP
#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
	int val;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void FImprime(Fila *f);
bool queue_is_empty(Fila *f);

void insertNewValue(Fila *f, Item d);
void equation(Fila *f, Item d);

void equation_c(Fila *Index, Fila *f, Item d); 

void problem_3_a();
int define_queue_size();
void fill_queue(Fila *queue, int size);
void break_apart_in_half(Fila *queue, Fila *first_half_queue, int size);
void pull_together_two_queues(Fila *queue_first_half, Fila *queue_second_half, Fila *final_queue);


#endif
