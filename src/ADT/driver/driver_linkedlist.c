#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    List l;
    ElType val;

    CreateList(&l);
    isEmptyList(l);

    insertFirst(&l, "Shiori");
    insertLast(&l, "Bae");
    insertAt(&l, "Watame", 1);

    isEmptyList(l);

    lengthList(l);

    printList(l);

    getElmt(l, 2);

    setElmt(&l, 2, "Hakos");

    getElmt(l, 2);

    indexOf(l, "Hakos");

    isInList(l, "Shiori");

    deleteFirst(&l, &val);

    deleteLast(&l, &val);

    deleteAt(&l, 0, &val);

    insertFirst(&l, "Shiori");
    insertLast(&l, "Bae");
    insertLast(&l, "Watame");
    swapIdx(&l, 0, 2);

    List l2, l3;
    CreateList(&l2);
    insertFirst(&l2, "Hakos");
    insertLast(&l2, "Novella");
    l3 = concat(l, l2);

    clearList(&l);
    clearList(&l2);
    clearList(&l3);
    return 0;
}
