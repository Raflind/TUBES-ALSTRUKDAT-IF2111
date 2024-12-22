#include <stdio.h>
#include "../ADT/user.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

int LoginUser(ListUser *list, User *activeUser) {
    if (activeUser->name[0] != '\0') {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", activeUser->name);
        return 0;
    }

    printf(">> LOGIN\n");
    int inputUsername = 1;
    char username[MAX_LEN];
    while (inputUsername){
        printf("Username: ");
        StartWords();
        CopyWordToString(username);
        if (wordContainsBlank(currentWord)){
            printf("Username hanya boleh 1 kata.\n");

        }
        else{
            inputUsername = 0;
        }
    }

    int inputPass = 1;
    char password[MAX_LEN];
    while (inputPass){
        printf("Password: ");
        StartWords();
        CopyWordToString(password);
        if (wordContainsBlank(currentWord)){
            printf("Password hanya boleh 1 kata.\n");

        }
        else{
            inputPass = 0;
        }
    }

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