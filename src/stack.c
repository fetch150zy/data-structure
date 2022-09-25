/**
 * @file stack.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement basic data structures stack
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "../include/stack.h"



#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


extern int errno;


static inline bool check_stack_num(int stack_num);



struct sqStack *init_stack(void)
{
        struct sqStack *SP = (struct sqStack *)malloc(sizeof(struct sqStack));
        if (NULL == SP) {
                fprintf(stderr, "*** Cause by malloc : %s\n", strerror(errno));
                assert(0);
        }
        memset(SP->data, 0, sizeof(SP->data));
        SP->top_left = -1;
        SP->top_right = MAX_SIZE;
        return SP;
}



static inline bool check_stack_num(int stack_num)
{
        if (left_stack == stack_num || right_stack == stack_num)
                return true;
        else {
                errno = EINVAL;
                fprintf(stderr, "*** error stack number : %s\n", strerror(errno));
                return false;
        }
}



bool is_empty_stack(struct sqStack S, int stack_num)
{
        if (check_stack_num(stack_num)) {
                if (left_stack == stack_num)
                        return (-1 == S.top_left);
                else
                        return (MAX_SIZE == S.top_right);
        }
        return STACK_NUM_ERR;
}



elemType get_top_elem(struct sqStack S, int stack_num)
{
        if (check_stack_num(stack_num)) {
                if (left_stack == stack_num)
                        return S.data[S.top_left];
                else
                        return S.data[S.top_right];
        }
        return STACK_NUM_ERR;
}



bool push(struct sqStack *SP, elemType elem, int stack_num)
{
        if (check_stack_num(stack_num)) {
                if (SP->top_left + 1 == SP->top_right) {
                        puts("*** The sqStack is full, you can't push elememt anymore.");
                        goto err;
                } else {
                        if (left_stack == stack_num) {
                                SP->top_left++;
                                SP->data[SP->top_left] = elem;
                                goto exit_safely;
                        } else {
                                SP->top_right--;
                                SP->data[SP->top_right] = elem;
                                goto exit_safely;
                        }
                }
        }

err:
        return false;
exit_safely:
        return true;
}



bool pop(struct sqStack *SP, elemType *elem, int stack_num)
{
        if (check_stack_num(stack_num)) {
                if (left_stack == stack_num) {
                        if (is_empty_stack(*SP, left_stack)) {
                                puts("*** The sqStack 1 is empty, you can't pop element anymore.");
                                goto err;
                        }
                        *elem = SP->data[SP->top_left--];
                        goto exit_safely;
                } else {
                        if (is_empty_stack(*SP, right_stack)) {
                                puts("*** The sqStack 2 is empty, you can't pop element anymore.");
                                goto err;
                        }
                        *elem = SP->data[SP->top_right++];
                        goto exit_safely;
                }
        }
err:
        return false;
exit_safely:
        return true;
}



void clear_stack(struct sqStack **SPP)
{
        if (NULL == *SPP) {
                puts("*** It has been free.");
                return;
        }
        free(*SPP);
        (*SPP) = NULL;
}


