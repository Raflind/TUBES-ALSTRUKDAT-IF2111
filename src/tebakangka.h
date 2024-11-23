#ifndef TEBAKANGKA_H
#define TEBAKANGKA_H

#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"
#include "ADT/user.h"
#include <time.h>

#define MAX_ELMT 10

typedef struct{
    int ans[MAX_ELMT];
    int Neff;
} AnswerTebakAngka;

void CreateAnswerTebakAngka(AnswerTebakAngka *Ans);

boolean IsAnswerFull(AnswerTebakAngka *Ans);

void AddAnswer(AnswerTebakAngka *Ans, int x);

int RandomizeAnswer(AnswerTebakAngka *Ans);

void ChallengeTebakAngka(AnswerTebakAngka *Ans, User *user);

#endif

