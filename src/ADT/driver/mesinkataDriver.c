#include <stdio.h>
#include "mesinkata.h"

int main(){
    StartWord();
    printf("Input: %s\n", currentWord.contents);

    AdvanceWord();
    printf("Next Word: %s\n", currentWord.contents);

    char str[MAX_WORD_LENGTH];
    CopyWordToString(str);
    printf("CopyWordToString: %s\n", str);

    if(IsWordEqual(currentWord, "LMAO")){
        printf("%s sama dengan LMAO\n", currentWord.contents);
    }
    else{
        printf("%s tidak sama dengan LMAO\n", currentWord.contents);
    }

    if(IsWordNumber(currentWord)){
        printf("'%s' adalah angka\n", currentWord.contents);
    }
    else{
        printf("'%s' bukan angka\n", currentWord.contents);
    }

    if(IsWordNumber(currentWord)){
        int number = WordToInt(currentWord);
        printf("%s adalah integer: %d\n", currentWord.contents, number);
    }
    else{
        printf("%s bukan integer\n", currentWord.contents);
    }

    if(wordContainsBlank(currentWord)){
        printf("%s mengandung Blank\n", currentWord.contents);
    }
    else{
        printf("%s tidak mengandung Blank\n", currentWord.contents);
    }

    Word kata = {"BEBEK", 5};
    if(IsSameWord(currentWord, kata)){
        printf("%s sama dengan BEBEK\n", currentWord.contents);
    }
    else{
        printf("%s tidak sama dengan BEBEK\n", currentWord.contents);
    }

    char destination[MAX_WORD_LENGTH];
    string_copy(destination, currentWord.contents);
    printf("String yang disalin: %s\n", destination);

    int len = strlent(currentWord.contents);
    printf("Panjang string %s: %d\n", currentWord.contents, len);

    char compareString[] = "bebek";
    int compared = string_compare(currentWord.contents, compareString);
    printf("Perbandingan dengan %s: %d\n", compareString, compared);

    char str1[MAX_WORD_LENGTH], str2[MAX_WORD_LENGTH];
    splitString(currentWord.contents, str1, str2);
    printf("Split: str1 = %s, str2 = %s\n", str1, str2);

    if(IsSameFirstWord(currentWord.contents, "BE")){
        printf("%s memiliki kata pertama yang sama dengan BE\n", currentWord.contents);
    }
    else{
        printf("%s tidak memiliki kata pertama yang sama dengan BE\n", currentWord.contents);
    }

    char testString1[MAX_WORD_LENGTH] = "BEBEK makan nasi";
    remainderWordalter(testString1, "BEBEK");
    printf("Sisa kata setelah alter: %s\n", testString1);

    if(isValidForSplit(currentWord.contents)){
        printf("%s valid untuk dipisah\n", currentWord.contents);
    } 
    else{
        printf("%s tidak valid untuk dipisah\n", currentWord.contents);
    }

    if(isThereBlank(currentWord.contents)){
        printf("%s mengandung spasi/tab\n", currentWord.contents);
    }
    else{
        printf("%s tidak mengandung spasi/tab\n", currentWord.contents);
    }

    char testString2[MAX_WORD_LENGTH] = "BEBEK makan nasi";
    remainderWord(testString2, "BEBEK");
    printf("Sisa kata: %s\n", testString2);

    char firstWord[MAX_WORD_LENGTH];
    char remaining[MAX_WORD_LENGTH];
    copyFirstWord("BEBEK makan nasi", firstWord);
    printf("Kata pertama: %s\n", firstWord);

    char testString3[MAX_WORD_LENGTH] = "BEBEK 123";
    char splitStr[MAX_WORD_LENGTH];
    int splitInt = splitStringInt(testString3, splitStr);
    printf("Split string: %s, Split integer: %d\n", splitStr, splitInt);

    return 0;
}