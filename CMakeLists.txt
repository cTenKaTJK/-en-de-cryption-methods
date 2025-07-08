cmake_minimum_required(VERSION 3.20)


set(PROJECT_NAME practice)
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)


add_executable("${PROJECT_NAME}" main.cpp diffie-hellman.hpp aes.hpp primes_and_pow.hpp rsa.hpp diffie-hellman.cpp aes.cpp primes_and_pow.cpp rsa.cpp)