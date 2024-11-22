#include <stdio.h>
#include "store.h"
#include "listbarang.h"
#include "queue.h"
#include "barang.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
//Program main hanya untuk store (untuk pengujian awal)
int main() {

    ListBarang store_list;
    Queue requests;

    InitializeListBarang(&store_list);
    CreateQueue(&requests);

    // Menambahkan beberapa barang awal ke store_list 
    Barang item1, item2, item3;

    string_copy(item1.name, "Baby Oil");
    item1.price = 5000;
    AddBarang(&store_list, item1);

    string_copy(item2.name, "Jean Paul Gaultier");
    item2.price = 3000;
    AddBarang(&store_list, item2);

    string_copy(item3.name, "BIG PP");
    item3.price = 2000;
    AddBarang(&store_list, item3);

    store_menu(&store_list, &requests);
    FreeListBarang(&store_list);

    return 0;
}


//gcc main-store.c barang.c mesinkarakter.c mesinkata.c queue.c listbarang.c store.c -o main
