#include "mesinkarakter.h"
#include "mesinkata.h"
#include "tebakangka.h"
#include "boolean.h"
#include "ADT/user.h"
#include <time.h>

void CreateAnswerTebakAngka(AnswerTebakAngka *Ans){
    Ans->Neff = 0;
}

boolean IsAnswerFull(AnswerTebakAngka *Ans){
    return (Ans->Neff == MAX_ELMT);
}

void AddAnswer(AnswerTebakAngka *Ans, int x){
    if(!IsAnswerFull(Ans)){
        Ans->ans[Ans->Neff] = x;
        Ans->Neff++;
    }
}

int RandomizeAnswer(AnswerTebakAngka *Ans){
    int i = clock() % Ans->Neff;
    return Ans->ans[i];
}

void ChallengeTebakAngka(AnswerTebakAngka *Ans, User *user){
    int answer = RandomizeAnswer(Ans);
    user->money -= 50;
    printf("Tebak Angka: ");
    START();
    StartWord();
    int useranswer = WordToInt(currentWord);

    int i = 1;
    while(i < 10 && useranswer != answer){
        printf("Tebak Angka: ");
        StartWord();
        useranswer = WordToInt(currentWord);
        if(useranswer > answer){
            printf("Tebakanmu lebih besar!\n");
        }
        else if(useranswer < answer){
            printf("Tebakanmu lebih kecil\n");
        }
        i++;
    }

    if(useranswer == answer){
        printf("Selamat and mendapatkan %d rupiah\n", 505 -(50*i));
        user->money += 505 - (50*i);
    }
    else{
        printf("Kesempatanmu untuk menjawab telah habis!");
    }
}
