#!/bin/bash

cd build

# for test list
echo -e "\n***********************************************\n*"
echo -e "*\n*              Test list                     *\n*"
echo -e "*\n***********************************************\n"
cmake .. -DUSE_LIST=ON && make && ./res; rm -rf *


# for test link
echo -e "\n***********************************************\n*"
echo -e "*\n*              Test link                     *\n*"
echo -e "*\n***********************************************\n"
cmake .. -DUSE_LINK=ON && make && ./res; rm -rf *


# for test static link
echo -e "\n***********************************************\n*"
echo -e "*\n*           Test static link                 *\n*"
echo -e "*\n***********************************************\n"
cmake .. -DUSE_STATIC_LINK=ON && make && ./res; rm -rf *


# for test stack
echo -e "\n***********************************************\n*"
echo -e "*\n*              Test stack                    *\n*"
echo -e "*\n***********************************************\n"
cmake .. -DUSE_STACK=ON && make && ./res; rm -rf *