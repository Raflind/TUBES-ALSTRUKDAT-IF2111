/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK || currentChar == '\r') {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(char* filename) {
    START(filename);
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORD_STDIN() {
    START_STDIN();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord() {
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != '\r' && currentChar != MARK) {
        if (currentWord.Length < NMax) {
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        } else {
            break;
        }
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

boolean IsEndWord() {
    return EndWord;
}
/* Mengecek apakah sudah mencapai akhir kata */

void ReadWord() {
    while (!IsEndWord()) {
        PrintWord(currentWord); 
        printf("\n");
        ADVWORD(); 
    }
}
/* Membaca kata tertentu dari input */

void GetWord(Word input, int idx) {
    int count = 0, i = 0;
    Word output;
    output.Length = 0;

    while (i < input.Length && count <= idx) {
        if (input.TabWord[i] != BLANK) {
            output.TabWord[output.Length] = input.TabWord[i];
            output.Length++;
        } else {
            if (count < idx) { 
                output.Length = 0;
            }
            count++;
        }
        i++;
    }

    if (count <= idx) {
        output.Length = 0;
    }

    return output;
}
/* Mengambil kata berdasarkan indeks tertentu */

Word toKata(char *str) {
    Word kata;
    kata.Length = 0;
    while (*str != '\0' && kata.Length < NMax) {
        kata.TabWord[kata.Length++] = *str;
        str++;
    }
    return kata;
}
/* Mengubah string menjadi tipe Word */

boolean IsWordEqual(Word kata, char *string) {
    int i = 0;
    while (i < kata.Length && string[i] != '\0') {
        if (kata.TabWord[i] != string[i]) {
            return false;
        }
        i++;
    }
    return (i == kata.Length && string[i] == '\0');
}
/* Mengecek apakah sebuah Word sama dengan string */

boolean IsWordNumber(Word kata) {
    int i = 0;

    while (i < kata.Length) {
        if (kata.TabWord[i] < '0' || kata.TabWord[i] > '9') {
            return false;
        }
        i++;
    }

    return (kata.Length > 0);
}
/* Mengecek apakah Word merupakan angka */

void PrintWord(Word kata) {
    for (int i = 0; i < kata.Length; i++) {
        printf("%c", kata.TabWord[i]);
    }
}
/* Mencetak Word*/

Word IntToWord(int n) {
    Word kata;
    kata.Length = 0;

    if (n == 0) {
        kata.TabWord[kata.Length++] = '0';
    } else {
        while (n > 0) {
            int sisa = n % 10;
            n /= 10;

            for (int k = kata.Length; k > 0; k--) {
                kata.TabWord[k] = kata.TabWord[k - 1];
            }

            kata.TabWord[0] = sisa + '0';
            kata.Length++;
        }
    }

    return kata;
}
/* Mengubah integer menjadi Word */

int WordToInt(Word kata) {
    int result = 0;

    for (int i = 0; i < kata.Length; i++) {
        result = result * 10 + (kata.TabWord[i] - '0');
    }

    return result;
}
/* Mengubah Word menjadi integer */