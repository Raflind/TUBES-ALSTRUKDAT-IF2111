#ifndef WISHLIST_H
#define WISHLIST_H

#include "linkedlist.h"
#include "listbarang.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "barang.h"

void wishlistAdd(ListBarang store, List *wishlist);
/* Menambah barang pada wishlist, bila kosong maka akan insertFirst, bila tidak akan insertLast */

void wishlistSwap(List *wishlist, char *word);
/* Menukar urutan barang pada wishlist */

void wishlistRemoveName(List *wishlist);
/* Menghilangkan barang dari wishlist sesuai nama barang */

void wishlistRemoveIdx(List *wishlist, char *word);
/* Menghilangkan barang dari wishlist sesuai index yang diberikan */

void wishlistClear(List *wishlist);
/* Mengkosongkan wishlist */

void wishlistShow(List wishlist);
/* Menampilkan wishlist dalam format <nomor>. <elemen> */

#endif