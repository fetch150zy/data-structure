/**
 * @file list.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief Implement the basic data structure sequence list 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "../include/list.h"



#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>



extern int errno;



static inline bool is_empty_list(struct sqList SL);



struct sqList* init_list(void)
{
        auto struct sqList *SLP = (struct sqList *)malloc(sizeof(struct sqList));
        if (NULL == SLP) {
                fprintf(stderr, "Cause by malloc : %s\n", strerror(errno));
                assert(0);
        }
        memset(SLP->data, 0, sizeof(SLP->data));
        SLP->length = 0;
        return SLP;
}



static inline bool is_empty_list(struct sqList SL)
{
        return (0 == SL.length);
}



size_t get_list_length(struct sqList SL)
{
         return (SL.length);
}



#define ERROR_VAL -1

elemType get_element_val(struct sqList SL, int pos)
{
        if (is_empty_list(SL)) {
                puts("*** The sqList is empty. "
                        "Query error in function get_element_val().");
                goto err;
        } else {
                if (pos < 1 || pos > SL.length) {
                        puts("*** The position is out of bounds. "
                                "Query error in function get_element_val().");
                        goto err;
                } else {
                       return SL.data[pos-1]; 
                }
        }

err:    
        return ERROR_VAL;
}



#define ERROR_POS -1

int get_element_index(struct sqList SL, elemType elem)
{
        if (is_empty_list(SL)) {
                puts("*** The sqList is empty. "
                        "Query error in function get_element_index().");
                goto err;
        } else {
                for (int i = 0; i < SL.length; ++i) {
                        if (elem == SL.data[i])
                                return i+1;
                }
                puts("*** Not found.");
                goto err;
        }

err:
        return ERROR_POS;
}



bool insert(struct sqList* SLP, int pos, elemType elem)
{
        if (MAX_SIZE == SLP->length) {
                puts("*** The struct sqList is full. Insert error in function insert().");
                return false;
        } else {
                if (pos < 1 || pos > SLP->length+1) {
                        puts("*** The pos is out of bounds. "
                                "Insert error in function insert().");
                        return false;
                } else {
                        if (pos <= SLP->length) {
                                for (int i = SLP->length-1; i >= pos-1; --i)
                                        SLP->data[i+1] = SLP->data[i];
                        }
                        SLP->data[pos-1] = elem;
                        SLP->length += 1;
                }
        }
        return true;
}



bool delete(struct sqList* SLP, int pos)
{
        if (is_empty_list(*SLP)) {
                puts("*** The struct sqList is empty. Delete failed in function delete().");
                return false;
        } else {
                if (pos < 1 || pos > SLP->length) {
                        puts("*** The pos is out of bounds. Delete failed in function delete().");
                        return false;
                } else {
                        if (pos < SLP->length)    {
                                for (int i = pos; i < SLP->length; ++i)
                                        SLP->data[i-1] = SLP->data[i];
                        }
                        SLP->length -= 1;
                }
        }
        return true;
}



void clear_list(struct sqList** SLPP)
{
        if (NULL == *SLPP) {
                puts("*** It has been free.");
                return;
        }
        free(*SLPP);
        *SLPP = NULL;
}


