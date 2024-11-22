#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int value;

void START() {
    pita = stdin;
    ADV();
}

void ADV() {
    value = fscanf(pita, "%c", &currentChar);
    if (currentChar == MARK){
        EOP = true;
        fclose(pita);
    } else {
        EOP = false;
    }
}

char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return (currentChar == MARK);
}
