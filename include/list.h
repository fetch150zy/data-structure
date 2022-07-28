/**
 * @file list.h
 * @author fetcha150zy (Mars_zhewei@outlook.com)
 * @brief header file of sequence table
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _LIST_H_
#define _LIST_H_

#include "list.h"
#include <stdio.h>
#include <stdbool.h>

#define ERROR_VAL -1
#define ERROR_POS -1

#define MAX_SIZE 100
typedef int elemType;
/* ADT of sequence table */
typedef struct 
{
    elemType data[MAX_SIZE];    // store elems
    size_t length;              // the number of stored elems
}SqList;

extern SqList* InitList(void);
extern bool ListIsEmpty(SqList SL);
extern size_t ListLength(SqList SL);
extern elemType GetElem(SqList SL, int pos);
extern int LocateElem(SqList SL, elemType elem);
extern bool ListInsert(SqList* SLP, int pos, elemType elem);
extern bool ListDelete(SqList* SLP, int pos);
extern void ClearList(SqList** SLPP);

#endif

