#include <stdio.h>
#include "user.h"
#include "barang.h"
#include "listbarang.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

int NewStartr(ListUser *listuser, ListBarang *listbarang, Stack *stackhistory){
 char filepath[200];
 snprintf(filepath, sizeof(filepath), "../saves/file_konfig.txt");
 StartFile(filepath);
 if (IsEOP()){
  printf("PURRMART gagal di-start. You're cooked.\n");
  return 1;
 }
 IgnoreBlanks();
 CopyWord();
 int n = WordToInt(currentWord);
 int pric;
 Barang baran;
 for(int i=0; i<100; i++){
	baran.name[i] = '\0';
 }
 for (int i=0;i<n;i++){
  IgnoreBlanks();
  StartWord();
  pric = WordToInt(currentWord);
  IgnoreBlanks();
  StartWords();
	int tempo = currentWord.length;
  for (int j=0;j<tempo;j++){
    baran.name[j] = currentWord.contents[j];
  }
  baran.price = pric;
  /*printf("%d ", baran.price);
  for(int j=0;j<nameIdx;j++){
   printf("%c", baran.name[j]);
  }
  printf("\n");*/
  AddBarang(listbarang, baran);
  for(int j=0;j<tempo;j++){
    baran.name[j] = '\0';
  }
 }
 IgnoreBlanks();
 CopyWord();
 int m = WordToInt(currentWord);
 int moni;
 User rando;
 for(int i=0; i<100; i++){
	rando.name[i] = '\0';
 }
 for(int i=0; i<100; i++){
	rando.password[i] = '\0';
 }
 //printf("m = %d\n", m);
 for (int i=0;i<m;i++){
  IgnoreBlanks();
  StartWord();
  moni = WordToInt(currentWord);
  rando.money = moni;
  IgnoreBlanks();
  StartWord();
  int tempu = currentWord.length;
  for (int j=0;j<tempu;j++){
    rando.name[j] = currentWord.contents[j];
  }
  IgnoreBlanks();
  StartWord();
  int tempa = currentWord.length;
  for (int j=0;j<tempa;j++){
    rando.password[j] = currentWord.contents[j];
  }
  AddUser(listuser, rando);
  //printf("%d ", rando.money);
  for(int j=0;j<tempu;j++){
   //printf("%c", rando.name[j]);
   rando.name[j] = '\0';
  }
  //printf(" ");
  for(int j=0;j<tempa;j++){
   //printf("%c", rando.password[j]);
   rando.password[j] = '\0';
  }
  //printf("\n");
  IgnoreBlanks();
  CopyWord();
  int x = WordToInt(currentWord);
  int totpric;
  int totitem;
  for(int j=1;j<=x;j++){
    Pembelian pb;
    pb.id = j;
    IgnoreBlanks();
    StartWord();
    totitem = WordToInt(currentWord);
    pb.jumlah_barang = totitem;
    IgnoreBlanks();
    StartWord();
    totpric = WordToInt(currentWord);
    pb.total = totpric;
    int itemprice;
    int itemquant;
    for(int k=1;k<=totitem;k++){
      IgnoreBlanks();
      StartWord();
      itemprice = WordToInt(currentWord);
      IgnoreBlanks();
      StartWord();
      itemquant = WordToInt(currentWord);
      pb.cart[k].total = itemprice;
      pb.cart[k].Kuantitas = itemquant;
      IgnoreBlanks();
      StartWords();
      int bruh = currentWord.length;
      for (int l=0;l<bruh;l++){
        pb.cart[k].Barang.name[l] = currentWord.contents[l];
      }
      pb.cart[k].Barang.price = (itemprice/itemquant);
    }
    Push(stackhistory, pb);
  }
 }
 CloseFile(); 
 printf("PURRMART berhasil di-start\n");
 return 2;
}