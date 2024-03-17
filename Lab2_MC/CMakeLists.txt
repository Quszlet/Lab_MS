cmake_minimum_required(VERSION 3.5)
project(Lab2_MC)

set(CMAKE_CXX_STANDARD 17)

add_library(runge_kutta STATIC src/runge_kutta/runge_kutta.cpp)

target_include_directories(runge_kutta PUBLIC ${PROJECT_SOURCE_DIR}/src/include)

find_package(sciplot REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} runge_kutta)