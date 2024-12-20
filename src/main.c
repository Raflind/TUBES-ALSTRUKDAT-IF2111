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
#include "newstart.h"
#include "user.h"
#include "wordl3.h"
#include "works.h"
#include "tebakangka.h"
#include "profile.h"
#include "map.h"
#include "stackhistory.h"


int main(){
    printf("konto");
    ListBarang listbarang;
    Queue queue;
    ListUser userlist;
    User user;
    Works work;
    WorksList worklist;
    Stack stackhistory;
    Map map;
    List wishlist;

    CreateList(&wishlist);
    CreateEmpty(&map);
    CreateEmptyStack(&stackhistory);
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
            if (NewStartr(&userlist, &listbarang, &stackhistory) == 2){
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

                    else if (IsSameFirstWord(inputmain, "SAVE")){
                        remainderWord(inputmain, "SAVE");
                        if (strlent(inputmain) > 0 && string_compare(inputmain, "SAVE") != 0){
                            
                            save(&userlist, &listbarang, inputmain);
                        }
                        else{
                            printf("Nama file tidak boleh kosong. SAVE (namafile)\n");
                        }
                        
                    }

                    else if (string_compare(inputmain, "QUIT") == 0){
                        quit(&queue, &userlist, &listbarang);
                        return 0;
                    }

                    else if (string_compare(inputmain, "HELP") == 0){
                        help_main();
                    }   
                    else if (string_compare(inputmain, "PROFILE") == 0){
                        Profile(&user);
                    }
                    else if (IsSameFirstWord(inputmain, "CART")){
                        char namaBarang[MAX_LEN];
                        remainderWord(inputmain, "CART");
                        if (string_compare(inputmain, "ADD")){
                            remainderWord(inputmain, "ADD");
                            if (strlent(inputmain)> 0) {
                                copyFirstWord(inputmain, namaBarang);
                                int quantity = stringToINt(inputmain);
                                if (quantity != -1){
                                    CartAdd(map, listbarang, namaBarang, quantity);
                                }
                            }     
                        }
                        else if (string_compare(inputmain, "REMOVE") == 0){
                            remainderWord(inputmain, "REMOVE");
                            if (strlent(inputmain)> 0) {
                                copyFirstWord(inputmain, namaBarang);
                                int quantity = stringToINt(inputmain);
                                if (quantity != -1){
                                    CartRemove(&map, listbarang, namaBarang, quantity);
                                }
                            }     
                        }
                        else if (string_compare(inputmain, "DISPLAY") == 0){
                            DisplayCart(map);     
                        }
                        else if (string_compare(inputmain, "PAY") == 0){
                            CartPay(&userlist, &user, &map, &stackhistory);
                        }                               
                    }
                    else if (IsSameFirstWord(inputmain, "HISTORY")){
                        remainderWord(inputmain, "HISTORY");
                        if (strlent(inputmain) > 0){
                            int N = stringToINt(inputmain);
                            if (N != -1){
                                PrintStackHistory(stackhistory, N);
                            }
                        }

                    }
                    
                }

                    }else{
                        printf("Command tidak dikenal. \n");
                    }




            
            }
            else{
                printf("Gagal untuk login. \n");
            }
        }
        if (string_compare(input, "HELP") == 0){
            help_login();
        }
        else{
            printf("Command tidak dikenal. Masukkan HELP jika anda butuh bantuan. \n");
        }
    
    return 0;
}

