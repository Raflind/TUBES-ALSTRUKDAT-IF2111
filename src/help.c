#include "help.h"

void help_welcome(){
    printf("=====[ Menu Help PURRMART]=====\n");
    const char *list[] = {
        "START -> Untuk masuk sesi baru",
        "LOAD -> Untuk memulai sesi berdasarkan file konfigurasi",
        "QUIT -> Untuk keluar dari program"};
    for (int i = 0; i < 3; i++){
        printf("%d. %s\n", i + 1, list[i]);
    }
}

void help_login(){
    printf("=====[ Menu Help PURRMART]=====\n");
    const char *list[] = {
        "REGISTER -> Untuk melakukan pendaftaran akun baru",
        "LOGIN -> Untuk masuk ke dalam akun dan memulai sesi",
        "QUIT -> Untuk keluar dari program"};
    for (int i = 0; i < 3; i++){
        printf("%d. %s\n", i + 1, list[i]);
    }
}

void help_main(){
    printf("=====[ Menu Help PURRMART]=====\n");
    const char *list[] ={
        "WORK -> Untuk bekerja",
        "WORK CHALLENGE -> Untuk mengerjakan challenge",
        "STORE LIST -> Untuk melihat barang-barang di toko",
        "STORE REQUEST -> Untuk meminta penambahan barang",
        "STORE SUPPLY -> Untuk menambahkan barang dari permintaan",
        "STORE REMOVE -> Untuk menghapus barang",
        "LOGOUT -> Untuk keluar dari sesi",
        "SAVE -> Untuk menyimpan state ke dalam file",
        "QUIT -> Untuk keluar dari program"};
    for (int i = 0; i < 9; i++){
        printf("%d. %s\n", i + 1, list[i]);
    }
}