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


#endif