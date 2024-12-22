#ifndef STORE_H
#define STORE_H

#include "../ADT/listbarang.h"
#include "../ADT/queue.h"

void display_store_list(ListBarang store_list);
/* Menampilkan daftar barang yang ada di toko */

void store_request(ListBarang store_list, Queue *requests);
/* Memproses permintaan penambahan barang baru ke toko */

void store_supply(ListBarang *store_list, Queue *requests);
/* Memproses supply barang berdasarkan permintaan dalam antrian */

void store_remove(ListBarang *store_list);
/* Menghapus barang dari toko berdasarkan nama */

#endif