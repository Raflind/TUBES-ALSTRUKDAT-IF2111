#include "mesinkata.h"

Word currentWord;

void IgnoreBlanks() {
    while (!IsEOP() && (currentChar == ' ' || currentChar == '\t' || currentChar == '\n')) {
        ADV();
    }
}

void StartWord() {
    IgnoreBlanks();
    if (!IsEOP()) {
        CopyWord();
    } else {
        currentWord.length = 0;
    }
}

void AdvanceWord() {
    IgnoreBlanks();
    if (!IsEOP()) {
        CopyWord();
    } else {
        currentWord.length = 0;
    }
}

void CopyWord() {
    int i = 0;
    while (!IsEOP() && currentChar != ' ' && currentChar != '\t' && currentChar != '\n' && i < MAX_WORD_LENGTH - 1) {
        currentWord.contents[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.contents[i] = '\0';
    currentWord.length = i;
}

int IsWordEqual(Word word, char *string) {
    int i = 0;
    while (i < word.length && string[i] != '\0') {
        if (word.contents[i] != string[i]) {
            return 0;
        }
        i++;
    }
    return (i == word.length && string[i] == '\0');
}

void CopyWordToString(char *destination) {
    int i;
    for (i = 0; i < currentWord.length; i++) {
        destination[i] = currentWord.contents[i];
    }
    destination[i] = '\0';
}

void ReadLine() {
    int i = 0;
    while (!IsEOP() && currentChar != '\n' && i < MAX_WORD_LENGTH - 1) {
        currentWord.contents[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.contents[i] = '\0';
    currentWord.length = i;
    /* Jika currentChar adalah newline, kita harus ADV sekali lagi untuk mengkonsumsi newline */
    if (currentChar == '\n') {
        ADV();
    }
}

int IsWordNumber(Word word) {
    int i = 0;
    if (word.length == 0) {
        return 0;
    }
    while (i < word.length) {
        if (word.contents[i] < '0' || word.contents[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

int WordToInt(Word word) {
    int result = 0;
    int i;
    for (i = 0; i < word.length; i++) {
        result = result * 10 + (word.contents[i] - '0');
    }
    return result;
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