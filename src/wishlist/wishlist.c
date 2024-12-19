#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "listbarang.h"

void wishlistAdd(ListBarang store, List *wishlist) {
    printf("Masukkan nama barang: ");
    START();
    StartWords();

    char wish[MAX_LEN];
    CopyWordToString(wish);
    
    if (FindBarangByName(store, wish) != -1 && !isInList(*wishlist, wish)) {
        if (isEmptyList(*wishlist)) {
            insertFirst(wishlist, wish);
            printf("Berhasil menambahkan %s ke wishlist!\n", wish);
        }
        else {
            insertLast(wishlist, wish);
            printf("Berhasil menambahkan %s ke wishlist!\n", wish);
        }
    }

    else if (FindBarangByName(store, wish) == -1) {
        printf("Tidak ada barang dengan nama %s\n", wish);
        return;
    }

    else if (isInList(*wishlist, wish)) {
        printf("%s sudah ada di wishlist!\n", wish);
        return;
    }
}

void wishlistSwap(List *wishlist, char *word) {
    remainderWordalter(word, "SWAP");
    char strIdx1[MAX_LEN];
    char strIdx2[MAX_LEN];

    if (isValidForSplit(word)) {
        splitString(word, strIdx1, strIdx2);
        if (stringIsNum(strIdx1) && stringIsNum(strIdx2)) {
            int idx1 = stringToInt(strIdx1);
            int idx2 = stringToInt(strIdx2);
            if (idx1 <= lengthList(*wishlist) || idx2 <= lengthList(*wishlist)) {
                swapIdx(wishlist, idx1 - 1, idx2 - 1);
                printf("Berhasil menukar posisi %d dengan %d pada wishlist!\n", getElmt(*wishlist, idx1 - 1), getElmt(*wishlist, idx2 - 1));
            }
            else {
                printf("Gagal menukar posisi dalam wishlist\n");
                return;
            }
        }
        else{
            printf("Gagal menukar posisi dalam wishlist\n");
            return;
        }
    }
    else {
        printf("Gagal menukar posisi dalam wishlist\n");
        return;
    }
}

void wishlistRemoveName(List *wishlist) {
    printf("Masukkan nama barang yang akan dihapus: ");
    START();
    StartWords();

    char wish[MAX_LEN];
    char *temp = NULL;
    CopyWordToString(wish);

    if (isInList(*wishlist, wish)) {
        deleteAt(wishlist, indexOf(*wishlist, wish), &temp);
        free(temp);
        printf("%s berhasil dihapus dari WISHLIST!\n", wish);
    }
    else {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", wish);
        return;
    }
}

void wishlistRemoveIdx(List *wishlist, char *word) {
    remainderWordalter(word, "REMOVE");
    if (isEmptyList(*wishlist)) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }
    if (stringIsNum(word)) {
        int idx = stringToInt(word);
        if (idx > lengthList(*wishlist)) {
            printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", idx);
            return;
        }
        else {
            char *temp = NULL;
            deleteAt(wishlist, idx - 1, &temp);
            free(temp);
            printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", idx);
        }
    }
    else {
        printf("Penghapusan barang WISHLIST gagal dilakukan, command tidak valid!\n");
        return;
    }
}

void wishlistClear(List *wishlist) {
    clearList(wishlist);
    printf("Wishlist telah dikosongkan\n");
}

void wishlistShow(List wishlist) {
    if (!isEmptyList(wishlist)) {
        printList(wishlist);
    }
    else {
        printf("List kamu kosong!\n");
        return;
    }
}