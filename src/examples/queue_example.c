#include "ldqueue.h"
#include <stdio.h>

typedef void* (*callback)();

static void reader() {
    printf("Hello from reader\n");
}

static void writer() {
    printf("Hello from writer\n");
}

int main() {
    queue_ld* q;
    callback func;
    int x = 5;
    printf("================= Queue example ===============\n");

    if(( q = Que_CreateQueue(3)) == NULL) {
        return -1;
    }
    if(Que_Push(q, reader)) {
        printf("push failed\n");
        return -1;
    }
    if(Que_Push(q, writer)) {
        printf("push failed\n");
        return -1;
    }
    Que_Push(q, &x);
    Que_Push(q, &x);

    if((func=Que_Pop(q)) == NULL) {
        printf("pop failed\n");
        return -1;
    }

    func();
    if((func=Que_Pop(q)) == NULL) {
        printf("pop failed\n");
        return -1;
    }
    func();
    int* y = Que_Pop(q);
    int* z = Que_Pop(q);
    printf("y=%d\n", *y);
    Que_Delete(q);
    printf("Done\n");
    return 0;
}