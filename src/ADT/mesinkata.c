#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord;
Word currentWord;

/* Definisi Variabel Global */
Word wordArray[MAX_WORDS];
int wordCount;
int currentWordIndex;

void IgnoreBlanks() {
    while (currentChar == BLANK || currentChar == NEWLINE) {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK dan NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD() {
    START(NULL); // Menggunakan stdin
    IgnoreBlanks();
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
/* Sama seperti STARTWORD, tetapi pita berasal dari stdin */

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWord */

void CopyWord() {
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK && currentChar != NEWLINE && i < NMax - 1) {
        currentWord.TabWord[i++] = currentChar;
        ADV();
    }
    currentWord.TabWord[i] = '\0';
    currentWord.Length = i;
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


void ReadWord() {
    while (!IsEndWord()) {
        PrintWord(currentWord);
        printf("\n");
        ADVWORD();
    }
}


void GetWord(Word input, int idx) {
}

Word toKata(char *str) {
    Word kata;
    int i = 0;
    while (str[i] != '\0' && i < NMax - 1) {
        kata.TabWord[i] = str[i];
        i++;
    }
    kata.TabWord[i] = '\0';
    kata.Length = i;
    return kata;
}
/* Mengubah string menjadi tipe Word */

boolean IsWordString(Word kata, char *string) {
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

boolean IsWordEqual(Word kata1, Word kata2) {
    if (kata1.Length != kata2.Length) {
        return false;
    }
    for (int i = 0; i < kata1.Length; i++) {
        if (kata1.TabWord[i] != kata2.TabWord[i]) {
            return false;
        }
    }
    return true;
}
/* Mengecek apakah dua buah Word sama */

boolean IsWordNumber(Word kata) {
    int i = 0;
    if (kata.Length == 0) {
        return false;
    }
    while (i < kata.Length) {
        if (kata.TabWord[i] < '0' || kata.TabWord[i] > '9') {
            return false;
        }
        i++;
    }
    return true;
}
/* Mengecek apakah Word merupakan angka */

void PrintWord(Word kata) {
    for (int i = 0; i < kata.Length; i++) {
        printf("%c", kata.TabWord[i]);
    }
}
/* Mencetak Word */

Word IntToWord(int n) {
    Word kata;
    kata.Length = 0;
    if (n == 0) {
        kata.TabWord[kata.Length++] = '0';
    } else {
        char temp[NMax];
        int idx = 0;
        while (n > 0 && idx < NMax - 1) {
            temp[idx++] = (n % 10) + '0';
            n /= 10;
        }
        for (int i = idx - 1; i >= 0; i--) {
            kata.TabWord[kata.Length++] = temp[i];
        }
    }
    kata.TabWord[kata.Length] = '\0';
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


void STARTLINE() {
    /* Membaca satu baris penuh dari stdin */
    char line[NMax];
    if (fgets(line, sizeof(line), stdin) != NULL) {
        int i = 0;
        while (line[i] != '\0' && line[i] != '\n' && i < NMax - 1) {
            currentWord.TabWord[i] = line[i];
            i++;
        }
        currentWord.TabWord[i] = '\0';
        currentWord.Length = i;
        EndWord = false;
        wordCount = 0;
        currentWordIndex = 0;
    } else {
        EndWord = true;
    }
}

void ParseLineToWords() {
    /* Memecah currentWord menjadi array of words */
    int i = 0;
    int k = 0;
    wordCount = 0;
    currentWordIndex = 0;
    while (currentWord.TabWord[i] != '\0') {
        if (currentWord.TabWord[i] == ' ' || currentWord.TabWord[i] == '\n') {
            if (k > 0) {
                /* Simpan kata yang telah dibaca */
                wordArray[wordCount].TabWord[k] = '\0';
                wordArray[wordCount].Length = k;
                wordCount++;
                k = 0;
            }
            i++;
        } else {
            wordArray[wordCount].TabWord[k++] = currentWord.TabWord[i++];
        }
    }
    if (k > 0) {
        /* Simpan kata terakhir */
        wordArray[wordCount].TabWord[k] = '\0';
        wordArray[wordCount].Length = k;
        wordCount++;
    }
}

Word GetNextWord() {
    if (currentWordIndex < wordCount) {
        return wordArray[currentWordIndex++];
    } else {
        EndWord = true;
        Word emptyWord;
        emptyWord.Length = 0;
        emptyWord.TabWord[0] = '\0';
        return emptyWord;
    }
}