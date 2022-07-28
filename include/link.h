/**
 * @file link.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief head file for link list
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _LINK_H_
#define _LINK_H_

#include "link.h"
#include <stdio.h>
#include <stdbool.h>

#define ERROR_VAL -1

typedef int elemType;
/* ADT of link list */
typedef struct Node
{
    elemType data;          // element
    struct Node* next;      // pointer to next node
}LinkList, *LinkListPtr;

extern LinkListPtr InitLink(void);
extern bool LinkIsEmpty(LinkList L);
extern elemType GetElem(LinkList L, int pos);
extern bool LinkListInsert(LinkListPtr* LPP, int pos, elemType elem);
extern bool LinkListDelete(LinkListPtr* LPP, int pos);
extern LinkListPtr CreateLinkListHead(size_t size);
extern LinkListPtr CreateLinkListTail(size_t size);
extern bool ClearLinkList(LinkListPtr* LPP);

#endif