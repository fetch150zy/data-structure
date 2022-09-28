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



#include "test.h"



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

#ifdef _LINK_STACK_
        test_link_stack();
#endif

#ifdef _QUEUE_
        test_queue();
#endif

#ifdef _LINK_QUEUE_
        test_link_queue();
#endif

#ifdef _STRING_
        test_string();
#endif

        return 0;
}


