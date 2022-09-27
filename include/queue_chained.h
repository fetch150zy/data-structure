/**
 * @file queue_chained.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file of queue_chained
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef QUEUE_CHAINED_H_
#define QUEUE_CHAINED_H_

#include "queue_chained.h"

#include <stdio.h>
#include <stdbool.h>

typedef int elemType;
/* ADT of chained queue */

/*
struct qnode 包含数据和下一个元素 (contains the data and the next element)
struct linkQueue 包含头指针和尾指针 (contains the head and tail pointers)
*/

struct qnode
{
        elemType data;
        struct qnode* next;
};


struct linkQueue
{
        struct qnode* front;
        struct qnode* rear;
};


extern struct linkQueue init_queue(int len);
extern int enQueue (struct linkQueue cq, elemType e);
extern void deQueue (struct linkQueue cq);
extern size_t get_queue_length(struct linkQueue cq);
extern elemType get_front_elem(struct linkQueue cq);
extern elemType get_back_elem(struct linkQueue cq);
extern void clear_chaQueue(struct linkQueue cq);

#endif