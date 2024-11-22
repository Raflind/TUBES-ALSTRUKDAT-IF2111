/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define MARK '.'
/* State Mesin */
extern char currentChar;
extern boolean EOP;

void START();
void ADV();
char GetCC();
boolean IsEOP();

#endif
