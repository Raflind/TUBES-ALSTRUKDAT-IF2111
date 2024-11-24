#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include "../tebakangka.h"
#include "../wordl3.h"
#include <stdio.h>
#include "workschallenge.h"

void ShowWorkChallenge(){
    printf("1. Tebak Angka (biaya main=50)\n");
    printf("2. Wordl3 (biaya main=100)\n");
}

void WorksChallenge(Wordl3List *wordl, User *user){
    ShowWorkChallenge();
    printf("Masukkan Challenge yang hendak dimainkan: ");
    START();
    StartWord();
    if(WordToInt(currentWord)==1){
        ChallengeTebakAngka(user);
    }
    else if(WordToInt(currentWord)==2){
        WordlChallenge(wordl, user)
    }
    else{
        printf("Input tidak valid.\n");
    }

}