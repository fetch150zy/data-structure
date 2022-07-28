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

#include <stdio.h>
#define _LIST_

#ifdef _LIST_
#include "./include/list.h"
#endif

void test_list(void);

int main(int argc, char** argv)
{
    #ifdef _LIST_
    test_list();
    #endif

    return 0;
}

/**
 * @brief test list
 */
void test_list(void)
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