#include "worklist.h"
#include <stdio.h>

void CreateEmptyWorkList(WorksList *W){
    W->Neff = 0;
}

void LoadWorkList(WorksList *W){
    CreateEmptyWorkList(W);
    Works work;
    char *works[] = {"Manager", "Sedot WC", "Kasir", "Supplier"};
    int salary[] = {100, 50, 70, 80};
    int delay[] = {10, 5, 7, 8};
    for(int i = 0;i < 4;i++){
        string_copy(work.workname, works[i]);
        work.salary = salary[i];
        work.delay = delay[i];
        AddWork(W, work);
    }
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

void AddWork(WorksList *W, Works NewWorks){
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
