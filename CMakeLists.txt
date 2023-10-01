cmake_minimum_required(VERSION 3.22)
project(C++School)

set(CMAKE_CXX_STANDARD 23)

add_executable(Main Lesson1/main.cpp)
add_executable(Calculator Lesson1/lecture01-calculator.cpp )
add_executable(HelloBuddy Lesson1/HelloBuddy1.cpp)
add_executable(Excercise3 Lesson1/Excercise3.cpp)
add_executable(Excercise4 Lesson1/Excercise4.cpp)
add_executable(Exercise5 Lesson1/Exercise5.cpp)

add_executable(Exercise21 Lesson2/Exercise21.cpp)
add_executable(Exercise22 Lesson2/Exercise22.cpp)
add_executable(Exercise23 Lesson2/Exercise23.cpp)
add_executable(Exercise24 Lesson2/Exercise24.cpp)

add_executable(Exercise31 Lesson3/Exercise31.cpp)
add_executable(Exercise32 Lesson3/Exercise32.cpp)
add_executable(Exercise33 Lesson3/Exercise33.cpp)
add_executable(Exercise331 Lesson3/Exercise331.cpp)

add_executable(Exercise41 Lesson4/Exercise41.cpp)
add_executable(Exercise42 Lesson4/Exercise42.cpp)

add_executable(Exercise51 Lesson5/Exercise51.cpp)
add_executable(Exercise52 Lesson5/Exercise52.cpp)
add_executable(Exercise53 Lesson5/Exercise53.cpp)