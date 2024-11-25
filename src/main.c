#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "listbarang.h"
#include "queue.h"
#include "barang.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "boolean.h"
#include "help.h"
#include "load.h"
#include "login.h"
#include "logout.h"
#include "quit.h"
#include "register.h"
#include "save.h"
#include "start.h"
#include "user.h"
#include "wordl3.h"
#include "works.h"
#include "tebakangka.h"

int main(){
    ListBarang listbarang;
    Queue queue;
    ListUser userlist;
    User user;
    Works work;
    WorksList worklist;

    CreateEmptyWorkList(&worklist);
    LoadWorkList(&worklist);
    CreateListUser(&userlist);
    user.name[0] = '\0';
    InitializeListBarang(&listbarang);
    CreateQueue(&queue);

    
    printf("Selamat Datang di PURRMART, silahkan masukkan command (START, LOAD, HELP): \n");
    START();

    char input[MAX_WORD_LENGTH];
    int started = 1;
    while (started == 1){
        StartWords();
        CopyWordToString(input);
        if (string_compare(input, "START") == 0){
            if (Startr(&userlist, &listbarang) == 2){
                started = 0;
            }
        }
        else if (string_compare(input, "LOAD") == 0){
            if (LoadFile(&userlist, &listbarang) == 2){
                started = 0;
            }
        }
        else if (string_compare(input, "HELP") == 0){
            help_welcome();
        }
        else {
            printf("Command tidak dikenal. Masukkan HELP jika anda butuh bantuan. \n");
        }
    }
    int logged = 1;
    printf("Silahkan masukkan command (REGISTER, LOGIN, HELP): \n");
    while(logged){
        START();
        StartWords();
        CopyWordToString(input);

        if (string_compare(input, "REGISTER") == 0){
            RegisterUser(&userlist);
        }

        else if (string_compare(input, "LOGIN") == 0){
            if (LoginUser(&userlist, &user) == 1){
                int menu = 1;
                help_main();
                while (menu){
                    printf("Silahkan masukkan command: ");
                    START();
                    StartWords();
                    char inputmain[MAX_WORD_LENGTH];
                    CopyWordToString(inputmain);

                    if (string_compare(inputmain, "WORK") == 0){
                        UserWorks(&worklist, &user);
                    }

                    else if (string_compare(inputmain, "WORK CHALLENGE") == 0){
                        printf("Daftar challenge yang tersedia: \n");
                        printf("1. Tebak Angka (biaya main = 50) \n");
                        printf("2. W0RDL399 (biaya main = 50) \n");
                        printf("3. Quit Challenge. \n");

                        int inChallenge = 0;
                        while (!inChallenge){
                            printf("\nMasukan challenge yang hendak dimainkan :");

                            char inputChallenge[MAX_LEN];
                            START();
                            StartWords();
                            CopyWordToString(inputChallenge);

                            if (string_compare(inputChallenge, "1") == 0){
                                ChallengeTebakAngka(&user);
                                inChallenge = 1;
                            }

                            else if (string_compare(inputChallenge, "2") == 0){
                                PlayWordl3(&user);
                                inChallenge = 1;
                            }

                            else if (string_compare(inputChallenge, "3") == 0){
                                printf("Anda keluar dari challenge. \n");
                                inChallenge = 1;
                            }

                            else {
                                printf("Command tidak dikenal. \n");
                            }
                        }

                    }

                    else if (string_compare(inputmain, "STORE LIST") == 0){
                        display_store_list(listbarang);
                    }

                    else if (string_compare(inputmain, "STORE REQUEST") == 0){
                        store_request(listbarang, &queue);
                    }

                    else if (string_compare(inputmain, "STORE SUPPLY") == 0){
                        store_supply(&listbarang, &queue);
                    }

                    else if (string_compare(inputmain, "STORE REMOVE") == 0){
                        store_remove(&listbarang);
                    }

                    else if (string_compare(inputmain, "LOGOUT") == 0){
                        LogoutUser(&user);
                        menu = 0;

                    }

                    else if (remainderWord(inputmain, "SAVE")){
                        save(&userlist, &listbarang, inputmain);
                    }

                    else if (string_compare(inputmain, "QUIT") == 0){
                        quit(&queue, &userlist, &listbarang);
                        return 0;
                    }

                    else if (string_compare(inputmain, "HELP") == 0){
                        help_main();
                    }


                    else{
                        printf("Command tidak dikenal. \n");
                    }




                }
            }
            else{
                printf("Gagal untuk login. \n");
            }
        }

        else if (string_compare(input, "HELP") == 0){
            help_login();
        }

        else{
            printf("Command tidak dikenal. Masukkan HELP jika anda butuh bantuan. \n");
        }
    }
}

