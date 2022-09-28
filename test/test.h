#ifndef TEST_H_
#define TEST_H_


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
#ifdef _LINK_QUEUE_
#include "link_queue.h"
#endif
#ifdef _STRING_
#include "string.h"
#endif
#ifdef _BIN_TREE_
#include "binary_tree.h"
#endif


extern void test_list(void);
extern void test_link(void);
extern void test_static_link(void);
extern void test_stack(void);
extern void test_link_stack(void);
extern void test_queue(void);
extern void test_link_queue(void);
extern void test_string(void);
extern void test_bin_tree(void);


#endif

