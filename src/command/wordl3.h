#ifndef WORDL3_H
#define WORDL3_H

#define MAX_LENGTH 5
#define MAX_ELMT_WORDL 10
#define MAX_ATTEMPTS 5

#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include "../ADT/boolean.h"
#include "../ADT/user.h"
#include <time.h>

typedef struct{
    Word answer[MAX_ELMT_WORDL];
    int Neff;
} Wordl3List;

void CreateWordl3List(Wordl3List *wordl);

void AddWordlAnswer(Wordl3List *wordl);

void MakeUppercase(Word *answer);

void PlayWordl3(User *user, ListUser *list);

void CompareGuess(Word answer, Word secretWord, Word *marker);

void displayPreviousGuesses(Word results[], int attempts);

boolean IsAnswerValid(Word *answer);

#endif