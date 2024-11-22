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
   F.S. : currentChar ≠ BLANK dan currentChar ≠ NEWLINE atau currentChar = MARK atau EOF */

void STARTWORD();
/* Memulai pembacaan kata dari input
   I.S. : currentChar sembarang
   F.S. : EndWord = true jika currentChar = MARK atau EOF
          EndWord = false jika tidak
          currentWord berisi kata yang sudah diakuisisi */

void STARTWORD_STDIN();
/* Sama seperti STARTWORD, tetapi secara eksplisit membaca dari stdin
   I.S. : currentChar sembarang
   F.S. : EndWord dan currentWord terinisialisasi sesuai dengan input */

void ADVWORD();
/* Membaca kata berikutnya dari input
   I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord berisi kata yang sudah diakuisisi
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK atau EOF
          Jika currentChar = MARK atau EOF, maka EndWord = true */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi
          currentChar = BLANK atau NEWLINE atau MARK atau EOF
          currentChar adalah karakter setelah karakter terakhir yang diakuisisi
          Jika panjang kata melebihi NMax, sisa kata "dipotong" */

boolean IsEndWord();
/* Mengecek apakah pembacaan kata telah mencapai akhir
   Mengirimkan true jika EndWord = true */

void ReadWord();
/* Membaca kata dari input hingga EndWord = true
   I.S. : currentChar sembarang
   F.S. : Semua kata telah dibaca dan diproses */

void GetWord(Word input, int idx);
/* Mengambil kata pada indeks tertentu dari input (jika diperlukan)
   I.S. : input adalah Word yang valid, idx adalah indeks yang diinginkan
   F.S. : Mengembalikan kata pada indeks idx */

Word toKata(char *str);
/* Mengubah string menjadi tipe Word
   I.S. : str adalah string yang valid
   F.S. : Mengembalikan Word yang berisi karakter-karakter dari str */

boolean IsWordString(Word kata, char *string);
/* Mengecek apakah sebuah Word sama dengan string
   I.S. : kata dan string adalah input yang valid
   F.S. : Mengembalikan true jika kata dan string identik, false jika tidak */

boolean IsWordEqual(Word kata1, Word kata2);
/* Mengecek apakah dua buah Word sama
   I.S. : kata1 dan kata2 adalah Word yang valid
   F.S. : Mengembalikan true jika kata1 dan kata2 identik, false jika tidak */

boolean IsWordNumber(Word kata);
/* Mengecek apakah sebuah Word merupakan representasi dari angka
   I.S. : kata adalah Word yang valid
   F.S. : Mengembalikan true jika semua karakter dalam kata adalah digit angka */

void PrintWord(Word kata);
/* Mencetak Word ke layar
   I.S. : kata adalah Word yang valid
   F.S. : Menampilkan karakter-karakter dalam kata ke layar */

Word IntToWord(int n);
/* Mengubah integer menjadi Word
   I.S. : n adalah integer yang valid
   F.S. : Mengembalikan Word yang merepresentasikan n dalam bentuk string */

int WordToInt(Word kata);
/* Mengubah Word menjadi integer
   I.S. : kata adalah Word yang merepresentasikan angka
   F.S. : Mengembalikan integer yang sesuai dengan nilai dalam kata */

void STARTLINE();
/* Membaca satu baris penuh dari stdin tanpa menggunakan fgets atau scanf
   I.S. : stdin siap untuk dibaca
   F.S. : currentWord berisi baris yang dibaca hingga NEWLINE atau EOF
          EndWord = false */

void ParseLineToWords();
/* Memecah currentWord menjadi array of words (wordArray)
   I.S. : currentWord berisi satu baris input
   F.S. : wordArray berisi kata-kata yang dipisahkan oleh spasi
          wordCount berisi jumlah kata yang berhasil diparsing
          currentWordIndex diatur ke 0 */

Word GetNextWord();
/* Mengambil kata berikutnya dari wordArray
   I.S. : currentWordIndex sembarang
   F.S. : Mengembalikan Word pada indeks currentWordIndex dan meningkatkan currentWordIndex
          Jika currentWordIndex >= wordCount, mengembalikan Word kosong dan EndWord = true */

#endif
