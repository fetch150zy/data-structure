#ifndef TEXT_H_
#define TEXT_H_


#include "test.h"


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


extern void test_list(void);
extern void test_link(void);
extern void test_static_link(void);
extern void test_stack(void);
extern void test_link_stack(void);
extern void test_queue(void);


#endif

