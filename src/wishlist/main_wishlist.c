#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "wishlist.h"
#include "listbarang.h"
#include "barang.h"

/* Hanya contoh bila diintegrasikan pada main.c */
int main() {
    List wishlist;
    ListBarang listbarang;

    CreateList(&wishlist);
    InitializeListBarang(&listbarang);

    while(true) {
        START();
        StartWords();

        char word[100];
        CopyWordToString(word);

        if (IsSameFirstWord(word, "WISHLIST")) {
            remainderWordalter(word, "WISHLIST");
            if (IsSameFirstWord(word, "ADD")) {
                wishlistAdd(listbarang, &wishlist);
            }

            else if (IsSameFirstWord(word, "SWAP")) {
                wishlistSwap(&wishlist, word);
            }

            else if (IsSameFirstWord(word, "REMOVE")) {
                if (isThereBlank(word)) {
                    wishlistRemoveIdx(&wishlist, word);
                }
                else {
                    wishlistRemoveName(&wishlist);
                }
            }

            else if (IsSameFirstWord(word,"CLEAR")) {
                wishlistClear(&wishlist);
            }

            else if (IsSameFirstWord(word, "SHOW")) {
                if (!isEmpty(wishlist)) {
                    wishlistShow(wishlist);
                }
                else {
                    printf("Wishlist kamu kosong!\n");
                }
            }
        }

        else if (IsSameFirstWord(word, "exit")) {
            printf ("bye bitch\n");
            return 0;
        }

        else {
            printf("WISHLIST OIIII!!\n");
        }
    }
}