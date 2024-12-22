#include "stackhistory.h"
#include <stdio.h>
#include <string.h>

// Definisi boolean.h
#ifndef BOOLEAN_H
#define BOOLEAN_H

typedef enum { false, true } boolean;

#endif

// Definisi barang.h
#ifndef BARANG_H
#define BARANG_H

#define MAX_LEN 50

typedef struct {
    char name[MAX_LEN];
} Barang;

#endif

int TotalHarga(Map M){
    int i = 0;
    int total = 0;  
    while(i < M.Count){
        total += M.Elements[i].total;
        i++;
    }
    return total;
}

int main(){
    // Inisialisasi stack
    Stack S;
    CreateEmptyStack(&S);

    // Membuat beberapa Barang
    Barang b1, b2, b3;
    strcpy(b1.name, "Laptop");
    strcpy(b2.name, "Mouse");
    strcpy(b3.name, "Keyboard");

    // Membuat beberapa Cart
    Cart c1, c2, c3;
    c1.Barang = b1;
    c1.Kuantitas = 1;
    c1.total = 15000000; // Misalnya harga Laptop

    c2.Barang = b2;
    c2.Kuantitas = 2;
    c2.total = 200000; // Misalnya harga Mouse

    c3.Barang = b3;
    c3.Kuantitas = 1;
    c3.total = 750000; // Misalnya harga Keyboard

    // Membuat Pembelian pertama
    Pembelian p1;
    p1.id = 1;
    p1.total = c1.total + c2.total;
    p1.jumlah_barang = 2;
    p1.cart[0] = c1;
    p1.cart[1] = c2;

    // Membuat Pembelian kedua
    Pembelian p2;
    p2.id = 2;
    p2.total = c3.total;
    p2.jumlah_barang = 1;
    p2.cart[0] = c3;

    // Push Pembelian ke Stack
    Push(&S, p1);
    Push(&S, p2);

    // Mencetak Riwayat Pembelian
    printf("=== Riwayat Pembelian Awal ===\n");
    PrintStackHistory(S, 10);

    // Menghapus (Pop) satu Pembelian
    Pembelian popped;
    Pop(&S, &popped);
    printf("=== Setelah Pop ===\n");
    printf("Pembelian yang dihapus: ID %d, Total %d\n\n", popped.id, popped.total);

    // Mencetak Riwayat Pembelian setelah Pop
    printf("=== Riwayat Pembelian Setelah Pop ===\n");
    PrintStackHistory(S, 10);

    // Menguji apakah Stack kosong
    if(IsStackEmpty(S)){
        printf("Stack sekarang kosong.\n");
    }
    else{
        printf("Stack sekarang tidak kosong.\n");
    }

    // Menghapus semua Pembelian
    Pop(&S, &popped);
    printf("=== Setelah Pop Kedua ===\n");
    printf("Pembelian yang dihapus: ID %d, Total %d\n\n", popped.id, popped.total);

    // Mencetak Riwayat Pembelian setelah semua Pop
    printf("=== Riwayat Pembelian Setelah Semua Pop ===\n");
    PrintStackHistory(S, 10);

    // Menguji apakah Stack kosong setelah semua Pop
    if(IsStackEmpty(S)){
        printf("Stack sekarang kosong.\n");
    }
    else{
        printf("Stack sekarang tidak kosong.\n");
    }

    return 0;
}

// gcc stackmain.c stackhistory.c -o stack_test
