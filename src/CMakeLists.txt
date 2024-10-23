cmake_minimum_required(VERSION 3.24)
project(zadanie-rekrutacyjne-cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)
