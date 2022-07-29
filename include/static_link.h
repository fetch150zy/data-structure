/**
 * @file static_link.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
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
typedef struct 
{
    elemType data;                  
    int cur;                // cursor (no pointer when 0)
}Component, StaticLinkList[MAX_SIZE];


extern void InitStaticLinkList(StaticLinkList SLL);
extern int MallocInStaticLinkList(StaticLinkList SLL);
extern int StaticLinkListLength(StaticLinkList SLL);
extern bool StaticLinkListInsert(StaticLinkList SLL, int cur, elemType elem);
extern void FreeInStaticLinkList(StaticLinkList SLL, int cur);
extern bool StaticLinkListDelete(StaticLinkList SLL, int cur);

#endif