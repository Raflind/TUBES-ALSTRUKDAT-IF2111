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

    STARTLINE();

    if (currentWord.Length == 0) {
        printf("Nama barang tidak boleh kosong!\n");
        return;
    }

    char item_name[MAX_LEN];
    for (int i = 0; i < currentWord.Length && i < MAX_LEN - 1; i++) {
        item_name[i] = currentWord.TabWord[i];
    }
    item_name[currentWord.Length] = '\0';

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

    STARTLINE();

    if (currentWord.Length == 0) {
        printf("Input tidak valid.\n");
        enqueue(requests, item);
        return;
    }

    char response[MAX_LEN];
    for (int i = 0; i < currentWord.Length && i < MAX_LEN - 1; i++) {
        response[i] = currentWord.TabWord[i];
    }
    response[currentWord.Length] = '\0';

    if (string_compare(response, "Terima") == 0) {
        printf("Harga barang: ");
        STARTLINE();

        if (currentWord.Length == 0 || !IsWordNumber(currentWord)) {
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

    STARTLINE();

    if (currentWord.Length == 0) {
        printf("Nama barang tidak boleh kosong!\n");
        return;
    }

    char item_name[MAX_LEN];
    for (int i = 0; i < currentWord.Length && i < MAX_LEN - 1; i++) {
        item_name[i] = currentWord.TabWord[i];
    }
    item_name[currentWord.Length] = '\0';

    int index = FindBarangByName(*store_list, item_name);

    if (index != -1) {
        RemoveBarangAt(store_list, index);
        printf("'%s' telah berhasil dihapus dari toko.\n", item_name);
    } else {
        printf("Toko tidak menjual '%s'.\n", item_name);
    }
}

void store_menu(ListBarang *store_list, Queue *requests) {
    int running = 1;
    while (running) {
        printf("\nMasukkan command (STORE LIST, STORE REQUEST, STORE SUPPLY, STORE REMOVE, QUIT): ");

        STARTLINE();
        ParseLineToWords();

        if (wordCount == 0) {
            printf("Command tidak dikenal.\n");
            continue;
        }

        Word commandWord = wordArray[0];
        char command[MAX_LEN];
        for (int i = 0; i < commandWord.Length && i < MAX_LEN - 1; i++) {
            command[i] = commandWord.TabWord[i];
        }
        command[commandWord.Length] = '\0';

        if (string_compare(command, "STORE") == 0) {
            if (wordCount < 2) {
                printf("Subcommand STORE tidak lengkap.\n");
                continue;
            }

            Word subcommandWord = wordArray[1];
            char subcommand[MAX_LEN];
            for (int i = 0; i < subcommandWord.Length && i < MAX_LEN - 1; i++) {
                subcommand[i] = subcommandWord.TabWord[i];
            }
            subcommand[subcommandWord.Length] = '\0';

            if (string_compare(subcommand, "LIST") == 0) {
                display_store_list(*store_list);
            } else if (string_compare(subcommand, "REQUEST") == 0) {
                store_request(*store_list, requests);
            } else if (string_compare(subcommand, "SUPPLY") == 0) {
                store_supply(store_list, requests);
            } else if (string_compare(subcommand, "REMOVE") == 0) {
                store_remove(store_list);
            } else {
                printf("Subcommand STORE tidak dikenal.\n");
            }
        } else if (string_compare(command, "QUIT") == 0) {
            running = 0;
            printf("Program dihentikan.\n");
        } else {
            printf("Command tidak dikenal.\n");
        }
    }
}
