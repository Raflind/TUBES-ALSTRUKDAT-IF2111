#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    if (isEmpty(q)) {
        return false;
    }
    return ((IDX_TAIL(q) + 1) % CAPACITY == IDX_HEAD(q));
}

int length(Queue q) {
    if (isEmpty(q)) {
        return 0;
    } else {
        if (IDX_TAIL(q) >= IDX_HEAD(q)) {
            return IDX_TAIL(q) - IDX_HEAD(q) + 1;
        } else {
            return CAPACITY - (IDX_HEAD(q) - IDX_TAIL(q) - 1);
        }
    }
}

void enqueue(Queue *q, ElemenQueue val) {
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    (*q).buffer[IDX_TAIL(*q)] = val;
}

void dequeue(Queue *q, ElemenQueue *val) {
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        // Queue menjadi kosong
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

boolean IsMemberQ(Queue q, char *name) {
    if (isEmpty(q)) {
        return false;
    }
    
    int idx = IDX_HEAD(q);
    int len = length(q);
    
    for (int i = 0; i < len; i++) {
        ElemenQueue current = q.buffer[idx];
        
        // Bandingkan nama barang dengan nama yang dicari
        if (string_compare(current.name, name) == 0) {
            return true;
        }
        
        idx = (idx + 1) % CAPACITY;
    }
    
    return false;
}