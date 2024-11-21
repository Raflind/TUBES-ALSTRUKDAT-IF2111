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

/* Implementasi Fungsi Utility */

int string_compare(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
        i++;
    }
    return 0;
}

void string_copy(char *dest, char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0')
        i++;
}