cmake_minimum_required(VERSION 3.5)
project(Lab3_MC)

set(CMAKE_CXX_STANDARD 17)

add_library(mura_machine STATIC src/mura_machine.cpp)

target_include_directories(mura_machine PUBLIC ${PROJECT_SOURCE_DIR}/src/include)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} mura_machine)