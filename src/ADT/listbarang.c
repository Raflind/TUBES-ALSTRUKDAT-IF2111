#include <stdio.h>
#include <stdlib.h>
#include "listbarang.h"

void InitializeListBarang(ListBarang *list) {
    (*list).capacity = 10;
    (*list).neff = 0;
    (*list).buffer = (Barang *)malloc((*list).capacity * sizeof(Barang));
}

int LengthList(ListBarang list) {
    return list.neff;
}

boolean IsListEmpty(ListBarang list) {
    return list.neff == 0;
}

Barang GetBarangAt(ListBarang list, int idx) {
    return list.buffer[idx];
}

void AddBarang(ListBarang *list, Barang item) {
    if ((*list).neff == (*list).capacity) {
        int new_capacity = (*list).capacity * 2;
        Barang *new_buffer = (Barang *)malloc(new_capacity * sizeof(Barang));
        for (int i = 0; i < (*list).neff; i++) {
            new_buffer[i] = (*list).buffer[i];
        }
        free((*list).buffer);
        (*list).buffer = new_buffer;
        (*list).capacity = new_capacity;
    }
    (*list).buffer[(*list).neff] = item;
    (*list).neff++;
}

int FindBarangByName(ListBarang list, char *name) {
    for (int i = 0; i < list.neff; i++) {
        if (string_compare(list.buffer[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void RemoveBarangAt(ListBarang *list, int idx) {
    for (int i = idx; i < (*list).neff - 1; i++) {
        (*list).buffer[i] = (*list).buffer[i + 1];
    }
    (*list).neff--;
}

void DisplayListBarang(ListBarang list) {
    if (IsListEmpty(list)) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko:\n");
        printf("Barang \t\t\t\t | \t Harga\n");
        for (int i = 0; i < LengthList(list); i++) {
            Barang barang = GetBarangAt(list, i);
            printf("- %s \t\t\t\t %d \n", barang.name, barang.price);
        }
    }
}

void FreeListBarang(ListBarang *list) {
    free((*list).buffer);
    (*list).buffer = NULL;
    (*list).capacity = 0;
    (*list).neff = 0;
}