#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

FILE *pita;
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

void StartFile(char *filename) {
    pita = fopen(filename, "r");
    if (pita == NULL) {
        printf("Error: File %s tidak dapat dibuka.\n", filename);
        EOP = true;
    } else {
        EOP = false;
        ADV();
    }
}

void CloseFile() {
    if (pita != NULL) {
        fclose(pita);
        pita = NULL;
    }
}

void StartWriteFile(char *filename) {
    pita = fopen(filename, "w");
}