#include <stdio.h>
#include "boolean.h"
#include "map.h"
#include "barang.h"
#include "mesinkata.h"

void CreateEmpty(Map *M){
    M->Count = Nil;
}

boolean IsEmpty(Map M){
    return M.Count == Nil;
}

boolean IsFull(Map M){
    return M.Count == MaxElCart;
}

int Value(Map M, Barang barang){
    if(IsMember(M, barang)){
        int i = 0;
        while(i < M.Count){
            if(string_compare(M.Elements[i].Barang.name, barang.name) == 0){
                return M.Elements[i].total;
            }
            i++;
        }
    }
    return Undefined;
}

int Quantity(Map M, Barang barang){
    if(IsMember(M, barang)){
        int i = 0;
        while(i < M.Count){
            if(string_compare(M.Elements[i].Barang.name, barang.name) == 0){
                return M.Elements[i].Kuantitas;
            }
            i++;
        }
    return Undefined;
    }
}

int GetAddress(Map M, Barang barang){
    if(IsMember(M, barang)){
        int i = 0;
        while(i < M.Count){
            if(string_compare(M.Elements[i].Barang.name, barang.name) == 0){
                return M.Count - 1;
            }
            i++;
        }
    return Undefined;
    }
}

void Insert(Map *M, Barang barang, int kuantitas){
    if(!IsMember(*M, barang)){
        M->Elements[M->Count].Barang = barang;
        M->Elements[M->Count].Kuantitas = kuantitas;
        M->Elements[M->Count].total = barang.price * kuantitas;
        M->Count++;
    }
    else{
        int idx = GetAddress(*M, barang);
        M->Elements[idx].Kuantitas += kuantitas;
        M->Elements[idx].total = barang.price * M->Elements[idx].Kuantitas;
    }
}

void Delete(Map *M, Barang barang, int quantity){
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
            printf("Berhasil mengurangi %d %s dari keranjang belanja!", quantity, M->Elements[idx].Barang.name);
        }
        else{
            printf("Berhasil mengurangi %d %s dari keranjang belanja!", quantity, M->Elements[idx].Barang.name);
            M->Elements[GetAddress(*M, barang)].Kuantitas -= quantity;
        }
    }
    else{
        printf("Barang tidak ada di keranjang belanja!\n");
    }
}

boolean IsMember(Map M, Barang barang){
    int i = 0;
    while(i < M.Count){
        if(string_compare(M.Elements[i].Barang.name, barang.name) == 0){
            return true;
        }
        i++;
    }
    return false;
}