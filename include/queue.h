/**
 * @file queue.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file of queue
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef QUEUE_H_
#define QUEUE_H_


#include "queue.h"


#include <stdio.h>
#include <stdbool.h>


#define MAX_SIZE 100 


typedef int elemType;
/* ADT of sequence queue */
struct sqQueue {
        elemType data[MAX_SIZE];
        int front, rear;
};


extern struct sqQueue *init_queue(void);
extern size_t get_queue_length(struct sqQueue SQ);
extern elemType get_front_elem(struct sqQueue SQ);
extern elemType get_back_elem(struct sqQueue SQ);
extern bool enque(struct sqQueue *SQP, elemType elem);
extern bool deque(struct sqQueue *SQP, elemType *elem);
extern void clear_queue(struct sqQueue **SQPP);


#endif

