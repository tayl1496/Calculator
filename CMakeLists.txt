project(Project_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

add_executable(proj4 Main.cpp infix.cpp DividByZero.cpp)
