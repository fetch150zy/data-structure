/**
 * @file link_stack.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file of link stack
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef LINK_STACK_
#define LINK_STACK_


#include "link_stack.h"


#include <stdio.h>
#include <stdbool.h>


typedef int elemType;


struct node {
        elemType data;
        struct node *next;
};

struct linkStack {
        struct node *top;
        int cnt;
};


extern struct linkStack *init_stack(void);
extern bool push(struct linkStack *LSP, elemType elem);
extern elemType get_top_val(struct linkStack LS);
extern bool pop(struct linkStack *LSP, elemType *elem);
extern void clear_stack(struct linkStack **LSPP);

#endif

