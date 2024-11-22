#include <stdio.h>
#include "user.h"
#include "mesinkata.h"
#include "register.h"
#include "login.h"
#include "logout.h"

void ShowMenu() {
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Logout\n");
    printf("0. Exit\n");
    printf("Pilih menu: ");
}

int main() {
    ListUser userList;
    User activeUser;
    CreateListUser(&userList);

    activeUser.name[0] = '\0';
    int choice = -1;
    while (choice != 0){
        ShowMenu();
        scanf("%d", &choice);

        if (choice == 1) {
            RegisterUser(&userList);
        } else if (choice == 2) {
            LoginUser(&userList, &activeUser);
        } else if (choice == 3) {
            LogoutUser(&activeUser);
        } else if (choice == 0) {
            printf("Keluar dari program. Sampai jumpa!\n");
        } else {
            printf("Pilihan tidak valid. Coba lagi.\n");
        }
    }

    return 0;
}
