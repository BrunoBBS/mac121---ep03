#include "types.h"
#ifndef PILHA_H
#define PILHA_H

int pilhaVazia(pilha p);

pilha *criaPilha(int max);

void realocaPilha(pilha *p);

void empilha(pilha *p, int x);

int desempilha();

void destroiPilha(pilha *p);

#endif
