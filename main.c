/**
 * @file main.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief just a test
 * @version 0.1
 * @date 2022-07-28
 *
 * @copyright Copyright (c) 2022
 *
 */



#if __STDC_VERSION__ != 201112L
#error Not C11
#endif



#ifdef _LIST_
#include "list.h"
#endif
#ifdef _LINK_
#include "link.h"
#endif
#ifdef _STATIC_LINK_
#include "static_link.h"
#endif
#ifdef _STACK_
#include "stack.h"
#endif



void test_list(void);
void test_link(void);
void test_static_link(void);
void test_stack(void);



int main(int argc, char **argv)
{
#ifdef _LIST_
        test_list();
#endif

#ifdef _LINK_
        test_link();
#endif

#ifdef _STATIC_LINK_
        test_static_link();
#endif

#ifdef _STACK_
        test_stack();
#endif

        return 0;
}



#if defined(_LIST_)
/**
 * @brief test list
 */
void test_list(void)
{
        struct sqList *SLP = init_list();
        for (int i = 1; i <= 20; ++i) {
                insert(SLP, i, i + 100);
                printf("the length of SL is %zd.\n", get_list_length(*SLP));
        }
        insert(SLP, 3, 200);
        insert(SLP, 23, 3);
        insert(SLP, 22, 300);
        insert(SLP, 0, 3);
        for (int i = 1; i <= get_list_length(*SLP); ++i)
                printf("%d ", get_element_val(*SLP, i));
        putchar('\n');
        delete (SLP, 20);
        delete (SLP, 0);
        delete (SLP, 21);
        for (int i = 1; i <= get_list_length(*SLP); ++i)
                printf("%d ", get_element_val(*SLP, i));
        putchar('\n');
        printf("%d\n", get_element_index(*SLP, 102));
        printf("%d\n", get_element_index(*SLP, 12));
        clear_list(&SLP); // free SLP
        printf("%p\n", SLP);

        return;
}



#elif defined(_LINK_)
/**
 * @brief test link list
 */
void test_link(void)
{
        struct linkList *LP = tail_create(10UL);
        for (int i = 1; i < 12; ++i)
                printf("%d ", get_element_val(*LP, i));
        putchar('\n');
        insert(LP, 0, 1);
        insert(LP, 3, 3);
        insert(LP, 13, 11);
        for (int i = 1; i < 12; ++i)
                printf("%d ", get_element_val(*LP, i));
        putchar('\n');

        clear_link(&LP);
        printf("%p\n", LP);
}



#elif defined(_STATIC_LINK_)
/**
 * @brief test static link list
 */
void test_static_link(void)
{
        auto struct node SLL[MAX_SIZE];
        init_static_link(SLL);
        for (int i = 0; i < MAX_SIZE; ++i)
                printf("data: %d cur: %d\n", SLL[i].data, SLL[i].cur);

        printf("Length is: %d.\n", get_static_link_length(SLL));

        insert(SLL, 1, 100);
        insert(SLL, 2, 100);
        insert(SLL, 3, 100);
        insert(SLL, 20, 100);

        delete(SLL, 2);

        insert(SLL, 2, 200);

        for (int i = 0; i < MAX_SIZE; ++i)
                printf("data: %d cur: %d\n", SLL[i].data, SLL[i].cur);

        printf("Length is: %d.\n", get_static_link_length(SLL));

        return;
}




#elif defined(_STACK_)
/**
 * @brief test stack
 * 
 */
void test_stack(void)
{
        struct sqStack *SP = init_stack();
        printf("stack 1 is %s\n", is_empty_stack(*SP, left_stack) ? "empty" : "not empty");
        printf("stack 2 is %s\n", is_empty_stack(*SP, right_stack) ? "empty" : "not empty");
        for (int i = 1; i <= 10; ++i) {
                push(SP, i + 100, left_stack);
                push(SP, i + 200, right_stack);
        }
        printf("stack 1 is %s\n", is_empty_stack(*SP, left_stack) ? "empty" : "not empty");
        printf("stack 2 is %s\n", is_empty_stack(*SP, right_stack) ? "empty" : "not empty");

        printf("%d\n", get_top_elem(*SP, left_stack));
        printf("%d\n", get_top_elem(*SP, right_stack));

        for (int i = 1; i <= 5; ++i) {
                elemType elem;
                pop(SP, &elem, left_stack);
                printf("%d ", elem);
        }
        printf("\n%d\n", get_top_elem(*SP, left_stack));

        for (int i = 1; i <= 5; ++i) {
                elemType elem;
                pop(SP, &elem, right_stack);
                printf("%d ", elem);
        }
        printf("\n%d\n", get_top_elem(*SP, right_stack));

        clear_stack(&SP);
        printf("%p\n", SP);
        return;
}

#endif