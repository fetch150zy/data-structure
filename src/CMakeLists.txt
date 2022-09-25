add_library(data_structure_libs STATIC empty.c)

target_include_directories(data_structure_libs PUBLIC ${CMAKE_SOURCE_DIR}/include)

option(USE_LIST "use sequence list" OFF)
option(USE_LINK "use link list" OFF)
option(USE_STATIC_LINK "use static link list without point" OFF)

if(USE_LIST)
    target_compile_definitions(data_structure_libs INTERFACE "_LIST_")
    add_library(list list.c)
    target_link_libraries(data_structure_libs INTERFACE list)

elseif(USE_LINK)
    target_compile_definitions(data_structure_libs INTERFACE "_LINK_")
    add_library(link link.c)
    target_link_libraries(data_structure_libs INTERFACE link)

elseif(USE_STATIC_LINK)
    target_compile_definitions(data_structure_libs INTERFACE "_STATIC_LINK_")
    add_library(static_link static_link.c)
    target_link_libraries(data_structure_libs INTERFACE static_link)

endif()