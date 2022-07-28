/**
 * @file list.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/list.h"
#include <string.h>
#include <stdlib.h>


/**
 * @brief initialize sequence list
 * 
 * @param SLP the pointer of SqList variable
 */
SqList* InitList(void)
{
    auto SqList *SLP = (SqList *)malloc(sizeof(SqList));
    memset(SLP->data, 0, sizeof(SLP->data));
    SLP->length = 0;
    return SLP;
}


/**
 * @brief Check if the sequence list is empty
 * 
 * @param SL SqList variable
 * @return true :table is empty
 * @return false :table is not empty
 */
bool ListIsEmpty(SqList SL)
{
    return (0 == SL.length);
}


/**
 * @brief get the length of SqList
 * 
 * @param SL SqList variable
 * @return size_t :the length of SqList
 */
size_t ListLength(SqList SL)
{
    return (SL.length);
}


/**
 * @brief Get the Elem object
 * 
 * @param SL SqList variable
 * @param pos position of the variable which you want to get(from 1 to length)
 * @return elemType :the value of pos in SL, return -1(ERROR_VAL) for query error
 */
elemType GetElem(SqList SL, int pos)
{
    if (pos < 1)    {
        puts("\nThe position is out of bounds(pos < 1). Query error in function GetElem().");
        return ERROR_VAL;
    }
    else if (pos > SL.length)    {
        puts("\nThe position is out of bounds(pos > SL.length). Query error in function GetElem().");
        return ERROR_VAL;
    }
    else if (ListIsEmpty(SL))    {
        puts("\nThe SqList is empty. Query error in function GetElem().");
        return ERROR_VAL;
    }
    else    {
        return SL.data[pos-1];
    }
}


/**
 * @brief get the pos of elem in SqList
 * 
 * @param SL SqList variable
 * @param elem the val you want to search in SqList
 * @return int :the pos(from 1 to length) of val in SqList, return -1(ERROR_POS) if SqList is empty 
 */
int LocateElem(SqList SL, elemType elem)
{
    if (ListIsEmpty(SL))    {
        puts("The SqList is empty. Query error in function LocateElem().");
        return ERROR_POS;
    }
    else    {
        for (int i = 0; i < SL.length; ++i)
        {
            if (elem == SL.data[i])    {
                return i+1;
            }
        }
        puts("Not found.");
        return ERROR_POS;
    }
}


/**
 * @brief enter the new elem at pos in the SqList
 * 
 * @param SLP the pointer of SqList
 * @param pos the position you want to insert
 * @param elem the element you want to insert
 * @return true :inserted successfully
 * @return false :insert failed
 */
bool ListInsert(SqList* SLP, int pos, elemType elem)
{
    if (MAX_SIZE == SLP->length)    {
        puts("The SqList is full. Insert error in function ListInsert().");
        return false;
    }
    else if (pos < 1 || pos > SLP->length+1)    {
        puts("The pos is out of bounds. Insert error in function ListInsert().");
        return false;
    }
    else    {
        if (pos <= SLP->length)    {
            for (int i = SLP->length-1; i >= pos-1; --i)
            {
                SLP->data[i+1] = SLP->data[i];
            }
        }
        SLP->data[pos-1] = elem;
        SLP->length += 1;
    }
    return true;
}


/**
 * @brief delete the elem at pos in SqList
 * 
 * @param SLP the pointer of SqList
 * @param pos the position you want to delete
 * @return true :delete sucessfully
 * @return false :delete failed
 */
bool ListDelete(SqList* SLP, int pos)
{
    if (ListIsEmpty(*SLP))    {
        puts("The SqList is empty. Delete failed in function ListDelete().");
        return false;
    }
    else if (pos < 1 || pos > SLP->length)    {
        puts("The pos is out of bounds. Delete failed in function ListDelete().");
        return false;
    }
    else    {
        if (pos < SLP->length)    {
            for (int i = pos; i < SLP->length; ++i)
            {
                SLP->data[i-1] = SLP->data[i];
            }
        }
        SLP->length -= 1;
    }
    return true;
}


/**
 * @brief claer the SqList
 * 
 * @param SLP the pointer of SqList
 */
void ClearList(SqList** SLPP)
{
    free(*SLPP);
    *SLPP = NULL;
    return ;
}