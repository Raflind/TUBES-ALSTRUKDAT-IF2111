#include <stdio.h>
#include "../user.h"

int main() {
    ListUser listuser;
    User user1, user2, user3;
    CreateListUser(&listuser);

    // Inisialisasi user
    User user1 = {"coklat", "coklat123", 100};
    User user2 = {"lapar", "lapar123", 100};
    User user3 = {"huweee", "nangisdah", 100};

    // Tes user exist atau tidak
    char username1[MAX_LEN] = "coklat";
    if (IsUserExist(&listuser, username1)) {
        printf("User %s ditemukan\n");
    } else {
        printf("User %s tidak ditemukan\n", username1);
    }
    printf("\n");

    // Tes inser user ke list
    AddUser(&listuser, user1);
    AddUser(&listuser, user2);
    AddUser(&listuser, user3);

    // Tes user exist atau tidak setelah insert
    char username2[MAX_LEN] = "lapar";
    if (IsUserExist(&listuser, username2)) {
        printf("User %s ditemukan\n");
    } else {
        printf("User %s tidak ditemukan\n", username2);
    }
    printf("\n");

    return 0;
    
}