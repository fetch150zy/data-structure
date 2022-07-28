/**
 * @file link.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/link.h"
#include <stdlib.h>


/**
 * @brief initialize link list
 * 
 * @return LinkList :the pointer of head node
 */
LinkListPtr InitLink(void)
{
    auto LinkListPtr HP = (LinkListPtr)malloc(sizeof(LinkList));
    HP->next = NULL;
    return HP;
}


/**
 * @brief check if the link list is empty
 * 
 * @param L link list variable
 * @return true :link list is empty
 * @return false :link list is not empty
 */
bool LinkIsEmpty(LinkList L)
{
    return (NULL == L.next);
}


/**
 * @brief get the elem at pos in link list
 * 
 * @param L LinkList variable
 * @param pos the pos you want to get element
 * @return elemType :the val at pos in link list
 */
elemType GetElem(LinkList L, int pos)
{
    auto LinkListPtr p = L.next;
    auto int cnt = 1;
    while (NULL != p && cnt < pos)
    {
        p = p->next;
        cnt++;
    }
    if (NULL == p || cnt > pos)    {
        puts("\nGet element error in function GetElem().");
        return ERROR_VAL;
    }
    return p->data;
}


/**
 * @brief insert elem at pos in link list
 * 
 * @param LPP the double pointer of link list
 * @param pos position you want to insert
 * @param elem element you want to insert
 * @return true :insert sucessfully
 * @return false :insert failed
 */
bool LinkListInsert(LinkListPtr* LPP, int pos, elemType elem)
{
    auto LinkListPtr p = *LPP;
    auto int cnt = 1;
    while (NULL != p && cnt < pos)
    {
        p = p->next;
        cnt++;
    }
    if (NULL == p || cnt > pos)    {
        puts("\nInsert element error in function LinkListInsert().");
        return false;
    }
    auto LinkListPtr temp = (LinkListPtr)malloc(sizeof(LinkList));
    temp->data = elem;
    temp->next = p->next;
    p->next = temp;
    return true;
}


/**
 * @brief delete elem at pos in link list
 * 
 * @param LPP the double pointer of link list
 * @param pos position you want to delete
 * @return true :delete sucessfully
 * @return false :delete failed
 */
bool LinkListDelete(LinkListPtr* LPP, int pos)
{
    auto LinkListPtr p = *LPP;
    auto int cnt = 1;
    while (NULL != p->next && cnt < pos)
    {
        p = p->next;
        cnt++;
    }
    if (NULL == p->next || cnt > pos)    {
        puts("\nDelete element error in function LinkListDelete().");
        return false;
    }

    auto LinkListPtr temp = p->next;
    p->next = temp->next;
    free(temp);
    return true;
}



/**
 * @brief create a link list by heading insert
 * 
 * @param size link list's size
 * @return LinkListPtr :the head pointer of link list
 */
LinkListPtr CreateLinkListHead(size_t size)
{
    auto LinkListPtr HP = (LinkListPtr)malloc(sizeof(LinkList));
    HP->next = NULL;
    for (auto size_t i = 0; i < size; ++i)
    {
        auto LinkListPtr p = (LinkListPtr)malloc(sizeof(LinkList));
        p->data = i + 100;
        p->next = HP->next;
        HP->next = p;
    }
    return HP;
}


/**
 * @brief create a linkList by tailing insert
 * 
 * @param size link list's size
 * @return LinkListPtr :the head pointer of link list
 */
LinkListPtr CreateLinkListTail(size_t size)
{
    auto LinkListPtr HP = (LinkListPtr)malloc(sizeof(LinkList));
    auto LinkListPtr temp = HP;
    HP->next = NULL;
    for (auto size_t i = 0; i < size; ++i)
    {
        auto LinkListPtr p = (LinkListPtr)malloc(sizeof(LinkList));
        p->data = i + 100;
        temp->next = p;
        temp = p;    
    }
    temp->next = NULL;
    return HP;
}


/**
 * @brief clear the whole link list(free all node)
 * 
 * @param LPP the double pointer of link list
 * @return true :free sucessfully
 * @return false :free failed
 */
bool ClearLinkList(LinkListPtr* LPP)
{
    auto LinkListPtr p = (*LPP)->next, q;

    while (NULL != p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*LPP)->next = NULL;
    return true;
}