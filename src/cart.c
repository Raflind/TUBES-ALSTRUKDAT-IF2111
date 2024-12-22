#include "map.h"
#include <stdio.h>
#include "listbarang.h"
#include "mesinkata.h"
#include "cart.h"

void CartAdd(Map *M, ListBarang list, char *name, int quantity){
    if(FindBarangByName(list, name) == -1){
        printf("Barang tidak ada di toko!\n");
    }
    else{
        int idx = FindBarangByName(list, name);
        Insert(M, list.buffer[idx], quantity);
        printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", quantity, name);
    }
}

void CartRemove(Map *M, ListBarang list, char *name, int quantity){
    int i = FindBarangByName(list, name);
    Barang barang = GetBarangAt(list, i);
    if(IsMember(*M, barang)){
        int idx = GetAddress(*M, barang);
        if(Quantity(*M, barang) < quantity){
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", M->Elements[idx].Kuantitas, M->Elements[idx].Barang.name);
        }
        else if(Quantity(*M, barang) == quantity){
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, M->Elements[idx].Barang.name);
            Delete(M, barang);
            
        }
        else{
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, M->Elements[idx].Barang.name);
            M->Elements[GetAddress(*M, barang)].Kuantitas -= quantity;
            M->Elements[GetAddress(*M, barang)].total -= barang.price * quantity;
        }
    }
    else{
        printf("Barang tidak ada di keranjang belanja!\n");
    }
}

int TotalHarga(Map M){
    int i = 0;
    int total = 0;  
    while(i < M.Count){
        total += M.Elements[i].total;
        i++;
    }
    return total;
}