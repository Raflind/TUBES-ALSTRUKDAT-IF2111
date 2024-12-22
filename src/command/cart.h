#ifndef CART_H
#define CART_H

#include <stdio.h>
#include "../ADT/map.h"
#include "../ADT/listbarang.h"
#include "../ADT/mesinkata.h"


void CartAdd(Map *M, ListBarang list, char *name, int quantity);

void CartRemove(Map *M, ListBarang list, char *name, int quantity);

int TotalHarga(Map M);

#endif
