/**
 * @file static_link.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/static_link.h"



/**
 * @brief initialize the static link list
 * 
 * @param SLL array(memory space) of static link list
 */
void InitStaticLinkList(StaticLinkList SLL)
{
    for (int i = 0; i < MAX_SIZE - 1; ++i)
    {
        SLL[i].data = -1;
        SLL[i].cur = i + 1;
    }
    // Currently the static link list is empty. The cur of the last element is 0
    SLL[MAX_SIZE - 1].cur = 0;
    SLL[MAX_SIZE - 1].data = -1;
    return ;
}


/**
 * @brief implement the malloc in static link list
 * 
 * @param SLL array(memory space) of static link list
 * @return int :assigned node index
 */
int MallocInStaticLinkList(StaticLinkList SLL)
{
    auto int cur = SLL[0].cur;
    if (0 != cur)    {
        SLL[0].cur = SLL[cur].cur;
    }
    return cur;
}


/**
 * @brief get length of static link list
 * 
 * @param SLL array(memory space) of static link list
 * @return int :the length of static link list
 */
int StaticLinkListLength(StaticLinkList SLL)
{
    auto int length = 0;
    auto int cur = SLL[MAX_SIZE - 1].cur;
    while (0 != cur)
    {
        cur = SLL[cur].cur;
        length++;
    }
    return length;
}



/**
 * @brief implement insert node in static link list
 * 
 * @param SLL array(memory space) of static link list
 * @param cur the node index you want to insert
 * @param elem the elem you want to insert
 * @return true :insert sucessfully
 * @return false :insert failed
 */
bool StaticLinkListInsert(StaticLinkList SLL, int cur, elemType elem)
{
    if (cur < 1 || cur > StaticLinkListLength(SLL) + 1)    {
        puts("\nThe cursor is out of bounds. Insert error in function StaticLinkListInsert().");
        return false;
    }
    auto int next = MAX_SIZE - 1, freeCur = MallocInStaticLinkList(SLL);
    if (0 != freeCur)    {
        SLL[freeCur].data = elem;
        for (int i = 1; i < cur; ++i)
        {
            next = SLL[next].cur;
        }
        SLL[freeCur].cur = SLL[next].cur;
        SLL[next].cur = freeCur;
        return true;
    }
    puts("\nSomething wrong in function StaticLinkListInsert().");
    return false;
}


/**
 * @brief implement free in static link list
 * 
 * @param SLL array(memory space) of static link list
 * @param cur the node index you want to free
 */
void FreeInStaticLinkList(StaticLinkList SLL, int cur)
{
    SLL[cur].data = -1;
    SLL[cur].cur = SLL[0].cur;
    SLL[0].cur = cur;
    return ;
}


/**
 * @brief implement delete node in static link list
 * 
 * @param SLL array(memory space) of static link list
 * @param cur the node index you want to delete
 * @return true :delete sucessfully
 * @return false :delate failed
 */
bool StaticLinkListDelete(StaticLinkList SLL, int cur)
{
    if (cur < 1 || cur > StaticLinkListLength(SLL))    {
        puts("\nThe cursor is out of bounds. Delete error in function StaticLinkListDelete().");
        return false;
    }
    auto int next = MAX_SIZE - 1;
    for (int i = 1; i < cur; ++i)
    {
         next = SLL[next].cur;
    }
    auto int current = SLL[next].cur;
    SLL[next].cur = SLL[current].cur;
    FreeInStaticLinkList(SLL, current);
    return true;
}