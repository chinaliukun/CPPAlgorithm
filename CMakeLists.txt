cmake_minimum_required(VERSION 3.17)

project(CPPAlgorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories("./DataStructure")
add_executable(CPPAlgorithmMain main.cpp )
add_executable(LinkListUseCase UseCase/LinkListUseCase.cpp )
