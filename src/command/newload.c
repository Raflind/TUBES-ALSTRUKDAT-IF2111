#include <stdio.h>
#include "../ADT/user.h"
#include "../ADT/barang.h"
#include "../ADT/listbarang.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

int NewLoadr(ListUser *listuser, ListBarang *listbarang){
 char filename[100];
 char filepath[200];
 printf(">> LOAD: ");
 StartWord();
 CopyWordToString(filename);
 printf("\n");
 snprintf(filepath, sizeof(filepath), "saves/%s.txt", filename);
 StartFile(filepath);
 if (IsEOP()){
  printf("Savefile gagal dibuka. Silahkan masukkan nama file yang benar.\n");
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
  //printf("%d ", rando.money);
  //printf("\n");
  IgnoreBlanks();
  CopyWord();
  int x = WordToInt(currentWord);
  int totpric;
  int totitem;
  CreateEmptyStack(&rando.riwayat_pembelian);
  /*printf("\n ************* \n");
  PrintStackHistory(rando.riwayat_pembelian, 3);
  printf("\n ************* \n");*/
  infotype pb;
  for(int j=1;j<=x;j++){
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
    for(int k=0;k<totitem;k++){
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
      char barangname[MAX_LEN];
      CopyWordToString(barangname);
      string_copy(pb.cart[k].Barang.name, barangname);
      /*for(int l=0;l<bruh;l++){
        if(j==3){
          printf("%c [yea] ", currentWord.contents[l]);
        }
      }*/
      pb.cart[k].Barang.price = (itemprice/itemquant);
    }
    Push(&rando.riwayat_pembelian, pb);
  }
  IgnoreBlanks();
  CopyWord();
  x = WordToInt(currentWord);
  CreateList(&rando.wishlist);
  for(int j=1;j<=x;j++){
   IgnoreBlanks();
   StartWords();
   char wishitem[MAX_LEN];
   CopyWordToString(wishitem);
   //insertLast(&rando.wishlist, wishitem);
   if(j==1){
    insertFirst(&rando.wishlist, wishitem);
   }
   else{
    insertLast(&rando.wishlist, wishitem);
   }
  }
  //printList(rando.wishlist);
  AddUser(listuser, rando);
  for(int j=0;j<tempu;j++){
   //printf("%c", rando.name[j]);
   rando.name[j] = '\0';
  }
  //printf(" ");
  for(int j=0;j<tempa;j++){
   //printf("%c", rando.password[j]);
   rando.password[j] = '\0';
  }
 }
 CloseFile();
 printf("PURRMART berhasil di-start\n");
 return 2;
}