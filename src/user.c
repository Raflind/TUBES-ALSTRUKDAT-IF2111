#include "user.h"

void CreateListUser(ListUser *list) {
    list->nEff = 0;
}

boolean IsUserExist(ListUser *list, char *username) {
    for (int i = 0; i < list->nEff; i++) {
        int j = 0;
        while (username[j] != '\0' && list->buffer[i].name[j] != '\0' && username[j] == list->buffer[i].name[j]) {
            j++;
        }
        if (username[j] == '\0' && list->buffer[i].name[j] == '\0') {
            return true;
        }
    }
    return false;
}

void AddUser(ListUser *list, User newUser) {
    if (list->nEff < MAX_USERS) {
        list->buffer[list->nEff] = newUser;
        list->nEff++;
    }
}

int FindUser(ListUser *list, char *username) {
    for (int i = 0; i < list->nEff; i++) {
        int j = 0;
        while (username[j] != '\0' && list->buffer[i].name[j] != '\0' && username[j] == list->buffer[i].name[j]) {
            j++;
        }
        if (username[j] == '\0' && list->buffer[i].name[j] == '\0') {
            return i;
        }
    }
    return -1;
}