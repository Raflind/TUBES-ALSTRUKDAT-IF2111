#include <stdio.h>
#include "user.h"
#include "barang.h"
#include "listbarang.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

void LoadFile(ListUser *listuser, ListBarang *listbarang){
	char filename[100];
	char filepath[200];
	printf(">> LOAD: ");
	START();
	StartWord();
	CopyWordToString(filename);
	printf("\n");
	snprintf(filepath, sizeof(filepath), "../saves/%s.txt", filename);
	StartFile(filepath);
	if (IsEOP()) {
		printf("Savefile gagal dibuka. Silahkan masukkan nama file yang benar.\n");
		return;
	}
	IgnoreBlanks();
	CopyWord();
	int n = WordToInt(currentWord);
	listbarang->neff = n;
	//printf("n = %d\n", n);
	int pric;
	Barang baran;
	for (int i=0;i<n;i++) {
		IgnoreBlanks();
		StartWord();
		pric = WordToInt(currentWord);
		IgnoreBlanks();
		StartWord();
		int nameIdx = 0;
		for (int j=0;j<currentWord.length;j++) {
				baran.name[nameIdx++] = currentWord.contents[j];
		}
		baran.price = pric;
		/*printf("%d ", baran.price);
		for(int j=0;j<nameIdx;j++){
			printf("%c", baran.name[j]);
		}
		printf("\n");*/
		AddBarang(listbarang, baran);
		for(int j=0;j<nameIdx;j++){
				baran.name[j] = '\0';
		}
	}
	IgnoreBlanks();
	CopyWord();
	int m = WordToInt(currentWord);
	int moni;
	User rando;
	//printf("m = %d\n", m);
	for (int i=0;i<m;i++) {
		IgnoreBlanks();
		StartWord();
		moni = WordToInt(currentWord);
		rando.money = moni;
		IgnoreBlanks();
		StartWord();
		int nameIdx = 0;
		for (int j=0;j<currentWord.length;j++) {
				rando.name[nameIdx++] = currentWord.contents[j];
		}
		IgnoreBlanks();
		StartWord();
		int nameIdx2 = 0;
		for (int j=0;j<currentWord.length;j++) {
				rando.password[nameIdx2++] = currentWord.contents[j];
		}
		AddUser(listuser, rando);
		//printf("%d ", rando.money);
		for(int j=0;j<nameIdx;j++){
			//printf("%c", rando.name[j]);
			rando.name[j] = '\0';
		}
		//printf(" ");
		for(int j=0;j<nameIdx2;j++){
			//printf("%c", rando.password[j]);
			rando.password[j] = '\0';
		}
		//printf("\n");
	}
	CloseFile(); 
	printf("Savefile %s telah dibaca. PURRMART berhasil dijalankan.\n", filename);
}