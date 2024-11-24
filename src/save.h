#ifndef __SAVE__H__
#define __SAVE__H__

#include "mesinkarakter.h"
#include "mesinkata.h"
#include "listbarang.h"
#include "user.h"
#include "barang.h"

void save(ListUser *listuser, ListBarang *listbarang, char *filename);
/*
/* I.S. store_list dan user_list terdefinisi, filename valid */
/* F.S. Data tersimpan dalam suatu file baru atau merewrite file yang sudah ada *
*/

#endif