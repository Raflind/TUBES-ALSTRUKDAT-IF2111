#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

boolean isEmptyList(List l) {
    return (FIRST(l) == NULL);
}

ElType getElmt(List l, int idx) {
    int ctr = 0;
    Address p = FIRST(l);
    
    while (ctr < idx) {
        ctr++;
        p = NEXT(p);
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    int ctr = 0;
    Address p = FIRST(*l);
    
    while (ctr < idx) {
        ctr++;
        p = NEXT(p);
    }
    string_copy(INFO(p), val);
}

int indexOf(List l, ElType val) {
    Address p = FIRST(l);
    int idx = 0;
    boolean found = false;
    
    while (p != NULL && !found) {
        if (string_compare(INFO(p), val) == 0) {
            found = true;
        } else {
            idx++;
            p = NEXT(p);
        }
    }
    
    if (found) {
        return idx;
    } else {
        return IDX_UNDEF_LIST;
    }
}

void insertFirst(List *l, ElType val) {
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = (char*)malloc((strlent(val) + 1) * sizeof(char));
        if (INFO(p) != NULL) {
            string_copy(INFO(p), val);
            NEXT(p) = FIRST(*l);
            FIRST(*l) = p;
        } else {
            free(p);
        }
    }
}

void insertLast(List *l, ElType val) {
    if (isEmptyList(*l)) {
        insertFirst(l, val);
    } else {
        Address p = (Address)malloc(sizeof(Node));
        if (p != NULL) {
            INFO(p) = (char*)malloc((strlent(val) + 1) * sizeof(char));
            if (INFO(p) != NULL) {
                string_copy(INFO(p), val);
                NEXT(p) = NULL;
                
                Address last = FIRST(*l);
                while (NEXT(last) != NULL) {
                    last = NEXT(last);
                }
                NEXT(last) = p;
            } else {
                free(p);
            }
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        Address p = (Address)malloc(sizeof(Node));
        if (p != NULL) {
            INFO(p) = (char*)malloc((strlent(val) + 1) * sizeof(char));
            if (INFO(p) != NULL) {
                string_copy(INFO(p), val);
                
                int ctr = 0;
                Address loc = FIRST(*l);
                while (ctr < idx - 1) {
                    ctr++;
                    loc = NEXT(loc);
                }
                
                NEXT(p) = NEXT(loc);
                NEXT(loc) = p;
            } else {
                free(p);
            }
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    Address p = FIRST(*l);
    *val = (char*)malloc((strlent(INFO(p)) + 1) * sizeof(char));
    if (*val != NULL) {
        string_copy(*val, INFO(p));
        FIRST(*l) = NEXT(p);
        free(INFO(p));
        free(p);
    }
}

void deleteLast(List *l, ElType *val) {
    Address p = FIRST(*l);
    Address loc = NULL;
    
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    
    *val = (char*)malloc((strlent(INFO(p)) + 1) * sizeof(char));
    if (*val != NULL) {
        string_copy(*val, INFO(p));
        
        if (loc == NULL) {
            FIRST(*l) = NULL;
        } else {
            NEXT(loc) = NULL;
        }
        
        free(INFO(p));
        free(p);
    }
}

void deleteAt(List *l, int idx, ElType *val) {
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        int ctr = 0;
        Address loc = FIRST(*l);
        while (ctr < idx - 1) {
            ctr++;
            loc = NEXT(loc);
        }
        
        Address p = NEXT(loc);
        *val = (char*)malloc((strlent(INFO(p)) + 1) * sizeof(char));
        if (*val != NULL) {
            string_copy(*val, INFO(p));
            NEXT(loc) = NEXT(p);
            free(INFO(p));
            free(p);
        }
    }
}

int lengthList(List l) {
    int ctr = 0;
    Address p = FIRST(l);
    while (p != NULL) {
        ctr++;
        p = NEXT(p);
    }
    return ctr;
}

List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    
    Address p = FIRST(l1);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    
    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    
    return l3;
}

void swapIdx(List *l, int idx1, int idx2) {
    if (isEmptyList(*l) || lengthList(*l) <= 1) {
        return;
    }

    int listlengthList = lengthList(*l);
    if (idx1 < 0 || idx1 >= listlengthList || idx2 < 0 || idx2 >= listlengthList) {
        return;
    }

    if (idx1 == idx2) {
        return;
    }

    Address prev1 = NULL;
    Address curr1 = FIRST(*l);
    for (int i = 0; i < idx1; i++) {
        prev1 = curr1;
        curr1 = NEXT(curr1);
    }

    Address prev2 = NULL;
    Address curr2 = FIRST(*l);
    for (int i = 0; i < idx2; i++) {
        prev2 = curr2;
        curr2 = NEXT(curr2);
    }

    if (prev1 != NULL) {
        NEXT(prev1) = curr2;
    } 
    else {
        *l = curr2;
    }

    if (prev2 != NULL) {
        NEXT(prev2) = curr1;
    } 
    else {
        *l = curr1;
    }

    Address temp = NEXT(curr1);
    NEXT(curr1) = NEXT(curr2);
    NEXT(curr2) = temp;
}

boolean isInList(List l, ElType val) {
    if (isEmptyList(l)) {
        return false;
    }
    
    Address p = FIRST(l);
    while (p != NULL) {
        if (string_compare(INFO(p), val) == 0) {
            return true;
        }
        p = NEXT(p);
    }
    return false;
}

void printList(List l) {
    Address p = FIRST(l);
    int counter = 1;
    while (p != NULL) {
        printf("%d. %s\n", counter, INFO(p));
        counter++;
        p = NEXT(p);
    }
}

void clearList(List *l) {
    while (!isEmptyList(*l)) {
        Address p = FIRST(*l);
        FIRST(*l) = NEXT(p);
        free(INFO(p));
        free(p);   
    }
}