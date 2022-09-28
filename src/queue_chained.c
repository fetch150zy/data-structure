/**
 * @file chained_queue.c
 * @author Achiever&
 * @brief Implement chained data structure queues
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "../include/queue_chained.h"

#include <errno.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


extern int errno;


static inline bool is_empty_queue(struct linkQueue cq);


static inline bool is_empty_queue(struct linkQueue cq)
{
        return (cq.front == cq.rear);
}



/*生成队列,函数体中cq为队列指针的结构体
大体思路：使用尾指针创建一个节点结构体，使头尾相等，利用的尾指针来循环建立新的节点
因为给节点赋值与创建新元素写在了一起，为避免尾指针不指向尾节点，暂时用p来储存上一个节点
给节点赋值仅是从1叠加，后续更改

The queue is generated, and cq in the function body is the struct of the queue pointer
The general idea: use the tail pointer to create a node structure that makes the head and tail equal, 
and use the tail pointer to loop to build new nodes
Because assigning a value to a node is written together with the creation of a new element, 
to avoid the tail pointer not pointing to the tail node, p is temporarily used to store the previous node
Assign a value to a node only from 1 overlay, with subsequent changes*/
extern struct linkQueue init_queue(int len)
{
        struct linkQueue cq;
        cq.rear = (struct qnode*)malloc(sizeof(struct qnode));
        cq.front = cq.rear;
        struct qnode* p = cq.rear;
        for (int i = 0; i < len; ++i)
        {
                cq.rear->data = i+1;
                cq.rear->next = (struct qnode*)malloc(sizeof(struct qnode));
                // printf("%d ", i+1);
                p = cq.rear;
                cq.rear = cq.rear->next;
        }
        cq.rear = p;
        cq.rear->next = NULL;   //将尾指针的next赋值为空(Assign the next value of the trailing pointer to null)
        return cq;

}



/*利用尾指针来创建新的节点，并将传入数值e进行赋值
A new node is created using the tail pointer and the passing value e is assigned*/
extern int enQueue (struct linkQueue cq, elemType e)
{
        cq.rear->next = (struct qnode*)malloc(sizeof(struct qnode));
        cq.rear = cq.rear->next;
        cq.rear->data = e;
        return 1;
}



/*将头指针向后移动，并释放空间
Move the head pointer backward and free up space*/
extern void deQueue (struct linkQueue cq)
{
        struct qnode * p;
        p = cq.front;
        if(cq.front->next)
                cq.front = cq.front->next;
        else
                cq.front = NULL;
        free(p);
}



/*循环，如果该节点的值不为空则长度加1，避免空链表长度错误
Loop, if the value of the node is not empty, the length is increased by 1, 
to avoid the error of the empty linked list length*/
extern size_t get_queue_length(struct linkQueue cq)
{
        int i = 0;
        struct qnode* p = cq.front;
        for(; ; )
        {
                if(p->data)
                {
                        i++;
                        p = p->next;
                }
                if(p == NULL)
                {
                        return i;
                }
        }
}




extern elemType get_front_elem(struct linkQueue cq)
{
        return cq.front->data;
}


extern elemType get_back_elem(struct linkQueue cq)
{
        return cq.rear->data;
}


/*循环释放空间
Cycle to free up space*/
extern void clear_chaQueue(struct linkQueue cq)
{
        struct qnode* q = cq.front;
        struct qnode* p;
        do
        {
                p = q->next;
                free(q);
                q = p;
        } while (q->next);

        cq.front = NULL;
        cq.rear = NULL;
        p = NULL;
        q = NULL;
}