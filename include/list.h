/**
 * @file list.h
 * @author fetcha150zy (Mars_zhewei@outlook.com)
 * @brief header file of sequence list
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef LIST_H_
#define LIST_H_


#include "list.h"


#include <stdio.h>
#include <stdbool.h>


#define MAX_SIZE 100
typedef int elemType;
/* ADT of sequence list */
struct sqList {
        elemType data[MAX_SIZE];    // store elems
        size_t length;              // the number of stored elems
};


extern struct sqList* init_list(void);
extern size_t get_list_length(struct sqList SL);
extern elemType get_element_val(struct sqList SL, int pos);
extern int get_element_index(struct sqList SL, elemType elem);
extern bool insert(struct sqList* SLP, int pos, elemType elem);
extern bool delete(struct sqList* SLP, int pos);
extern void clear_list(struct sqList** SLPP);


#endif

