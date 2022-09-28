add_library(data_structure_libs STATIC empty.c)

target_include_directories(data_structure_libs PUBLIC ${CMAKE_SOURCE_DIR}/include)


function(op_link op_macro c_macro src)
        if(${op_macro})
                target_compile_definitions(data_structure_libs INTERFACE ${c_macro})
                add_library(final_lib ${src})
                target_link_libraries(data_structure_libs INTERFACE final_lib)
        endif(${op_macro})
endfunction(op_link)


option(USE_LIST "use sequence list" OFF)
option(USE_LINK "use link list" OFF)
option(USE_STATIC_LINK "use static link list without point" OFF)
option(USE_STACK "use stack" OFF)
option(USE_LINK_STACK "use link stack" OFF)
option(USE_QUEUE "use queue" OFF)
option(USE_LINK_QUEUE "use link queue" OFF)

set(op_list USE_LIST USE_LINK USE_STATIC_LINK USE_STACK USE_LINK_STACK USE_QUEUE USE_LINK_QUEUE USE_STRING USE_BIN_TREE)
set(macro_list "_LIST_" "_LINK_" "_STATIC_LINK_" "_STACK_" "_LINK_STACK_" "_QUEUE_" "_LINK_QUEUE_" "_STRING_" "_BIN_TREE_")
set(src_list "list.c" "link.c" "static_link.c" "stack.c" "link_stack.c" "queue.c" "link_queue.c" "string.c" "binary_tree.c")

foreach(item IN ZIP_LISTS op_list macro_list src_list)
        op_link(${item_0} ${item_1} ${item_2})
endforeach()


