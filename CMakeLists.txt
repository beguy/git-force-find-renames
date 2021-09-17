cmake_minimum_required(VERSION 3.20)
project(git_proxy C)

set(CMAKE_C_STANDARD 11)

add_executable(git main.c)
add_executable(git.orig main2.c)
