cmake_minimum_required(VERSION 3.22)
project(Trabalho___Simulador_de_Aeroporto C)

set(CMAKE_C_STANDARD 11)

add_executable(Trabalho___Simulador_de_Aeroporto main.c "Trabalho - Simulador de Aeroporto.h" CriarAviao.c ATERRISSAR.c DECOLAR.c)
