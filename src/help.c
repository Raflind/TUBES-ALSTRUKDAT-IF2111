#include "help.h"

void help_welcome(){
    printf("=====[ Menu Help PURRMART ]=====\n");
    printf("START -> Untuk masuk sesi baru\n");
    printf("LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("QUIT -> Untuk keluar dari program\n");
}

void help_login(){
    printf("=====[ Menu Help PURRMART ]=====\n");
    printf("REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf("LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf("QUIT -> Untuk keluar dari program\n");
}

void help_main(){
    printf("=====[ Menu Help PURRMART ]=====\n");
    printf("WORK -> Untuk bekerja\n");
    printf("WORK CHALLENGE -> Untuk mengerjakan challenge\n");
    printf("STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf("STORE REQUEST -> Untuk meminta penambahan barang\n");
    printf("STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf("STORE REMOVE -> Untuk menghapus barang\n");
    printf("LOGOUT -> Untuk keluar dari sesi\n");
    printf("SAVE -> Untuk menyimpan state ke dalam file\n");
    printf("QUIT -> Untuk keluar dari program\n");
    printf("PROFILE -> Untuk melihat data diri user\n");
    printf("HISTORY <n> -> Menampilkan riwayat <n> pembelian terbaru\n");
    printf("CART ADD <nama> <n> -> Menambahkan barang sebanyak <n>\n");
    printf("CART REMOVE <name> <n> -> Menghapus barang sebanyak <n>\n");
    printf("CART SHOW -> Menampilkan semua barang dalam CART\n");
    printf("CART PAY -> Membeli semua barang asal uang user cukup\n");
    printf("WISHLIST ADD -> Menambah barang ke wishlist\n");
    printf("WWISHLIST SWAP <i> <j> -> Menukar posisi barang dalam wishlist\n");
    printf("WISHLIST REMOVE <i> -> Menghapus barang pada posisi <i>\n");
    printf("WISHLIST REMOVE -> Menghapus barang sesuai nama\n");
    printf("WISHLIST CLEAR -> Menghapus semua barang dalam wishlist\n");
    printf("WISHLIST SHOW -> Menampilkan wishlist user\n");
}