#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord;
Word currentWord;

Word wordArray[MAX_WORDS];
int wordCount;
int currentWordIndex;

void IgnoreBlanks() {
    while (currentChar == BLANK || currentChar == NEWLINE) {
        ADV();
    }
}

void STARTWORD() {
    START(NULL); // Menggunakan stdin
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == EOF) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void STARTWORD_STDIN() {
    START_STDIN();
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == EOF) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == EOF) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK && currentChar != NEWLINE && i < NMax - 1 && currentChar != EOF) {
        currentWord.TabWord[i++] = currentChar;
        ADV();
    }
    currentWord.TabWord[i] = '\0';
    currentWord.Length = i;
}

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

void PrintWord(Word kata) {
    for (int i = 0; i < kata.Length; i++) {
        printf("%c", kata.TabWord[i]);
    }
}

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

int WordToInt(Word kata) {
    int result = 0;
    for (int i = 0; i < kata.Length; i++) {
        result = result * 10 + (kata.TabWord[i] - '0');
    }
    return result;
}


void STARTLINE() {
    /* Membaca satu baris penuh dari stdin */
    int i = 0;
    char c = getchar();
    while (c != '\n' && c != EOF && i < NMax - 1) {
        currentWord.TabWord[i++] = c;
        c = getchar();
    }
    currentWord.TabWord[i] = '\0';
    currentWord.Length = i;
    EndWord = false;
    wordCount = 0;
    currentWordIndex = 0;
}

void ParseLineToWords() {
    /* Memecah currentWord menjadi array of words */
    int i = 0;
    int k = 0;
    wordCount = 0;
    currentWordIndex = 0;
    while (currentWord.TabWord[i] != '\0') {
        if (currentWord.TabWord[i] == ' ') {
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
