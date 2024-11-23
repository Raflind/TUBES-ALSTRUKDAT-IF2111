#include "works.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "user.h"
#include <stdio.h>
#include <time.h>
void CreateEmptyWorkList(WorksList *W){
    W->Neff = 0;
}

void delay(int second){
    clock_t start_time = clock();
    clock_t end_time = start_time + second * CLOCKS_PER_SEC;
    while(clock() < end_time);
}

int Getidx(WorksList *W, Word word){
    if(IsWorkExist(W, word)){
        for(int i = 0; i < W->Neff; i++){
            if(IsWordEqual(word, W->buffer[i].workname)){
                return i;
            }
        }
    }
    return undefined;
}

boolean IsWorkExist(WorksList *W, Word word){
    for(int i = 0; i < W->Neff; i++){
        if((IsWordEqual(word, W->buffer[i].workname))){
            return true;
        }
    }
    return false;
}

void RegisterWork(WorksList *W) {
    printf("Menambah Works\n");

    printf("Nama Pekerjaan: ");
    START();
    StartWord();
    char name[MAX_LEN];
    CopyWordToString(name);

    printf("Salary: ");
    StartWord();
    int salary = WordToInt(currentWord);

    printf("Waktu bekerja: ");
    StartWord();
    int delay = WordToInt(currentWord);

    Word workname;

    char currchar = 'z';
    int rand = -1;
    while(currchar != '\0'){
        rand++;
        currchar = name[rand];
        if(currchar == '\0'){
            workname.contents[rand] = currchar;
            workname.length = rand;
            break;
        }
        else{
            workname.contents[rand] = currchar;
        }
    }

    if(IsWorkExist(W, workname)){
        printf("Pekerjaan sudah terdaftar\n");
        return;
    }

    Works NewWork;
    rand = -1;
    for (int i = 0; name[i] != '\0'; i++) {
        rand++;
        NewWork.workname[i] = name[i];
    }
    NewWork.workname[rand+1] = '\0';

    NewWork.salary = salary;
    NewWork.delay = delay;
    W->buffer[W->Neff] = NewWork;
    W->Neff++;
    printf("\nPekerjaan %s berhasil ditambahkan.\n", name);
}

Works AddWork(WorksList *W, Works NewWorks){
    if (W->Neff < MAX_WORKS) {
        W->buffer[W->Neff] = NewWorks;
        W->Neff++;
    }
}

void DisplayWorks(WorksList W){
    printf("Daftar Pekerjaan: \n");
    for(int i = 0; i < W.Neff ; i++){
        printf("%d. %s (pendapatan=%d, durasi=%d)\n", i+1, W.buffer[i].workname, W.buffer[i].salary, W.buffer[i].delay);
    }
}

void UserWorks(WorksList *W, User *user){
    DisplayWorks(*W);
    printf("Masukkan pekerjaan yang dipilih : ");
    START();
    StartWord();
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
        printf("Pekerjaan yang anda pilih tidak ada!");
    }

}

int main(){
    Works work;
    WorksList worklist;
    CreateEmptyWorkList(&worklist);
    DisplayWorks(worklist);
    RegisterWork(&worklist);
    DisplayWorks(worklist);
    return 0;
}


