#ifndef __QUIT__H
#define __QUIT__H

#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include "../ADT/queue.h"
#include "../ADT/listbarang.h"
#include "../ADT/user.h"
#include "store.h"
#include "save.h"

void quit(Queue *request, ListUser *listuser, ListBarang *listbarang);
/*
I.S: Sembarang
F.s: Antrean kosong dan keluar dari sistem 
*/

#endif