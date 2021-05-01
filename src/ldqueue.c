/*** Includes **************************/
#include <stdlib.h>
#include <stdio.h>
#include "ldqueue.h"
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
queue_ld* Que_CreateQueue(int queue_size) {
    queue_intern* q = malloc(sizeof(*q));

    if(q == NULL) {
        fprintf(stderr, "out of memory queue\n");
        return NULL;
    }
    queue_slot* slot = malloc(sizeof(*slot));
    if(slot == NULL) {
        fprintf(stderr, "out of memory slot\n");
        return NULL;
    }
    slot->next = NULL;
    slot->item = NULL;
    q->first = slot;
    q->last = slot;
    q->queue_size = 0;
    q->queue_maxsize = queue_size;

    return (queue_ld*)q;
}

int Que_Push(queue_ld* queue, void* item) {
    queue_intern* q = (queue_intern*)queue;

    if(q == NULL) {
        fprintf(stderr, "invalid queue handle\n");
        return -1;
    }

    if(item == NULL) {
        fprintf(stderr, "invalid item funktion");
        return -1;
    }

    if(q->queue_size == q->queue_maxsize) {
        fprintf(stderr, "queue already full\n");
        return -1;
    }

    if(q->queue_size == 0) {
        printf("First\n");
        q->first->item = item;
        
    }else {
        printf("Add\n");
        queue_slot* slot = malloc(sizeof(*slot));
        if(slot == NULL) {
            fprintf(stderr, "out of memory slot\n");
            return -1;
        }
        slot->item = item;
        slot->next = NULL;
        q->last->next = slot;
        q->last = slot;
    }
    q->queue_size++;

    return 0;
}

void* Que_Pop(queue_ld* queue) {
    queue_intern* q = (queue_intern*)queue;
    if(q == NULL) {
        fprintf(stderr, "invalid queue handle\n");
        return NULL;
    }
    if(q->first != NULL) {
        queue_slot* slot = q->first;
        q->first = NULL;
        if(slot->next != NULL) {
            q->first = slot->next;
        }
        void* item = slot->item;
        free(slot);
        return item;
    }
    fprintf(stderr, "queue empty\n");
    return NULL;
}

int Que_Delete();

