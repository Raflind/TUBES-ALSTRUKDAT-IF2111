#include <stdio.h>
#include "quit.h"

void quit(Queue *request, ListUser *listuser, ListBarang *listbarang) {
    int isValid = 0;

    do {
        printf("Apakah ingin melakukan save sebelum keluar? (Y/N): ");
        START();  
        char saved[MAX_WORD_LENGTH];
        StartWords();
        CopyWordToString(saved);

        if (string_compare(saved, "Y") == 0) {
            isValid = 1;
            save(listuser, listbarang, saved);
        } 
        else if (string_compare(saved, "N") == 0) {
            isValid = 1;  
        } 
        else {
            printf("Input tidak valid. Mohon masukkan 'Y' atau 'N'.\n");
            isValid = 0;
        }
    } while (!isValid);

    while (!isEmpty(*request)) {
        Barang item;
        dequeue(request, &item);
    }

    printf("Kamu keluar dari PURRMART.\n Dadah^_^/\n");
}


