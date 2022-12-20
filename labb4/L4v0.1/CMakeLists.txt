cmake_minimum_required(VERSION 3.23)
project(L4v0_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(L4v0_1 main.cpp Email.h Email.cpp MailBox.cpp MailBox.h)
