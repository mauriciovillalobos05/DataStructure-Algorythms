cmake_minimum_required(VERSION 3.29)
project(matricesAdyacentes)

set(CMAKE_CXX_STANDARD 20)

add_executable(matricesAdyacentes main.cpp
        LoadBalancer.h
        LoadBalancer.cpp)
