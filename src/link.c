/**
 * @file link.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement basic data structures link list
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright Copyright (c) 2022
 *
 */



#include "../include/link.h"



#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>



extern int errno;



struct linkList *init_link(void)
{
        auto struct linkList *HP = (struct linkList *)malloc(sizeof(struct linkList));
        if (NULL == HP) {
                fprintf(stderr, "Cause by malloc : %s\n", strerror(errno));
                assert(0);
        }
        HP->next = NULL;
        HP->data = 0;
        return HP;
}



bool is_empty_link(struct linkList L)
{
        return (NULL == L.next);
}



int get_link_length(struct linkList L)
{
        return L.data;
}



#define ERROR_VAL -1

elemType get_element_val(struct linkList L, int pos)
{
        auto struct linkList *p = L.next;
        auto int cnt = 1;
        while (NULL != p && cnt < pos) {
                p = p->next;
                cnt++;
        }
        if (NULL == p || cnt > pos) {
                puts("Get element error in function get_element_val().");
                return ERROR_VAL;
        }
        return p->data;
}



bool insert(struct linkList *LP, int pos, elemType elem)
{
        auto struct linkList *p = LP;
        auto int cnt = 1;
        while (NULL != p && cnt < pos) {
                p = p->next;
                cnt++;
        }
        if (NULL == p || cnt > pos) {
                puts("Insert element error in function insert().");
                return false;
        }
        auto struct linkList *temp = (struct linkList *)malloc(sizeof(struct linkList));
        temp->data = elem;
        temp->next = p->next;
        p->next = temp;
        return true;
}



bool delete(struct linkList *LP, int pos)
{
        auto struct linkList *p = LP;
        auto int cnt = 1;
        while (NULL != p->next && cnt < pos) {
                p = p->next;
                cnt++;
        }
        if (NULL == p->next || cnt > pos) {
                puts("\nDelete element error in function LinkListDelete().");
                return false;
        }

        auto struct linkList *temp = p->next;
        p->next = temp->next;
        free(temp);
        temp = NULL;
        return true;
}



struct linkList *head_create(size_t size)
{
        auto struct linkList *HP = (struct linkList *)malloc(sizeof(struct linkList));
        HP->next = NULL;
        for (auto size_t i = 0; i < size; ++i) {
                auto struct linkList *p = (struct linkList *)malloc(sizeof(struct linkList));
                p->data = i + 100;
                p->next = HP->next;
                HP->next = p;
        }
        return HP;
}



struct linkList *tail_create(size_t size)
{
        auto struct linkList *HP = (struct linkList *)malloc(sizeof(struct linkList));
        auto struct linkList *temp = HP;
        HP->next = NULL;
        HP->data = -1;
        for (auto size_t i = 0; i < size; ++i) {
                auto struct linkList *p = (struct linkList *)malloc(sizeof(struct linkList));
                p->data = i + 100;
                temp->next = p;
                temp = p;
        }
        temp->next = NULL;
        return HP;
}



void clear_link(struct linkList **LPP)
{
        auto struct linkList *p = (*LPP)->next, *q;
        while (NULL != p) {
                q = p->next;
                free(p);
                p = q;
        }
        p = q = NULL;
        free(*LPP);
        (*LPP) = NULL;        
}


