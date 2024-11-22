#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "barang.h"
#include "mesinkarakter.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef Barang ElemenQueue;

typedef struct {
    ElemenQueue buffer[CAPACITY];
    int idxHead;
    int idxTail;
} Queue;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb:
      - Index head bernilai IDX_UNDEF
      - Index tail bernilai IDX_UNDEF
      Proses : Melakukan inisialisasi */

boolean isEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */

int length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */


void enqueue(Queue *q, ElemenQueue val);
/* Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElemenQueue *val);
/* Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

boolean IsMemberQ(Queue q, char *name);
/* Mengecek apakah elemen dengan nama tertentu ada di dalam queue q */

#endif