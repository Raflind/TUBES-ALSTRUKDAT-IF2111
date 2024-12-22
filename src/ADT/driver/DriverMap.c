#include <stdio.h>
#include "map.h"
#include "barang.h"

int main(){
    Map cart;
    CreateEmpty(&cart);
    Barang barang1, barang2, barang3;

    barang1.name = "Lalabu";
    barang1.price = 20;

    barang2.name = "AK47";
    barang2.price = 10;

    barang3.name = "Meong";
    barang3.price = 500;

    printf("Menambahkan barang ke keranjang:\n");
    Insert(&cart, barang1, 2);
    printf("%s ditambahkan sebanyak 2.\n", barang1.name);
    Insert(&cart, barang2, 5);
    printf("%s ditambahkan sebanyak 5.\n", barang2.name);

    if(IsMember(cart, barang1)){
        printf("%s ada dalam keranjang.\n", barang1.name);
    }

    printf("Total harga %s: %d\n", barang1.name, Value(cart, barang1));
    printf("Kuantitas %s: %d\n", barang1.name, Quantity(cart, barang1));

    Insert(&cart, barang1, 3);
    printf("%s ditambahkan lagi sebanyak 3.\n", barang1.name);
    printf("Kuantitas baru %s: %d\n", barang1.name, Quantity(cart, barang1));

    Delete(&cart, barang1);
    printf("%s dihapus dari keranjang.\n", barang1.name);

    if(IsEmpty(cart)){
        printf("Keranjang sekarang kosong.\n");
    }
    else{
        printf("Keranjang masih berisi barang.\n");
    }

    Insert(&cart, barang3, 4);
    int address = GetAddress(cart, barang3);
    if(address != Undefined){
        printf("Alamat %s dalam keranjang: %d\n", barang3.name, address);
    }
    else{
        printf("%s tidak ditemukan dalam keranjang.\n", barang3.name);
    }

    printf("Menambahkan barang sampai penuh:\n");
    for(int i = 0; i< MaxElCart-cart.Count; i++){
        Barang temp;
        temp.name = "Barang";
        temp.price = 1000;
        Insert(&cart, temp, 1);
    }
    if(IsFull(cart)){
        printf("Keranjang sekarang penuh.\n");
    }
    else{
        printf("Keranjang belum penuh.\n");
    }
    return 0;
}