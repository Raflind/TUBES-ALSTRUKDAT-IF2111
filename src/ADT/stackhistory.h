#ifndef STACKHISTORY_H
#define STACKHISTORY_H

#include "boolean.h"
#include "barang.h"
#include "../command/cart.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
    int total;
    int jumlah_barang;
    Cart cart[10];
} Pembelian;

typedef Pembelian infotype;

typedef struct stacknode *address;

typedef struct stacknode {
    infotype info;
    address next;
} stacknode;

typedef struct {
    address TOP;
} Stack;


void CreateEmptyStack(Stack *S);
boolean IsStackEmpty(Stack S);
boolean IsStackFull(Stack S);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X);
void PrintStackHistory(Stack S, int N);
void AddtoPembelian(Map *M, Stack *stackhistory);

#endif
