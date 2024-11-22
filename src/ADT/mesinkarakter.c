#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;

void START(char *filename) {
    if (filename != NULL) {
        pita = fopen(filename, "r");
        if (pita != NULL) {
            ADV();
        } else {
            EOP = true;
        }
    } else {
        pita = stdin;
        ADV();
    }
}

void START_STDIN() {
    pita = stdin;
    ADV();
}

void ADV() {
    int retval = fscanf(pita, "%c", &currentChar);
    if (retval == EOF) {
        EOP = true;
    } else {
        EOP = (currentChar == MARK);
    }

    if (EOP && pita != stdin) {
        fclose(pita);
    }
}

char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return EOP;
}

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
