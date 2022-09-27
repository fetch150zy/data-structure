/**
 * @file link_stack.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement basic data structures link stack
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "../include/link_stack.h"



#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


extern int errno;

static inline void check_error(const void *ptr);
static inline bool is_empty_stack(struct linkStack SL);



static inline void check_error(const void *ptr)
{
        if (NULL == ptr) {
                fprintf(stderr, "Cause by malloc : %s\n", strerror(errno));
                assert(0);
        }
        return;
}



static inline bool is_empty_stack(struct linkStack SL)
{
        return (0 == SL.cnt);
}



struct linkStack *init_stack(void)
{
        struct linkStack *LSP = malloc(sizeof(struct linkStack));
        check_error(LSP);
        LSP->cnt = 0;
        LSP->top = NULL;
        return LSP;
}



bool push(struct linkStack *LSP, elemType elem)
{
        struct node *nd = malloc(sizeof(struct node));
        check_error(nd);
        nd->data = elem;
        nd->next = LSP->top;
        LSP->top = nd;
        LSP->cnt++;
        return true;
}



elemType get_top_val(struct linkStack LS)
{
        check_error(&LS);
        return LS.top->data;
}




bool pop(struct linkStack *LSP, elemType *elem)
{
        if (is_empty_stack(*LSP)) {
                puts("*** The stack is empty, you can't pop element anymore.");
                return false;
        }
        struct node *nd;
        *elem = LSP->top->data;
        nd = LSP->top;
        LSP->top = LSP->top->next;
        free(nd);
        LSP->cnt--;
        return true;
}



void clear_stack(struct linkStack **LSPP)
{
        if (NULL == *LSPP) {
                puts("*** It has been free.");
                return;
        }
        auto struct node *p = (*LSPP)->top->next, *q;
        while (NULL != p) {
                q = p->next;
                free(p);
                p = q;
        }
        p = q = NULL;
        free(*LSPP);
        (*LSPP) = NULL;
}