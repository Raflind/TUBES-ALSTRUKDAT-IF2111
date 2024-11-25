#include <stdio.h>
#include "quit.h"

void quit(Queue *request, ListUser *listuser, ListBarang *listbarang) {
    int isValid = 0;

    do {
        printf("Apakah ingin melakukan save sebelum keluar? (Y/N): ");
        START();  

        if (currentChar == 'Y') {
            isValid = 1;

            printf(">>SAVE ");
            char saved[100];
            StartWords();
            CopyWordToString(saved);
            for (int i = 0; saved[i] != '\0'; i++) {
                if (saved[i] == '\n') {
                    saved[i] = '\0';
                    break;
                }
            }

            save(listuser, listbarang, saved);
        } else if (currentChar == 'N') {
            isValid = 1;  
        } else {
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


