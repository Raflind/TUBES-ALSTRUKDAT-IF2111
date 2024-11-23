#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include "../tebakangka.h"
#include <stdio.h>
#include "workschallenge.h"

void ShowWorkChallenge(){
    printf("1. Tebak Angka (biaya main=100)\n");
    printf("2. Wordl3 (biaya main=50)\n");
}

void WorksChallenge(AnswerTebakAngka *Ans, User *user){
    ShowWorkChallenge();
    printf("Masukkan Challenge yang hendak dimainkan: ");
    START();
    StartWord();
    if(WordToInt(currentWord)==1){
        ChallengeTebakAngka(Ans, user);
    }
    else{
        printf("Input tidak valid.\n");
    }

}