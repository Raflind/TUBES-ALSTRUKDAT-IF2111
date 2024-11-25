#ifndef WORK_H
#define WORK_H

#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/user/user.h"
#include "../ADT/worklist/worklist.h"
#include <stdio.h>


#define MAX_WORKS 20
#define MAX_LEN 100
#define undefined -999

void delay(int second);
/* Prosedur untuk melakukan sleep selama second yang ditentukan */

void UserWorks(WorksList *W, User *user);
/* Prosedur untuk melakukan work */

void LoadWorkList(WorksList *W);
/* Prosedur untuk mengisi WorkList dengan Work yang sudah ditentukan */


#endif


