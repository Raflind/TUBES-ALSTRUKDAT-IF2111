#ifndef MESINKATA_H
#define MESINKATA_H

#include "mesinkarakter.h"

#define MAX_WORD_LENGTH 256

typedef struct {
    char contents[MAX_WORD_LENGTH];
    int length;
} Word;

extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK, TAB, dan NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK, TAB, atau NEWLINE, atau currentChar = MARK atau EOF */

void StartWord();
/* Memulai pembacaan kata dari input
   I.S. : currentChar sembarang
   F.S. : currentWord berisi kata yang sudah diakuisisi
          Jika currentChar = MARK atau EOF, maka currentWord.length = 0 */

void StartWords();
/* Memulai pembacaan kata dari input
   I.S. : currentChar sembarang
   F.S. : currentWord berisi kata-kata yang sudah diakuisisi
          Jika currentChar = MARK atau EOF, maka currentWord.length = 0 */

void AdvanceWord();
/* Membaca kata berikutnya dari input
   I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord berisi kata yang sudah diakuisisi
          Jika currentChar = MARK atau EOF, maka currentWord.length = 0 */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi
          currentChar = BLANK, TAB, NEWLINE, MARK, atau EOF
          Jika panjang kata melebihi MAX_WORD_LENGTH, sisa kata "dipotong" */

void CopyWords();
/* Mengakuisisi kata-kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi
          currentChar = BLANK, TAB, NEWLINE, MARK, atau EOF
          Jika panjang kata melebihi MAX_WORD_LENGTH, sisa kata "dipotong" */

int IsWordEqual(Word word, char *string);
/* Mengembalikan 1 jika word sama dengan string, 0 jika tidak */

void CopyWordToString(char *destination);
/* Menyalin isi currentWord ke destination */

void ReadLine();
/* Membaca satu baris penuh dari input
   I.S. : currentChar sembarang
   F.S. : currentWord berisi baris yang dibaca hingga NEWLINE atau MARK atau EOF */

int IsWordNumber(Word word);
/* Mengembalikan 1 jika word adalah representasi angka, 0 jika tidak */

int WordToInt(Word word);
/* Mengubah word menjadi integer */

int string_compare(char *s1, char *s2);
/* Mengembalikan 0 jika kedua string sama,
   negatif jika s1 < s2,
   positif jika s1 > s2 */

void string_copy(char *dest, char *src);
/* Menyalin string src ke dest */

int strlent(char *str);

void clearNewline();
/* Membaca karakter sampai menemukan karakter newline */

int wordContainsBlank(Word word);
//Mengembalikan 1 jika kata mengandung blank ' ' atau '\t', 0 jika tidak

boolean IsSameWord(Word word1, Word word2);

#endif
