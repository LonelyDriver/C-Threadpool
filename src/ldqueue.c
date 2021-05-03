/*** Includes **************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wcon/common/util.h"
/** Typedefs ***************************/
typedef struct _queue_slot queue_slot;

typedef struct _queue_slot {
    queue_slot* next;
    void* item;
} queue_slot;

typedef struct _queue_intern {
    queue_slot* first;
    queue_slot* last;
    int queue_size;
    int queue_maxsize;
} queue_intern;



/*** Declarition ***********************/
queue_o UTIL_CreateQueue(int queue_size) {
    int i;
    queue_intern* q = malloc(sizeof(*q));

    if(q == NULL) {
        fprintf(stderr, "out of memory queue\n");
        return NULL;
    }
    queue_slot* slot = malloc(queue_size * sizeof(*slot));
    if(slot == NULL) {
        fprintf(stderr, "out of memory slot\n");
        return NULL;
    }
    memset(slot, 0x00, queue_size*sizeof(*slot));

    for(i=0;i<=queue_size-1;i++) {
        slot[i].next = &slot[(i+1)%queue_size];
        slot[i].item = NULL;
    }
    q->first = &slot[0];
    q->last = &slot[0];
    q->queue_size = 0;
    q->queue_maxsize = queue_size;

    return (queue_o)q;
}

int UTIL_PushQueue(queue_o queue, void* item) {
    queue_intern* q = (queue_intern*)queue;

    if(q == NULL) {
        fprintf(stderr, "invalid queue handle\n");
        return -1;
    }

    if(item == NULL) {
        fprintf(stderr, "invalid item");
        return -1;
    }

    if(q->queue_size == q->queue_maxsize) {
        fprintf(stderr, "queue already full\n");
        return -1;
    }
    
    q->last->item = item;
    q->last = q->last->next;
    q->queue_size++;

    return 0;
}

void* UTIL_PopQueue(queue_o queue) {
    queue_intern* q = (queue_intern*)queue;
    queue_slot* slot;
    if(q == NULL) {
        fprintf(stderr, "invalid queue handle\n");
        return NULL;
    }
    if(q->queue_size != 0) {
        slot = q->first;
        q->first = NULL;
        if(slot->next != NULL) {
            q->first = slot->next;
        }
        void* item = slot->item;
        slot->item = NULL;
        q->queue_size--;
        return item;
    }
    fprintf(stderr, "queue empty\n");
    return NULL;
}

int UTIL_DeleteQueue(queue_o* queue) {
    queue_intern* q =(queue_intern*)*queue;
    int max_size = q->queue_size;
    queue_slot* slot = q->first;
    for(int i=0;i<max_size;i++) {
        queue_slot* next = slot->next;
        if(slot != NULL) {
            free(slot);
        }
        slot = next;
    }
    free(q);
    q = NULL;
    return 0;
}

int UTIL_SizeQueue(queue_o queue) {
    queue_intern* q =(queue_intern*)queue;
    return q->queue_size;
}
