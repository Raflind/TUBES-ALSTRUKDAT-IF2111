#ifndef WORKS_H
#define WORKS_H

#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include <stdio.h>
#include <time.h>
#include "../ADT/user.h"


#define MAX_WORKS 20
#define MAX_LEN 100
#define undefined -999

typedef struct{
    char workname[MAX_LEN];
    int salary;
    int delay;
} Works;

typedef struct{
    Works buffer[MAX_WORKS];
    int Neff;
} WorksList;

void CreateEmptyWorkList(WorksList *W);

void delay(int second);

void RegisterWork(WorksList *W);

int Getidx(WorksList *W, Word word);

boolean IsWorkExist(WorksList *W, Word workname);

Works AddWork(WorksList *W, Works NewWorks);

void DisplayWorks(WorksList W);

void UserWorks(WorksList *W, User *user, ListUser *list);

void LoadWorkList(WorksList *W);


#endif


