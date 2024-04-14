cmake_minimum_required(VERSION 3.5)
project(Lab5_MC)

set(CMAKE_CXX_STANDARD 17)

add_library(runge_kutta STATIC src/runge_kutta/runge_kutta.cpp)
add_library(markov_process_ds_ct STATIC src/markov_process_ds_ct/markov_process_ds_ct.cpp)

target_include_directories(runge_kutta PUBLIC ${PROJECT_SOURCE_DIR}/src/include)
target_include_directories(markov_process_ds_ct PUBLIC ${PROJECT_SOURCE_DIR}/src/include)

add_executable(${PROJECT_NAME} src/main.cpp )

target_link_libraries(${PROJECT_NAME} markov_process_ds_ct runge_kutta)
