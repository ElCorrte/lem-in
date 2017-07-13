cmake_minimum_required(VERSION 3.7)
project(lem_in)

set(CMAKE_C_STANDARD 99)

file(GLOB lem-in_SRC "./*.c" "./libft/*.c")
add_executable(lem_in ${lem-in_SRC})
set(LIBFT libft/libft.a)
target_link_libraries(lem_in ${CMAKE_SOURCE_DIR}/${LIBFT})