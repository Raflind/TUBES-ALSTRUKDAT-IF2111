#ifndef CART_H
#define CART_H

#include "map.h"
#include <stdio.h>
#include "listbarang.h"
#include "mesinkata.h"


void CartAdd(Map *M, ListBarang list, char *name, int quantity);

void CartRemove(Map *M, ListBarang list, char *name, int quantity);

void DisplayCart(Map M);

int TotalHarga(Map M);

#endif
