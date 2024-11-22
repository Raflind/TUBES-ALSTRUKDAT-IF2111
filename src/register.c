#include <stdio.h>
#include "user.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

void RegisterUser(ListUser *list) {
    printf(">> REGISTER\n");

    printf("Username: ");
    START();
    StartWord();
    char username[MAX_LEN];
    CopyWordToString(username);

    printf("Password: ");
    StartWord();
    char password[MAX_LEN];
    CopyWordToString(password);

    Word username2;
    Word password2;

    char currchar = 'z';
    int rand = -1;
    while(currchar != '\0'){
        rand++;
        currchar = username[rand];
        if(currchar == '\0'){
            username2.contents[rand] = currchar;
            username2.length = rand;
            break;
        }
        else{
            username2.contents[rand] = currchar;
        }
    }

    currchar = 'z';
    rand = -1;
    while(currchar != '\0'){
        rand++;
        currchar = password[rand];
        if(currchar == '\0'){
            password2.contents[rand] = currchar;
            password2.length = rand;
            break;
        }
        else{
            password2.contents[rand] = currchar;
        }
    }


    for (int i = 0; i < list->nEff; i++) {
        if (IsWordEqual(username2, list->buffer[i].name)) {
            printf("\nAkun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
            return;
        }
    }

    User newUser;
    rand = -1;
    for (int i = 0; username[i] != '\0'; i++) {
        rand++;
        newUser.name[i] = username[i];
    }
    newUser.name[rand+1] = '\0';

    rand = -1;
    for (int i = 0; password[i] != '\0'; i++) {
        rand++;
        newUser.password[i] = password[i];
    }
    newUser.password[rand+1] = '\0';

    newUser.money = 1000;
    list->buffer[list->nEff++] = newUser;
    printf("\nAkun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
}
