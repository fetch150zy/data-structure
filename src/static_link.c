/**
 * @file static_link.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement the basic data structure static link list
 * @version 0.1
 * @date 2022-07-29
 *
 * @copyright Copyright (c) 2022
 *
 */



#include "../include/static_link.h"



static inline int malloc_self(struct node *SLL);
static inline void free_self(struct node *SLL, int cur);



void init_static_link(struct node *SLL)
{
        for (int i = 0; i < MAX_SIZE - 1; ++i) {
                SLL[i].data = -1;
                SLL[i].cur = i + 1;
        }
        // Currently the static link list is empty. The cur of the last element is 0
        SLL[MAX_SIZE - 1].cur = 0;
        SLL[MAX_SIZE - 1].data = -1;
        return;
}



static inline int malloc_self(struct node *SLL)
{
        auto int cur = SLL[0].cur;
        if (0 != cur)
                SLL[0].cur = SLL[cur].cur;
        return cur;
}



int get_static_link_length(struct node *SLL)
{
        auto int length = 0;
        auto int cur = SLL[MAX_SIZE - 1].cur;
        while (0 != cur) {
                cur = SLL[cur].cur;
                length++;
        }
        return length;
}



bool insert(struct node *SLL, int cur, elemType elem)
{
        if (cur < 1 || cur > get_static_link_length(SLL) + 1) {
                puts("The cursor is out of bounds. Insert error in function insert().");
                return false;
        }
        auto int next = MAX_SIZE - 1, freeCur = malloc_self(SLL);
        if (0 != freeCur) {
                SLL[freeCur].data = elem;
                for (int i = 1; i < cur; ++i)
                        next = SLL[next].cur;
                SLL[freeCur].cur = SLL[next].cur;
                SLL[next].cur = freeCur;
                return true;
        }
        puts("Something wrong in function insert().");
        return false;
}



static inline void free_self(struct node *SLL, int cur)
{
        SLL[cur].data = -1;
        SLL[cur].cur = SLL[0].cur;
        SLL[0].cur = cur;
        return;
}



bool delete(struct node *SLL, int cur)
{
        if (cur < 1 || cur > get_static_link_length(SLL)) {
                puts("The cursor is out of bounds. Delete error in function delete().");
                return false;
        }
        auto int next = MAX_SIZE - 1;
        for (int i = 1; i < cur; ++i)
                next = SLL[next].cur;
        auto int current = SLL[next].cur;
        SLL[next].cur = SLL[current].cur;
        free_self(SLL, current);
        return true;
}
