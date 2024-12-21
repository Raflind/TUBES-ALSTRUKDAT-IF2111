#ifndef USER_H
#define USER_H

#include "boolean.h"
#include "stackhistory.h"
#include "map.h"
#include "wishlist.h"

#define MAX_USERS 10
#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
    Map keranjang;
    Stack riwayat_pembelian;
    List wishlist;
} User;

typedef struct {
    User buffer[MAX_USERS];
    int nEff;
} ListUser;


void CreateListUser(ListUser *list);
boolean IsUserExist(ListUser *list, char *username);
void AddUser(ListUser *list, User newUser);
int FindUser(ListUser *list, char *username);
void CartPay(ListUser *list, User *user, Map *M);
void DisplayCart(Map M);
void AddCartToUser(Map M, User *user);
void AddWishlistToUser(List wishlist, User *user);

#endif