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
// #define _LINK_
#define _STATIC_LINK_

#ifdef _LIST_
#include "./include/list.h"
#endif
#ifdef _LINK_
#include "./include/link.h"
#endif
#ifdef _STATIC_LINK_
#include "./include/static_link.h"
#endif

void TestList(void);
void TestLink(void);
void TestStaticLink(void);

int main(int argc, char** argv)
{
    #ifdef _LIST_
    TestList();
    #endif

    #ifdef _LINK_
    TestLink();
    #endif

    #ifdef _STATIC_LINK_
    TestStaticLink();
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


#if defined(_STATIC_LINK_)
/**
 * @brief test static link list
 */
void TestStaticLink(void)
{
    auto StaticLinkList SLL;
    InitStaticLinkList(SLL);
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        printf("data: %d cur: %d\n", SLL[i].data, SLL[i].cur);
    }

    printf("Length is: %d.\n", StaticLinkListLength(SLL));

    StaticLinkListInsert(SLL, 1, 100);
    StaticLinkListInsert(SLL, 2, 100);
    StaticLinkListInsert(SLL, 3, 100);
    StaticLinkListInsert(SLL, 20, 100);

    StaticLinkListDelete(SLL, 2);

    StaticLinkListInsert(SLL, 2, 200);

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        printf("data: %d cur: %d\n", SLL[i].data, SLL[i].cur);
    }

    printf("Length is: %d.\n", StaticLinkListLength(SLL));

    return ;
}
#endif