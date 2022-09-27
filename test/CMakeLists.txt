add_library(test STATIC test.c)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/test)

target_link_libraries(test PUBLIC
                     ${LIBS}
                     )