/**
 * @file test.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief for test
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include "test.h"



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


#elif defined(_LINK_STACK_)
/**
 * @brief test link stack
 * 
 */
void test_link_stack(void)
{
        struct linkStack *LSP = init_stack();
        for (int i = 1; i <= 10; ++i) {
                push(LSP, i + 100);
        }
        printf("%d\n", get_top_val(*LSP));
        for (int i = 1; i <= 5; ++i) {
                elemType elem;
                pop(LSP, &elem);
                printf("%d ", elem);
        }
        putchar('\n');
        printf("%d\n", get_top_val(*LSP));

        clear_stack(&LSP);
        printf("%p\n", LSP);
}



#elif defined(_QUEUE_)
/**
 * @brief test queue
 * 
 */
void test_queue(void)
{
        struct sqQueue *SQP = init_queue();
        printf("queue length : %zd\n", get_queue_length(*SQP));
        for (int i = 1; i <= 10; ++i) {
                enque(SQP, i + 100);
        }
        printf("front elements : %d\n", get_front_elem(*SQP));
        printf("back elements : %d\n", get_back_elem(*SQP));

        for (int i = 1; i <= 5; ++i) {
                elemType elem;
                deque(SQP, &elem);
                printf("%d ", elem);
        }
        putchar('\n');
        printf("front elements : %d\n", get_front_elem(*SQP));
        printf("back elements : %d\n", get_back_elem(*SQP));

        clear_queue(&SQP);
        printf("%p\n", SQP);
}



#elif defined(_LINK_QUEUE_)
/**
 * @brief test link queue
 * 
 */
void test_link_queue(void)
{
        struct linkQue *LQP = init_queue();
        printf("%zd\n", get_queue_length(*LQP));
        for (int i = 1; i <= 10; ++i)
                enque(LQP, i + 100);
        printf("%d %d\n", get_front_elem(*LQP), get_back_elem(*LQP));
        printf("%zd\n", get_queue_length(*LQP));

        for (int i = 1; i <= 5; ++i) {
                elemType elem;
                deque(LQP, &elem);
                printf("%d ", elem);
        }
        putchar('\n');
        printf("%d %d\n", get_front_elem(*LQP), get_back_elem(*LQP));
        printf("%zd\n", get_queue_length(*LQP));

        clear_queue(&LQP);
        printf("%p\n", LQP);
}


#elif defined(_STRING_)
/**
 * @brief test bf and kmp
 * 
 */
void test_string(void)
{
        struct string s, t;
        s.str = "abcabxxxxxabyzdscccc";
        s.length = 20;
        t.str = "abyzdsc";
        t.length = 7;
        printf("bf : %d\n", bf_match(s, t));
        printf("kmp : %d\n", kmp(s, t, 1));
        t.str = "xxxab";
        t.length = 5;
        printf("bf : %d\n", bf_match(s, t));
        printf("kmp : %d\n", kmp(s, t, 1));
        t.str = "abdc";
        t.length = 4;
        printf("bf : %d\n", bf_match(s, t));
        printf("kmp : %d\n", kmp(s, t, 1));
}


#elif defined(_BIN_TREE_)
/**
 * @brief test binary tree
 * 
 */
void test_bin_tree(void)
{
        struct biNode *tree = NULL;
        FILE *fp = fopen("../data/bitree.bin", "rb");
        init_tree(&tree, fp);
        printf("%p\n", tree);
        clear_tree(&tree);
        printf("%p\n", tree);

        getc(fp);
        init_tree(&tree, fp);
        pre_order_traverse(tree);
        putchar('\n');
        in_order_traverse(tree);
        putchar('\n');
        post_order_traverse(tree);
        putchar('\n');
        printf("nodes: %zd\n", get_bitree_nodes());
        printf("depth: %zd\n", get_bitree_depth(tree));
        clear_tree(&tree);
        printf("%p\n", tree);
        printf("nodes: %zd\n", get_bitree_nodes());
        printf("depth: %zd\n", get_bitree_depth(tree));
        
        getc(fp);
        init_tree(&tree, fp);
        pre_order_traverse(tree);
        putchar('\n');
        in_order_traverse(tree);
        putchar('\n');
        post_order_traverse(tree);
        putchar('\n');
        printf("nodes: %zd\n", get_bitree_nodes());
        printf("depth: %zd\n", get_bitree_depth(tree));
        clear_tree(&tree);
        printf("%p\n", tree);
        printf("nodes: %zd\n", get_bitree_nodes());
        printf("depth: %zd\n", get_bitree_depth(tree));

        fclose(fp);
}

#endif


