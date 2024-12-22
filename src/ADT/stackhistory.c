#include "stackhistory.h"

#include <stdio.h>

void CreateEmptyStack(Stack *S){
    Top(*S) = Nill;
}

boolean IsStackEmpty(Stack S){
    return (Top(S) == Nill);
}

boolean IsStackFull(Stack S){
    return (Top(S) == MaxEl - 1);
}

void Push(Stack * S, infotype X){
    Top(*S)++;
    S->T[Top(*S)] = X;
}

void Pop(Stack * S, infotype* X){
    *X = S->T[Top(*S)];
    Top(*S)--;
}

int stackLength(Stack S){
    return Top(S);
}

void PrintStackHistory(Stack S, int N){
    if (IsStackEmpty(S)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    int total_pembelian = Top(S) + 1;
    int jumlah_dicetak;

    if (N > total_pembelian) {
        jumlah_dicetak = total_pembelian;
    } 

    else {
        jumlah_dicetak = N;
    }

    printf("Riwayat Pembelian : \n");
    for(int i = Top(S); i >= Top(S) - jumlah_dicetak + 1; i--){
        if(i < 0) break;
        Pembelian p = S.T[i];
        printf("Pembelian %d - Total %d\n", p.id, p.total);
        printf("Kuantitas\tNama\tTotal\n");
        for(int j = 0; j < p.jumlah_barang; j++) {
            Cart cart = p.cart[j];
            printf("%d\t\t%s\t%d\n", cart.Kuantitas, cart.Barang.name, cart.total);
        }
        printf("\n");
    }
}

void AddtoPembelian(Map *M, Stack *stackhistory) {
    Pembelian purchase;
    purchase.jumlah_barang = 0;
    purchase.total = 0;
    for(int i = 0; i < M->Count; i++){
        purchase.cart[i] = M->Elements[i];
    }
    purchase.jumlah_barang = M->Count;
    purchase.total = TotalHarga(*M);
    if(IsStackEmpty(*stackhistory)) {
        purchase.id = 1;
    } else {
        purchase.id = Top(*stackhistory) + 2;
    }
    Push(stackhistory, purchase);
}