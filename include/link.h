/**
 * @file link.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file for link list
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright Copyright (c) 2022
 *
 */


#ifndef LINK_H_
#define LINK_H_


#include "link.h"


#include <stdio.h>
#include <stdbool.h>


typedef int elemType;
/* ADT of link list */
struct linkList {
        elemType data;         // element
        struct linkList *next; // pointer to next node
};


extern struct linkList *init_link(void);
extern bool is_empty_link(struct linkList L);
extern elemType get_element_val(struct linkList L, int pos);
extern bool insert(struct linkList *LP, int pos, elemType elem);
extern bool delate(struct linkList *LP, int pos);
extern struct linkList *head_create(size_t size);
extern struct linkList *tail_create(size_t size);
extern void clear_link(struct linkList **LPP);


#endif

