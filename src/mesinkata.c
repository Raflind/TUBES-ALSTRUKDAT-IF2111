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

void StartWords() {
    IgnoreBlanks();
    if (!IsEOP()) {
        CopyWords();
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

void CopyWords() {
    int i = 0;
    while (!IsEOP() && currentChar != '\t' && currentChar != '\n' && i < MAX_WORD_LENGTH - 1) {
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

int strlent(char *str){
    int len = 0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}

int wordContainsBlank(Word word){
    for (int i = 0; i < word.length; i++){
        if (word.contents[i] == ' ' || word.contents[i] == '\t'){
            return 1;
        }

    }
    return 0;
}

boolean IsSameWord(Word word1, Word word2){
    if(word1.length != word2.length){
        return false;
    }
    else{
        for(int i = 0; i < word1.length;i++){
            if(word1.contents[i] != word2.contents[i]){
                return false;
            }
        }
    }
    return true;
}

boolean IsSameFirstWord(char *s1, char *s2){
    for (int i = 0; i < strlent(s2); i ++){
        if (s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}

void remainderWord(char *s1, char *s2){
    if (IsSameFirstWord(s1, s2)){
        int selisih = (strlent(s1) - strlent(s2) - 1);
        for (int i = 0; i < selisih; i++){
            s1[i] = s1[(i + 5)];
        }
        s1[(strlent(s1) - strlent(s2) - 1)] = '\0';
    }
    
}