#!/bin/bash

cd build

# for test list
cmake .. -DUSE_LIST=ON && make && ./res; rm -rf *

# for test link
cmake .. -DUSE_LINK=ON && make && ./res; rm -rf *

# for test static link
cmake .. -DUSE_STATIC_LINK=ON && make && ./res; rm -rf *