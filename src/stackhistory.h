#ifndef STACKHISTORY_H
#define STACKHISTORY_H

#include "boolean.h"
#include "barang.h"
#include "cart.h"
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

typedef struct { // ieu kummaha carana dapet panjang stack na >:(
    address TOP;
} Stack;

typedef struct {
    int length;
    char** historyStrings;
} StackInfo;

void CreateEmptyStack(Stack *S);
boolean IsStackEmpty(Stack S);
boolean IsStackFull(Stack S);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X);
void PrintStackHistory(Stack S, int N);
void AddtoPembelian(Map *M, Stack *stackhistory);
void writeHistory(FILE *pita, Stack *S);

#endif
