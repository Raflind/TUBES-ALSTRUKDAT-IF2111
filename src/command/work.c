#include "../ADT/worklist/worklist.h"
#include "../ADT/user/user.h"
#include "work.h"
#include <stdio.h>
#include <time.h>

void delay(int second){
    clock_t start_time = clock();
    clock_t end_time = start_time + second * CLOCKS_PER_SEC;
    while(clock() < end_time);
}

void UserWorks(WorksList *W, User *user){
    DisplayWorks(*W);
    printf("Masukkan pekerjaan yang dipilih : ");
    START();
    StartWords();
    char selectwork[MAX_LEN];
    CopyWordToString(selectwork);

    Word selectedwork;

    char currchar = 'z';
    int rand = -1;
    while(currchar != '\0'){
        rand++;
        currchar = selectwork[rand];
        if(currchar == '\0'){
            selectedwork.contents[rand] = currchar;
            selectedwork.length = rand;
            break;
        }
        else{
            selectedwork.contents[rand] = currchar;
        }
    }

    if(IsWorkExist(W, selectedwork)){
        int idx = Getidx(W, selectedwork);
        printf("Anda sedang bekerja sebagai %s... harap tunggu\n ", selectedwork.contents);
        delay(W->buffer[idx].delay);
        printf("pekerjaan selesai, +%d rupiah telah ditambahkan ke akun anda\n", W->buffer[idx].salary);
        user->money += W->buffer[idx].salary;
    }
    else{
        printf("Pekerjaan yang anda pilih tidak ada!\n");
    }

}


