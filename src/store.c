#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "mesinkata.h"
#include "mesinkarakter.h"


void display_store_list(ListBarang store_list) {
    DisplayListBarang(store_list);
}

void store_request(ListBarang store_list, Queue *requests) {
    printf("Nama barang yang diminta: ");

    StartWords();

    if (currentWord.length == 0) {
        printf("Nama barang tidak boleh kosong!\n");
        return;
    }

    char item_name[MAX_LEN];
    CopyWordToString(item_name);

    if (FindBarangByName(store_list, item_name) != -1) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    if (IsMemberQ(*requests, item_name)) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
        return;
    }

    Barang new_item;
    string_copy(new_item.name, item_name);
    new_item.price = 0; // Harga belum ditentukan

    enqueue(requests, new_item);
    printf("Permintaan barang '%s' telah ditambahkan ke antrian.\n", new_item.name);
}

void store_supply(ListBarang *store_list, Queue *requests) {
    if (isEmpty(*requests)) {
        printf("Tidak ada permintaan barang dalam antrian.\n");
        return;
    }

    Barang item;
    dequeue(requests, &item);

    printf("Apakah kamu ingin menambahkan barang %s (Terima/Tunda/Tolak): ", item.name);

    StartWords();

    if (currentWord.length == 0) {
        printf("Input tidak valid.\n");
        enqueue(requests, item);
        return;
    }

    char response[MAX_LEN];
    CopyWordToString(response);

    if (string_compare(response, "Terima") == 0) {
        printf("Harga barang: ");
        StartWords();

        if (currentWord.length == 0 || !IsWordNumber(currentWord)) {
            printf("Harga barang tidak valid.\n");
            enqueue(requests, item);
            return;
        }

        int price = WordToInt(currentWord);

        if (price <= 0) {
            printf("Harga barang tidak valid.\n");
            enqueue(requests, item);
            return;
        }

        item.price = price;
        AddBarang(store_list, item);
        printf("'%s' dengan harga %d telah ditambahkan ke toko.\n", item.name, item.price);
    } else if (string_compare(response, "Tunda") == 0) {
        enqueue(requests, item);
        printf("'%s' dikembalikan ke antrian.\n", item.name);
    } else if (string_compare(response, "Tolak") == 0) {
        printf("'%s' dihapuskan dari antrian.\n", item.name);
    } else {
        enqueue(requests, item);
        printf("< Balik ke menu >\n");
    }
}

void store_remove(ListBarang *store_list) {
    printf("Nama barang yang akan dihapus: ");

    StartWords();

    if (currentWord.length == 0) {
        printf("Nama barang tidak boleh kosong!\n");
        return;
    }

    char item_name[MAX_LEN];
    CopyWordToString(item_name);

    int index = FindBarangByName(*store_list, item_name);

    if (index != -1) {
        RemoveBarangAt(store_list, index);
        printf("'%s' telah berhasil dihapus dari toko.\n", item_name);
    } else {
        printf("Toko tidak menjual '%s'.\n", item_name);
    }
}
