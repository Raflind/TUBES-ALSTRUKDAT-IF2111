#include "stackhistory.h"

void CreateEmptyStack(Stack *S)
{
    S->TOP = NULL;
}

boolean IsStackEmpty(Stack S)
{
    return (S.TOP == NULL);
}

boolean IsStackFull(Stack S)
{
    return false;
}

void Push(Stack *S, infotype X)
{
    address newNode = (address)malloc(sizeof(stacknode));
    newNode->info = X;
    newNode->next = S->TOP;
    S->TOP = newNode;
}

void Pop(Stack *S, infotype *X)
{
    if (!IsStackEmpty(*S))
    {
        address temp = S->TOP;
        *X = temp->info;
        S->TOP = temp->next;
        free(temp);
    }
}

void PrintStackHistory(Stack S, int N)
{
    if (IsStackEmpty(S))
    {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }
    printf("Riwayat Pembelian:\n");
    address current = S.TOP;
    int count = 0;
    while (current != NULL && count < N)
    {
        Pembelian p = current->info;
        printf("Pembelian %d - Total %d\n", p.id, p.total);
        printf("Kuantitas\tNama\t\tTotal\n");
        for (int j = 0; j < p.jumlah_barang; j++)
        {
            Cart cartItem = p.cart[j];
            printf("%d\t\t%s\t\t%d\n", cartItem.Kuantitas, cartItem.Barang.name, cartItem.total);
        }
        printf("\n");
        current = current->next;
        count++;
    }
}

void AddtoPembelian(Map *M, Stack *stackhistory)
{
    Pembelian purchase;
    purchase.jumlah_barang = 0;
    purchase.total = 0;
    for (int i = 0; i < M->Count; i++)
    {
        purchase.cart[i] = M->Elements[i];
    }
    purchase.jumlah_barang = M->Count;
    purchase.total = TotalHarga(*M);
    if (IsStackEmpty(*stackhistory))
    {
        purchase.id = 1;
    }
    else
    {
        purchase.id = stackhistory->TOP->info.id + 1;
    }
    Push(stackhistory, purchase);
}

// Fungsi untuk menghitung panjang stack
int StackLength(Stack *S)
{
    int length = 0;
    address current = S->TOP;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

// Implementation of getHistoryStrings
void writeHistory(FILE *pita, Stack *S)
{
    // Hitung jumlah history barang
    int length = StackLength(S);

    // tulis banyaknya barang yang dibeli
    fprintf(pita, "%d\n", length);

    // Traversal stacknya untuk menulis history
    address current = S->TOP;
    int count = 0;
    while (current != NULL)
    {
        Pembelian p = current->info;
        fprintf(pita, "%d %d\n", p.jumlah_barang, p.total);
        for (int j = 0; j < p.jumlah_barang; j++)
        {
            Cart cartItem = p.cart[j];
            fprintf(pita, "%d %d %s\n", cartItem.total, cartItem.Kuantitas, cartItem.Barang.name);
            current = current->next;
        }
    }
}
