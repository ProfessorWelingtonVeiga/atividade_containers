cmake_minimum_required(VERSION 3.6)
project(teste)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



set(SOURCE_FILES main.c containers.h containers.c entrada_saida.h entrada_saida.c)
add_executable(teste ${SOURCE_FILES})

target_link_libraries(teste m)