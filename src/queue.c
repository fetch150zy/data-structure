/**
 * @file queue.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement basic data structures queue
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "../include/queue.h"



#include <errno.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>



extern int errno;

static inline bool is_empty_queue(struct sqQueue SQ);
static inline bool is_full_queue(struct sqQueue SQ);



static inline bool is_empty_queue(struct sqQueue SQ)
{
        return (SQ.front == SQ.rear);
}



static inline bool is_full_queue(struct sqQueue SQ)
{
        return ((SQ.rear + 1) % MAX_SIZE == SQ.front);
}



struct sqQueue *init_queue(void)
{
        struct sqQueue *SQP = malloc(sizeof(struct sqQueue));
        if (NULL == SQP) {
                fprintf(stderr, "Cause by malloc : %s\n", strerror(errno));
                assert(0);
        }
        memset(SQP->data, 0, sizeof(SQP->data));
        SQP->front = 0;
        SQP->rear = 0;
        return SQP;
}



size_t get_queue_length(struct sqQueue SQ)
{
        return (SQ.rear - SQ.front + MAX_SIZE) % MAX_SIZE;
}



elemType get_front_elem(struct sqQueue SQ)
{
        return SQ.data[SQ.front];
}



elemType get_back_elem(struct sqQueue SQ)
{
        return SQ.data[(SQ.rear - 1) % MAX_SIZE];
}



extern bool enque(struct sqQueue *SQP, elemType elem)
{
        if (is_full_queue(*SQP)) {
                puts("*** The sequence queue is full of elements, you can't enter anymore.");
                goto err;
        }
        SQP->data[SQP->rear] = elem;
        SQP->rear = (SQP->rear + 1) % MAX_SIZE;
        goto exit_safely;

exit_safely:
        return true;
err:
        return false;
}



extern bool deque(struct sqQueue *SQP, elemType *elem)
{
        if (is_empty_queue(*SQP)) {
                puts("*** The sequence queue is empty, you can't enter anymore.");
                goto err;
        }
        *elem = SQP->data[SQP->front];
        SQP->front = (SQP->front + 1) % MAX_SIZE;
        goto exit_safely;

exit_safely:
        return false;
err:
        return false;
}



void clear_queue(struct sqQueue **SQPP)
{
        if (NULL == *SQPP) {
                puts("*** It has benn free.");
                return;
        }
        free(*SQPP);
        (*SQPP) = NULL;
        return;
}