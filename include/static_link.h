/**
 * @file static_link.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief header file for static link list
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef _STATIC_LINK_H_
#define _STATIC_LINK_H_


#include "static_link.h"


#include <stdio.h>
#include <stdbool.h>


#define MAX_SIZE 50
typedef int elemType;
/* ADT of static link list */
struct node {
        elemType data;                  
        int cur;                // cursor (no pointer when 0)
};


extern void init_static_link(struct node *SLL);
extern int get_static_link_length(struct node *SLL);
extern bool insert(struct node *SLL, int cur, elemType elem);
extern bool delete(struct node *SLL, int cur);


#endif

