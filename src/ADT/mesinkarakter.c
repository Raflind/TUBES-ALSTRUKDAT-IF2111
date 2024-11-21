/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#include <stdio.h>
#include "mesinkarakter.h"


char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START(char *filename) {
    pita = fopen(filename, "r");
    if (pita) {
        retval = fscanf(pita, "%c", &currentChar);
        if (retval > 0) {
            EOP = (currentChar == MARK);
        } else {
            EOP = true;
        }
    } else {
        EOP = true;
    }
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari file.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void START_STDIN() {
    pita = stdin;
    ADV();
}
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */


void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    if (retval > 0) {
        EOP = (currentChar == MARK);
    } else {
        EOP = true;
    }

    if (EOP && pita != stdin) {
        fclose(pita); 
    }
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC() {
    return currentChar;
}
/* Mengirimkan currentChar */

boolean IsEOP() {
    return EOP;
}
/* Mengirimkan true jika currentChar = MARK */