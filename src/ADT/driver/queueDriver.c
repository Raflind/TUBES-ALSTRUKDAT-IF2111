#include <stdio.h>
#include "../queue.h"

int main() {
    Queue q;
    ElemenQueue item1, item2, item3, item4, buang;
    CreateQueue(&q);

    // Inisialisasi elemen barang
    ElemenQueue item1 = {"Shotgun", 100};
    ElemenQueue item2 = {"Claymore", 200};
    ElemenQueue item3 = {"Bow", 300};
    ElemenQueue item3 = {"Lightsaber", 400};

    // Tes queue kosong
    if (isEmpty(q)) {
        printf("Queue kosong.\n");
    } else {
        printf("Queue tidak kosong.\n");
    }
    printf("\n");

    // Tes insert elemen
    enqueue(&q, item1);
    enqueue(&q, item2);
    enqueue(&q, item3);
    enqueue(&q, item4);

    // Print isi queue
    printf("Isi Queue:\n");
    for (int i = 0; i < length(q); i++) {
        int idx = (IDX_HEAD(q) + i) % CAPACITY;
        printf("  Nama: %s, Harga: %d\n", q.buffer[idx].name, q.buffer[idx].price);
    }
    printf("\n");


    // Tes apakah "Bow" ada di Queue
    if (IsMemberQ(q, "Bow")) {
        printf("Bow ada di Queue.\n");
    } else {
        printf("Bow tidak ada di Queue.\n");
    }
    printf("\n");

    // Tes apakah Queue penuh
    if (isFull(q)) {
        printf("Queue penuh.\n");
    } else {
        printf("Queue tidak penuh.\n");
    }
    printf("\n");

    // Cek panjang Queue
    printf("Panjang Queue: %d\n", length(q));
    printf("\n");

    // Hapus elemen
    dequeue(&q, &buang);
    printf("Elemen dequeue: Nama: %s, Harga: %d\n", buang.name, buang.price);
    printf("\n");

    // Print isi queue setelah penghapusan elemen
    printf("Isi Queue setelah dequeue:\n");
    for (int i = 0; i < length(q); i++) {
        int idx = (IDX_HEAD(q) + i) % CAPACITY;
        printf("  Nama: %s, Harga: %d\n", q.buffer[idx].name, q.buffer[idx].price);
    }
    printf("\n");

    return 0;
    
}