#include <stdio.h>
#include "user.h"
#include "listbarang.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

void LoadFile(ListUser *listuser, ListBarang *listbarang){
  printf(">> LOAD: \n");
  START();
  StartWord();
  char filename[100];
  CopyWordToString(filename);
  char filepath[200];
  snprintf(filepath, sizeof(filepath), "datas/%s", filename);
  FILE *file = fopen(filepath, "r");
  if(file){
    StartWord();
    int n;

    printf("%d\n", n);
    printf("Savefile %s telah dibaca. PURRMART berhasil dijalankan.", filename);
    fclose(file);
  }
  else{
    printf("Savefile gagal dibaca. Silahkan masukkan ulang savefile yang benar jika ada.", filename);
  }
}