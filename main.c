/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// #define _LIST_
#define _LINK_

#ifdef _LIST_
#include "./include/list.h"
#endif
#ifdef _LINK_
#include "./include/link.h"
#endif

void TestList(void);
void TestLink(void);

int main(int argc, char** argv)
{
    #ifdef _LIST_
    TestList();
    #endif

    #ifdef _LINK_
    TestLink();
    #endif

    return 0;
}


#if defined(_LIS_)
/**
 * @brief test list
 */
void TestList(void)
{
    SqList* SLP = InitList();
    puts(ListIsEmpty(*SLP) ? "the SL is empty." : "the SL is not empty.");
    for (int i = 1; i <= 20; ++i)
    {
        ListInsert(SLP, i, i+100);
        printf("the length of SL is %zd.\n", ListLength(*SLP));
    }
    ListInsert(SLP, 3, 200);
    ListInsert(SLP, 23, 3);
    ListInsert(SLP, 22, 300);
    ListInsert(SLP, 0, 3);
    for (int i = 1; i <= ListLength(*SLP); ++i)
    {
        printf("%d ", GetElem(*SLP, i));
    }
    putchar('\n');
    ListDelete(SLP, 20);
    ListDelete(SLP, 0);
    ListDelete(SLP, 21);
    for (int i = 1; i <= ListLength(*SLP); ++i)
    {
        printf("%d ", GetElem(*SLP, i));
    }
    putchar('\n');
    ClearList(&SLP);            // free SLP
    printf("%p\n", SLP);

    return ;
}
#endif


#if defined(_LINK_)
/**
 * @brief test link list
 */
void TestLink(void)
{
    LinkListPtr LP = InitLink();
    puts(LinkIsEmpty(*LP) ? "empty." : "not empty");
    LP = CreateLinkListTail(10UL);
    for (int i = 1; i < 12; ++i)
    {
        printf("%d ", GetElem(*LP, i));
    }
    putchar('\n');
    LinkListInsert(&LP, 0, 1);
    LinkListInsert(&LP, 3, 3);
    LinkListInsert(&LP, 13, 11);
    for (int i = 1; i < 13; ++i)
    {
        printf("%d ", GetElem(*LP, i));
    }
    putchar('\n');

    ClearLinkList(&LP);
    puts(LinkIsEmpty(*LP) ? "empty." : "not empty");
}
#endif