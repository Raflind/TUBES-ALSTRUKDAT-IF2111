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

void Delete(Map *M, Barang barang){
    if(IsMember(*M, barang)){
        int i = GetAddress(*M, barang);
        while(i < (*M).Count){
            M->Elements[i].Barang = M->Elements[i+1].Barang;
            M->Elements[i].total = M->Elements[i+1].total;
            M->Elements[i].Kuantitas = M->Elements[i+1].Kuantitas;
            i++;
    }
    M->Count--;
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