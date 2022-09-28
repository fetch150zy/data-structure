#ifndef TEXT_H_
#define TEXT_H_




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
#ifdef _LINK_STACK_
#include "link_stack.h"
#endif
#ifdef _QUEUE_
#include "queue.h"
#endif



void test_list(void);
void test_link(void);
void test_static_link(void);
void test_stack(void);
void test_link_stack(void);
void test_queue(void);







#endif