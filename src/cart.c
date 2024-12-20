#include "map.h"
#include "stdio.h"
#include "listbarang.h"
#include "user.h"
#include "mesinkata.h"


void CartAdd(Map M, ListBarang list, char *name, int quantity){
    if(FindBarangByName(list, name) == -1){
        printf("Barang tidak ada di toko!\n");
    }
    else{
        int idx = FindBarangByName(list, name);
        Insert(&M, list.buffer[idx], quantity);
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
            int i = idx;
            while(i < M->Count){
                M->Elements[i] = M->Elements[i+1];
                i++;
            }
            printf("Berhasil mengurangi %d %s dari keranjang belanja!", M->Elements[idx], M->Elements[idx].Barang.name);
        }
        else{
            printf("Berhasil mengurangi %d %s dari keranjang belanja!", M->Elements[idx], M->Elements[idx].Barang.name);
            M->Elements[GetAddress(*M, barang)].Kuantitas -= quantity;
        }
    }
    else{
        printf("Barang tidak ada di keranjang belanja!\n");
    }
}

void DisplayCart(Map M){
    printf("Berikut adalah isi keranjangmu!\n");
    printf("Kuantitas  ");
    printf("Nama           ");
    printf("Total  ");
    int i = 0;
    while(i < M.Count){
        printf("%10d %14s %7d", M.Elements[i].Kuantitas, M.Elements[i].Barang.name, M.Elements[i].total);
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