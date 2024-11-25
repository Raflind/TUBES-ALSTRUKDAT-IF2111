#include <stdio.h>
#include "../mesinkata.h"

int main() {
    // Tes input
    StartWord();
    printf("Input: ");
    printf("%s", currentWord.contents);
    AdvanceWord;

    // Tes copyWordToString
    char str[MAX_WORD_LENGTH];
    for (int i = 0; i < currentWord.length; i++) {
        str[i] = currentWord.contents[i];
    }
    str[currentWord.length] = '\0';
    printf("CopyWordToString: %s\n", str);

    // Tes IsWordEqual
    if (IsWordEqual(currentWord, "LMAO")) {
        printf("%s sama dengan LMAO\n", currentWord.contents);
    } else {
        printf("%s tidak sama dengan LMAO\n", currentWord.contents);
    }

    // Tes IsWordNumber
    if (IsWordNumber(currentWord)) {
        printf("'%s' adalah angka\n", currentWord.contents);
    } else {
        printf("'%s' bukan angka\n", currentWord.contents);
    }

    // Tes WordToInt
    if (IsWordNumber(currentWord)) {
        int number = WordToInt(currentWord);
        printf("%s adalah integer: %d\n", currentWord.contents, number);
    } else {
        printf("%s bukan integer\n", currentWord.contents);
    }

    // Tes wordContainsBlank
    if (wordContainsBlank(currentWord)) {
        printf("%s mengandung Blank\n", currentWord.contents);
    } else {
        printf("%s tidak mengandung Blank\n", currentWord.contents);
    }

    // Tes IsSameWord
    Word kata = {"BEBEK", 7};
    if (IsSameWord(currentWord, kata)) {
        printf("%s sama dengan BEBEK\n", currentWord.contents);
    } else {
        printf("%s tidak sama dengan BEBEK\n", currentWord.contents);
    }

    // Tes string_copy
    char destination[MAX_WORD_LENGTH];
    string_copy(destination, currentWord.contents);
    printf("String yang disalin: %s\n", destination);

    // Tes strlent
    int len = strlent(currentWord.contents);
    printf("Panjang string %s: %d\n", currentWord.contents, len);

    // Tes string_compare
    char compareString[] = "bebek";
    int compared = string_compare(currentWord.contents, compareString);
    printf("Perbandingan dengan %s: %d\n", compareString, compared);

    return 0;
}