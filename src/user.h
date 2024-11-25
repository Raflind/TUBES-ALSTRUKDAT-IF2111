#ifndef LISTUSER_H
#define LISTUSER_H

#include <stdio.h>
#include "boolean.h"

#define MAX_USERS 100
#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

typedef struct {
    User buffer[MAX_USERS];
    int nEff;
} ListUser;

void CreateListUser(ListUser *list);
boolean IsUserExist(ListUser *list, char *username);
void AddUser(ListUser *list, User newUser);
User *FindUser(ListUser *list, char *username);

#endif