/* File: mesinkarakter.c */
/* Implementasi Mesin Karakter */

#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START() {
    pita = stdin;
    ADV();
}

void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    if (retval == EOF) {
        EOP = true;
    } else {
        EOP = (currentChar == MARK);
    }
}

char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return EOP;
}
