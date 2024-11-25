#ifndef WORKSLIST_H
#define WORKSLIST_H

#include "../mesinkarakter/mesinkarakter.h"
#include "../mesinkata/mesinkata.h"
#include <stdio.h>
#include "../boolean.h"


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
/* Membuat list kosong dengan Neff = 0 */

int Getidx(WorksList *W, Word word);
/* Mengembalikan nilai index dari word.contents di WorkList, jika tidak ada mengembalikan nilai undefined */

boolean IsWorkExist(WorksList *W, Word workname);
/* Mengembalikan true jika ada workname di WorkList */

void AddWork(WorksList *W, Works NewWorks);
/* Menambahkan NewWorks ke dalam WorkList */

void DisplayWorks(WorksList W);
/* Menampilkan daftar Worklist */


#endif


