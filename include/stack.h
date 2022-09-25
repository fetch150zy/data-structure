/**
 * @file stack.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file of stack
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef STACK_H_
#define STACK_H_


#include "stack.h"


#include <stdio.h>
#include <stdbool.h>


#define MAX_SIZE (1 << 8)
#define STACK_NUM_ERR 0


const static int left_stack = 1;
const static int right_stack = 2;


typedef int elemType;

struct sqStack {
        elemType data[MAX_SIZE];
        int top_left;
        int top_right;
};


extern struct sqStack *init_stack(void);
extern bool is_empty_stack(struct sqStack S, int stack_num);
extern elemType get_top_elem(struct sqStack S, int stack_num);
extern bool push(struct sqStack *SP, elemType elem, int stack_num);
extern bool pop(struct sqStack *SP, elemType *elem, int stack_num);
extern void clear_stack(struct sqStack **SPP);


#endif


