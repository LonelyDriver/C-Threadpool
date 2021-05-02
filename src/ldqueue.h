#ifndef _LDQUEUE_H
#define _LDQUEUE_H

/*** Includes ***********************/

/*** Typedefs ***********************/
typedef struct _queue_ld* queue_ld;

/*** Definitions ********************/
queue_ld* Que_CreateQueue(int queue_size);
int Que_Push(queue_ld* queue, void* item);
void* Que_Pop(queue_ld* queue);
int Que_Delete(queue_ld* queue);

#endif // _LDQUEUE_H