#ifndef STACKHISTORY_H
#define STACKHISTORY_H

#include "boolean.h"
#include "barang.h"

#define Nil -1
#define MaxEl 100
#define MaxItems 10
#define NamaMax MAX_LEN

typedef struct {
    Barang barang;
    int jumlah_dibeli;
    int total;
} Cart;

typedef struct {
    int id;
    int total;
    int jumlah_barang;
    Cart cart[MaxItems];
} Pembelian;


typedef Pembelian infotype;
typedef int address;

typedef struct { 
    infotype T[MaxEl];
    address TOP;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsStackFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */


void PrintStackHistory(Stack S, int N);
// Menampilkan riwayat pembelian sebanyak N, dimulai dari pembelian terbaru (top element)
// Stack mungkin kosong, N mungkin lebih banyak dari neff stack

#endif
