cmake_minimum_required(VERSION 3.16)
project(mini_soc_backend CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(mini_soc_backend src/main.cpp)

target_include_directories(mini_soc_backend PRIVATE
    ${PROJECT_SOURCE_DIR}/third_party
)

find_package(Threads REQUIRED)

target_link_libraries(mini_soc_backend PRIVATE
    Threads::Threads
)
