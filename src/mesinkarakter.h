#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include <stdio.h>
#include "boolean.h"

#define MARK '~'
/*Hi ini marknya diganti buat handle save ya tq*/

/* State Mesin */
extern FILE *pita;
extern char currentChar;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : currentChar adalah karakter pada jendela
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          EOP menyala jika currentChar = MARK */

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOP();
/* Mengirimkan true jika currentChar = MARK */

void StartFile(char *filename);

void CloseFile();

void StartWriteFile(char *filename);

#endif