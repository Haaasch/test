cmake_minimum_required(VERSION 3.27)
project(Iteratoren)

set(CMAKE_CXX_STANDARD 17)

add_executable(Iteratoren main.cpp
        WordCounter.h
        tokenizer.h)
