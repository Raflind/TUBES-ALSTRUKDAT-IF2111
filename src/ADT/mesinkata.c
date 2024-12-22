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

void remainderWordalter(char *s1, char *s2) {
    if (IsSameFirstWord(s1, s2)) {
        int selisih = (strlent(s1) - strlent(s2) - 1);
        for (int i = 0; i < selisih; i++){
            s1[i] = s1[(i + strlent(s2) + 1)];
        }
        s1[(strlent(s1) - strlent(s2) - 1)] = '\0';
    }
}

void splitString(char *input, char *str1, char *str2) {
    int i = 0;
    int j = 0;
    
    while (input[i] != ' ' && input[i] != '\0') {
        str1[i] = input[i];
        i++;
    }
    str1[i] = '\0';
    
    if (input[i] == ' ') {
        i++;
    }
    
    while (input[i] != '\0') {
        str2[j] = input[i];
        i++;
        j++;
    }
    str2[j] = '\0';
}

int stringToInt(char *str) {
    int result = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
        i++;
    }
    
    return result;
}

boolean stringIsNum(char *str) {
    if (str[0] == '\0') {
        return false;
    }
    
    int i = 0;
    
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
        i++;
    }
    
    return true;
}

boolean isValidForSplit(char *input) {
    int i = 0;
    boolean foundFirstWord = false;
    boolean foundSpace = false;
    boolean foundSecondWord = false;
    
    if (input == NULL || input[0] == '\0') {
        return false;
    }
    
    if (input[0] == ' ') {
        return false;
    }
    
    while (input[i] != '\0' && !foundSpace) {
        if (input[i] == ' ') {
            foundSpace = true;
        }
        i++;
    }
    
    if (!foundSpace) {
        return false;
    }
    
    while (input[i] == ' ') {
        i++;
    }
    
    if (input[i] == '\0') {
        return false;
    }
    
    while (input[i] != '\0' && input[i] != ' ') {
        foundSecondWord = true;
        i++;
    }
    
    while (input[i] != '\0') {
        if (input[i] != ' ') {
            return false;
        }
        i++;
    }
    return foundSpace && foundSecondWord;
}

boolean isThereBlank(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            return true;
        }
        i++;
    }
    return false;
}

void remainderWord(char *s1, char *s2){
    int length = strlent(s2);
    if (IsSameFirstWord(s1, s2)){
        int selisih = (strlent(s1) - strlent(s2) - 1);
        for (int i = 0; i < selisih; i++){
            s1[i] = s1[(i + length + 1)];
        }
        s1[(strlent(s1) - strlent(s2) - 1)] = '\0';
    }
    
}

int copyFirstWord(char *s1, char *s2){
    int length = strlent(s1);
    int spaceidx = -1;
    for (int i = 0; i < length; i++){
        if (s1[i] == ' '){
            spaceidx = i;
        }
    }
    if (spaceidx != -1){
        for (int j = 0; j < length; j++){
            if (j < spaceidx){
                s2[j] = s1[j];
            }
            else if ( j > spaceidx){
                s1[j - spaceidx - 1] = s1[j]; 
            }
        }
        s2[spaceidx] = '\0';
        s1[length - spaceidx - 1] = '\0';
    }

    return spaceidx;
}

int stringToINt(char *s1){
    int i = 0;
    int num = 0;
    while (s1[i] != '\0'){
        if (s1[i] < '0' || s1[i] > '9'){
            printf("Input digit angka invalid!\n");
            return -1;
        }
        else{
            num = num * 10 + (s1[i] - '0');
        }
        i++;
        
    }
    return num;
}

int splitStringInt(char *s1, char *s2) {
    int i = 0;
    int lastSpaceidx = -1;
    int num;

    while (s1[i] != '\0'){
        if (s1[i] == ' '){
            lastSpaceidx = i;
        }
        i++;
    }
    
    if (lastSpaceidx == -1){
        printf("Tidak ada spasi di dalam string!\n");
        return -1;
    }

    char numToSplit[MAX_WORD_LENGTH];
    int k = 0;
    for (int j = lastSpaceidx + 1; j < i; j++){
        numToSplit[k++] = s1[j];
    }
    numToSplit[k] = '\0';

    if (stringIsNum(numToSplit)){
        num = stringToInt(numToSplit);
        for (int j = 0; j < lastSpaceidx; j++){
            s2[j] = s1[j];
        }
        s2[lastSpaceidx] = '\0';
    } 
    else{
        printf("Input digit angka invalid!\n");
        num = -1;
    }

    return num;
}