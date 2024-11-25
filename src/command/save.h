#ifndef __SAVE__H__
#define __SAVE__H__

#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/listbarang/listbarang.h"
#include "../ADT/user/user.h"
#include "../ADT/barang.h"

void save(ListUser *listuser, ListBarang *listbarang, char *filename);
/*
/* I.S. store_list dan user_list terdefinisi, filename valid */
/* F.S. Data tersimpan dalam suatu file baru atau merewrite file yang sudah ada *
*/

#endif