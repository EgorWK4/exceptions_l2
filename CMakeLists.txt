cmake_minimum_required(VERSION 3.16)
project(exceptions_l2)
set(CMAKE_CXX_STANDARD 20)


add_executable(exceptions_l2 main.cpp clothes.h shop.h customer.h interface.h exceptions_handling.h customer.cpp clothes.cpp shop.cpp file_writing.h utility_fun.h)