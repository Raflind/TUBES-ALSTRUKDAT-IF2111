#include "profile.h"
#include "cart.h"
#include "wishlist.h"
#include "stackhistory.h"
#include <stdio.h>

void Profile(User *user) {
    printf("\n>> PROFILE\n");
    printf("Nama  : %s\n", user->name);
    printf("Saldo : %d\n", user->money);

    printf("\nKeranjang Belanja:\n");
    if (IsEmpty(user->keranjang)) {
        printf("Keranjang kosong.\n");
    }
    else {
        DisplayCart(user->keranjang);
    }

    if (IsStackEmpty(user->riwayat_pembelian)) {
        printf("Riwayat pembelian kosong.\n");
    } else {
        PrintStackHistory(user->riwayat_pembelian, 5);
    }

    printf("\nWishlist:\n");
    if (isEmptyList(user->wishlist)) {
        printf("Wishlist kosong.\n");
    } else {
        wishlistShow(user->wishlist);
    }

    printf(">\nKembali ke menu utama\n");
}
