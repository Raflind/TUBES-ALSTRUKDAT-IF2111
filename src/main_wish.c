#include <stdio.h>
#include <stdlib.h>
#include "wishlist.h"
#include "linkedlist.h"
#include "boolean.h"
#include "listbarang.h"
#include "barang.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "queue.h"

int main(){
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

    List wishlist;
    CreateList(&wishlist);

    while(true){
        START();
        StartWords();

        char word[MAX_LEN];
        CopyWordToString(word);

        if (IsSameFirstWord(word, "WISHLIST")) {
            remainderWordalter(word, "WISHLIST");
            if (IsSameFirstWord(word, "ADD")) {
                wishlistAdd(store_list, &wishlist);
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
                wishlistShow(wishlist);
            }
            else {
                printf("INVALIDDDDDD\n");
            }
        }
        else if (IsSameFirstWord(word, "exit")){
            printf("bye bye bye bye\n");
            break;
        }
        else {
            printf("WISHLISTT OIIII\n");
        }
    }
    
    FreeListBarang(&store_list);
}