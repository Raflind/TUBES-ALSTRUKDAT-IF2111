#ifndef MESINKATA_H
#define MESINKATA_H

#include "boolean.h"
#include "mesinkarakter.h"

#define NMax 256
#define BLANK ' '
#define NEWLINE '\n'
#define MAX_WORDS 100

typedef struct
{
    char TabWord[NMax]; 
    int Length;
} Word;

extern boolean EndWord;
extern Word currentWord;

extern Word wordArray[MAX_WORDS];
extern int wordCount;
extern int currentWordIndex;


void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK dan NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORD_STDIN();
/* Sama seperti STARTWORD, tetapi pita berasal dari stdin */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsEndWord();
/* Mengirimkan true jika currentWord adalah kata terakhir */

void ReadWord();
/* Membaca kata dari input */

void GetWord(Word input, int idx);
/* Mengambil kata berdasarkan indeks tertentu */

Word toKata(char *str);
/* Mengubah string menjadi tipe Word */

boolean IsWordString(Word kata, char *string);
/* Mengecek apakah sebuah Word sama dengan string */

boolean IsWordEqual(Word kata1, Word kata2);
/* Mengecek apakah dua buah Word sama */

boolean IsWordNumber(Word kata);
/* Mengecek apakah Word merupakan angka */

void PrintWord(Word kata);
/* Mencetak Word */

Word IntToWord(int n);
/* Mengubah integer menjadi Word */

int WordToInt(Word kata);
/* Mengubah Word menjadi integer */

/* Fungsi Baru untuk Membaca Baris Input */
void STARTLINE();
/* Membaca satu baris penuh dari stdin */

void ParseLineToWords();
/* Memecah currentWord menjadi array of words */

Word GetNextWord();
/* Mengambil kata berikutnya dari wordArray */

#endif