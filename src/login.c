#include <stdio.h>
#include "user.h"
#include "mesinkata.h"

int LoginUser(ListUser *list, User *activeUser) {
    if (activeUser->name[0] != '\0') {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", activeUser->name);
        return 0;
    }

    printf(">> LOGIN\n");
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
        if (IsWordEqual(username2, list->buffer[i].name) && 
            IsWordEqual(password2, list->buffer[i].password)) {
            *activeUser = list->buffer[i];
            printf("\nAnda telah login ke PURRMART sebagai %s.\n", activeUser->name);
            return 1;
        }
    }

    printf("\nUsername atau password salah.\n");
    return 0;
}
