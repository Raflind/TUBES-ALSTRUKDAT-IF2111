#ifndef MESINKATA_H
#define MESINKATA_H

#include "mesinkarakter.h"

#define MAX_WORD_LENGTH 50

typedef struct {
    char contents[MAX_WORD_LENGTH];
    int length;
} Word;

extern Word currentWord;

void IgnoreBlanks();
void StartWord();
void AdvanceWord();
void CopyWord();
int IsWordEqual(Word word, char *string);
void CopyWordToString(char *destination);
void ReadLine();
/* Membaca satu baris penuh dari input
   I.S. : currentChar sembarang
   F.S. : currentWord berisi baris yang dibaca hingga NEWLINE atau MARK atau EOF */

int IsWordNumber(Word word);
/* Mengembalikan 1 jika word adalah representasi angka, 0 jika tidak */

int WordToInt(Word word);
/* Mengubah word menjadi integer */
#endif
