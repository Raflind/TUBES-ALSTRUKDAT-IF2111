#include <stdio.h>
#include "../ADT/user.h"

void LogoutUser(User *activeUser) {
    if (activeUser->name[0] == '\0') {
        printf("Tidak ada akun yang sedang login.\n");
        return;
    }

    printf("Anda telah LOGOUT dari akun %s.\n", activeUser->name);

    activeUser->name[0] = '\0';
    activeUser->password[0] = '\0';
    activeUser->money = 0;
}
