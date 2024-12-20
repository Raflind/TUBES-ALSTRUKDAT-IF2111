#include "user.h"
#include "stackhistory.h"

void CreateListUser(ListUser *list) {
    list->nEff = 0;
}

boolean IsUserExist(ListUser *list, char *username) {
    for (int i = 0; i < list->nEff; i++) {
        int j = 0;
        while (username[j] != '\0' && list->buffer[i].name[j] != '\0' && username[j] == list->buffer[i].name[j]) {
            j++;
        }
        if (username[j] == '\0' && list->buffer[i].name[j] == '\0') {
            return true;
        }
    }
    return false;
}

void AddUser(ListUser *list, User newUser) {
    if (list->nEff < MAX_USERS) {
        list->buffer[list->nEff] = newUser;
        list->nEff++;
    }
}

int FindUser(ListUser *list, char *username) {
    for (int i = 0; i < list->nEff; i++) {
        int j = 0;
        while (username[j] != '\0' && list->buffer[i].name[j] != '\0' && username[j] == list->buffer[i].name[j]) {
            j++;
        }
        if (username[j] == '\0' && list->buffer[i].name[j] == '\0') {
            return i;
        }
    }
    return -1;
}

void CartPay(ListUser *list, User *user, Map *M, Stack *stackhistory){
    printf("Berikut adalah isi keranjangmu!\n");
    printf("Kuantitas  ");
    printf("Nama           ");
    printf("Total  ");
    int i = 0;
    while(i < M->Count){
        printf("%10d %14s %7d", M->Elements[i].Kuantitas, M->Elements[i].Barang.name, M->Elements[i].total);
    }
    i = 0;
    int total = 0;
    while(i < M->Count){
        total += M->Elements[i].total;
    }
    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak)");
    char validate[10];
    while(validate != "Ya" || validate != "Tidak"){
        START();
        StartWord();
        CopyWordToString(validate);
        if(strlent(validate) != 1){
            printf("Masukkan Input yang benar.");
        }
    }
    if(validate == "Ya"){
        int idx = FindUser(list, user->name);
        if(list->buffer[idx].money < total){
            printf("Uang kamu hanya %d, tidak cukup untuk membeli barang di keranjang\n", user->money);
        }
        else{
            printf("Selamat kamu telah membeli barang-barang tersebut!");
            list->buffer[idx].money -= total;
            AddtoPembelian(M, stackhistory);
        }
    }

}