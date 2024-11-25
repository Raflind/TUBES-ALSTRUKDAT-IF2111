#ifndef LISTBARANG_H
#define LISTBARANG_H

#include "../boolean.h"
#include "../barang.h"
#include "../mesinkata/mesinkata.h"

typedef struct {
    Barang *buffer;
    int capacity;
    int neff;
} ListBarang;

void InitializeListBarang(ListBarang *list);
/* I.S. sembarang */
/* F.S. Sebuah list barang kosong terbentuk dengan kapasitas awal tertentu */

int LengthList(ListBarang list);
/* Mengirimkan banyaknya elemen list. Mengirimkan 0 jika list kosong */

boolean IsListEmpty(ListBarang list);
/* Mengirimkan true jika list kosong */

Barang GetBarangAt(ListBarang list, int idx);
/* Mengembalikan barang pada indeks idx (indeks mulai dari 0) */

void AddBarang(ListBarang *list, Barang item);
/* Menambahkan barang ke list */
/* I.S. list mungkin kosong, list tidak penuh */
/* F.S. item menjadi elemen terakhir yang baru di list */

int FindBarangByName(ListBarang list, char *name);
/* Mengembalikan indeks barang dengan nama tertentu di list */
/* Mengembalikan -1 jika tidak ditemukan */

void RemoveBarangAt(ListBarang *list, int idx);
/* Menghapus barang pada indeks idx dari list */
/* I.S. idx valid (0 <= idx < LengthList(list)) */
/* F.S. Barang pada indeks idx dihapus dari list */

void DisplayListBarang(ListBarang list);
/* Menampilkan daftar barang yang ada di list */
/* I.S. list mungkin kosong */
/* F.S. Jika list tidak kosong, menampilkan nama barang yang ada di list */

void FreeListBarang(ListBarang *list);
/* Membebaskan memori yang dialokasikan untuk list */
/* I.S. list terdefinisi */
/* F.S. Memori untuk buffer list dibebaskan */

#endif