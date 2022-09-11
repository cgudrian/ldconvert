cmake_minimum_required(VERSION 3.14)

project(ldconvert LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(ldconvert
  main.cpp
)
target_link_libraries(ldconvert Qt6::Core)

install(TARGETS ldconvert
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
