#include <stdio.h>
#include "save.h"

void save(ListUser *listuser, ListBarang *listbarang, char *filename) {
    char filepath[100] = "../../saves/";
    int i = 0;

    while (filename[i] != '\0') {
        filepath[9 + i] = filename[i];
        i++;
    }
    filepath[9 + i] = '\0';

    StartWriteFile(filepath);

    fprintf(pita, "%d\n", LengthList(*listbarang));
    for (i = 0; i < LengthList(*listbarang); i++) {
        fprintf(pita, "%s\n", listbarang->buffer[i].name);
        fprintf(pita, "%d\n", listbarang->buffer[i].price);
    }

    fprintf(pita, "%d\n", listuser->nEff);
    for (i = 0; i < listuser->nEff; i++) {
        fprintf(pita, "%d %s %s\n", listuser->buffer[i].money, listuser->buffer[i].name, listuser->buffer[i].password);
    }

    fprintf(pita, " ");  // Penutup file, jika diperlukan
    CloseFile();

    printf("Save file berhasil disimpan\n");
}

/*
/* I.S. store_list dan user_list terdefinisi, filename valid */
/* F.S. Data tersimpan dalam suatu file baru atau merewrite file yang sudah ada */