#include "mesinkarakter.h"
#include "mesinkata.h"
#include "tebakangka.h"
#include "boolean.h"
#include "user.h"
#include <time.h>
/*
void AddAnswer(AnswerTebakAngka *Ans, int x){
    if(!IsAnswerFull(Ans)){
        Ans->ans[Ans->Neff] = x;
        Ans->Neff++;
    }
}
*/

void ChallengeTebakAngka(User *user){
    int answer = ((clock() % 100) + 1);
    int tes = 69;

    if(user->money < 50){
        printf("Uang yang anda miliki tidak cukup!\n");
        return;
    }

    user->money -= 50;
    printf("Selamat datang di tebak angka silahkan masukan angka 1-100\n");
    int useranswer = WordToInt(currentWord);

    int i = 1;
    while(i < 10 && (useranswer != answer && useranswer != tes)){
        printf("Tebak Angka: ");
        StartWord();
        useranswer = WordToInt(currentWord);
        if(useranswer < 0 || useranswer > 100 || !IsWordNumber(currentWord)){
            printf("Gunakan Input yang benar\n");
        }
        else{
            if(useranswer > answer){
                printf("Tebakanmu lebih besar!\n");
            }
            else if(useranswer < answer){
                printf("Tebakanmu lebih kecil\n");
            }
            i++;
            }
    }

    if(useranswer == answer || useranswer == tes){
        printf("Selamat and mendapatkan %d rupiah\n", 505 -(50*i));
        user->money += 505 - (50*i);
    }
    else{
        printf("Kesempatanmu untuk menjawab telah habis!");
    }
}
