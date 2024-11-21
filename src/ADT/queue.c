/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q) {
    return (IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITY);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q) {
    if (!isEmpty(q)) {
        return ((IDX_TAIL(q) - IDX_HEAD(q) + 100) % 100 + 1);        
    } else {
        return 0;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Barang val) {
    if (!isEmpty(*q)) {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    } else {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }

    TAIL(*q) = val;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, Barang *val) {
    *val = HEAD(*q);
    if (length(*q) == 1) {
        CreateQueue(q);
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }    
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void clearQueue(Queue *q) {
    Barang temp;
    while (!isEmpty(*q)) {
        dequeue(q, &temp);
    }
}
/* Menghapus semua antrian */

boolean IsMemberQ(Queue q, Barang v) {
    if (!isEmpty(q)) {
        Barang temp;
        int len = length(q);

        for (int i = 0; i < len; i++) {
            dequeue(&q, &temp);

            if (IsWordEqual(temp, v)) {
                enqueue(&q, temp);
                return true;
            }

            enqueue(&q, temp);
        }
    }

    return false;
}
/* Mengecek apakah elemen v ada di dalam queue q*/

/* *** Print Queue *** */
void PrintQueue(Queue q) {
    if (isEmpty(q)) {
        printf("  -\n");
    } else {
        Barang temp;
        int i = 1;
        int len = length(q);
        while (len > 0) {
            dequeue(&q, &temp);
            printf("  %d. ", i);
            PrintWord(temp);
            printf("\n");
            enqueue(&q, temp);
            i++;
            len--;
        }
    }
}

/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga barang berupa Platypus Laser, Shrink Ray, Net Shooter akan dicetak: [Platypus Laser, Shrink Ray, Net Shooter] */
/* Jika Queue kosong : menulis [] */