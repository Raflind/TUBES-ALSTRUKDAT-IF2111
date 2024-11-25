#ifndef __QUIT__H
#define __QUIT__H

#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/queue/queue.h"
#include "../ADT/listbarang/listbarang.h"
#include "store.h"
#include "../ADT/user/user.h"
#include "save.h"

void quit(Queue *request, ListUser *listuser, ListBarang *listbarang);
/*
I.S: Sembarang
F.s: Antrean kosong dan keluar dari sistem 
*/

#endif