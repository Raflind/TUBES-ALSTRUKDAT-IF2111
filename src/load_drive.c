#include <stdio.h>
#include "load.h"
#include "listbarang.h"
#include "user.h"

int main(){
  ListUser listuserz;
  ListBarang listbarangz;
  CreateListUser(&listuserz);
  InitializeListBarang(&listbarangz);
  LoadFile(&listuserz, &listbarangz);
  printf("\n");
  int tempi;
  for(int i=0; i<listuserz.nEff; i++){
    printf("%d ", listuserz.buffer[i].money);
    tempi = strlent(listuserz.buffer[i].name);
    for(int j=0; j<10; j++){
      printf("%c", listuserz.buffer[i].name[j]);
    }
    printf(" ");
    tempi = strlent(listuserz.buffer[i].password);
    for(int j=0; j<tempi; j++){
      printf("%c", listuserz.buffer[i].password[j]);
    }
    printf("\n");
  }
  printf("\n");
  for(int i=0; i<listbarangz.neff; i++){
    printf("%d ", listbarangz.buffer[i].price);
    tempi = strlent(listbarangz.buffer[i].name);
    for(int j=0; j<tempi; j++){
      printf("%c", listbarangz.buffer[i].name[j]);
    }
    printf("\n");
  }
}