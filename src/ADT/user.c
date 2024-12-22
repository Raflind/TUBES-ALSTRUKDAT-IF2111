#include "user.h"
#include "stackhistory.h"

void CreateListUser(ListUser *list) {
    list->nEff = 0;
    for (int i = 0; i < MAX_USERS; i++) {
        CreateEmptyStack(&list->buffer[i].riwayat_pembelian);
    }
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

void CartPay(ListUser *list, User *user, Map *M){
    printf("Berikut adalah isi keranjangmu!\n");
    printf("Kuantitas  ");
    printf("Nama           ");
    printf("Total  \n");
    int i = 0;
    while(i < M->Count){
        printf("%-10d %-14s %d\n", M->Elements[i].Kuantitas, M->Elements[i].Barang.name, M->Elements[i].total);
        i++;
    }
    i = 0;
    int total = 0;
    while(i < M->Count){
        total += M->Elements[i].total;
        i++;
    }
    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak)\n", total);
    char validate[10];
    while(1){
        START();
        StartWord();
        CopyWordToString(validate);
        if(string_compare(validate, "Ya") == 0 || string_compare(validate, "Tidak") == 0 ){
            break;
        }
        else{
            printf("Masukkan Input yang benar.\n");
        }
    }
    if(string_compare(validate, "Ya") == 0){
        int idx = FindUser(list, user->name);
        if(list->buffer[idx].money < total){
            printf("Uang kamu hanya %d, tidak cukup untuk membeli barang di keranjang\n", user->money);
        }
        else{
            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
            list->buffer[idx].money -= total;
            user->money -= total;
            AddtoPembelian(M, &user->riwayat_pembelian);
            CreateEmpty(&user->keranjang);
            CreateEmpty(M);
        }
    }

}

void DisplayCart(Map M){
    if(IsEmpty(M)){
        printf("Tidak ada Barang apapun di Keranjang.\n");
    }
    else{
        printf("Berikut adalah isi keranjangmu!\n");
        printf("Kuantitas  ");
        printf("Nama           ");
        printf("Total  \n");
        int i = 0;
        while(i < M.Count){
            printf("%-10d %-14s %d\n", M.Elements[i].Kuantitas, M.Elements[i].Barang.name, M.Elements[i].total);
            i++;
        }
    }
}

void AddCartToUser(Map M, User *user){
    user->keranjang = M;
}

void AddWishlistToUser(List wishlist, User *user){
    user->wishlist = wishlist;
}