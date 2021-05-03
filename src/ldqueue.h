/****************************************************************************
*
*   util.h: Util Routinen
*
*	Beschreibung:   
*
* 	Historie:
*
*	26.04.2021  		ri			erstellt
*
*
****************************************************************************/
#ifndef _WCON_UTIL_H
#define _WCON_UTIL_H

/**** INCLUDE **************************************************************/
#if __linux__

#elif _WIN32

#elif _BECK_RTOS

#endif

/**** DEFINES **************************************************************/

/**** PROTOTYPES ***********************************************************/

/*** Typedefs ***********************/
typedef struct _queue_o* queue_o;

/*** Definitions ********************/
queue_o UTIL_CreateQueue(int queue_size);
int UTIL_PushQueue(queue_o queue, void* item);
void* UTIL_PopQueue(queue_o queue);
int UTIL_DeleteQueue(queue_o* queue);
int UTIL_SizeQueue(queue_o queue);
#endif // _WCON_UTIL_H
