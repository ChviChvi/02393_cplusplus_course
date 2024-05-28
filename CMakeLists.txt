cmake_minimum_required(VERSION 3.22)
project(C++School__)

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

add_executable(Exercise61 Lesson6/Exercise61.cpp)
add_executable(shapes Lesson8/shapes.cpp)
add_executable(Test01 Lesson8/Test01.cpp)
add_executable(Test02 Lesson8/Test02.cpp)

add_executable(TheLevenshteindistance Lesson9/TheLevenshteindistance.cpp)
add_executable(Palindrome Lesson9/Palindrome.cpp)
add_executable(Fibonacci Lesson9/Fibonacci.cpp)
add_executable(Reverse Lesson9/Reverse.cpp)

add_executable(FibonacciTree Lesson11/FibonacciTree.cpp)


add_executable(ex01 "Exam2020-December(✔)/ex01/ex01-main.cpp" "Exam2020-December(✔)/ex01/ex01-library.cpp")
add_executable(ex02 "Exam2020-December(✔)/ex02/ex02-main.cpp" "Exam2020-December(✔)/ex02/ex02-library.cpp")
add_executable(ex03 "Exam2020-December(✔)/ex03/ex03-main.cpp" "Exam2020-December(✔)/ex03/ex03-library.cpp")
add_executable(ex04 "Exam2020-December(✔)/ex04/ex04-main.cpp" "Exam2020-December(✔)/ex04/ex04-library.cpp")

add_executable(Exam2022-May-ex01 "Exam2022-May/ex01/ex01-main.cpp" "Exam2022-May/ex01/ex01-library.cpp")
add_executable(Exam2022-May-ex02 "Exam2022-May/ex02/ex02-main.cpp" "Exam2022-May/ex02/ex02-library.cpp")
add_executable(Exam2022-May-ex03 "Exam2022-May/ex03/ex03-main.cpp" "Exam2022-May/ex03/ex03-library.cpp")
add_executable(Exam2022-May-ex04 "Exam2022-May/ex04/ex04-main.cpp" "Exam2022-May/ex04/ex04-library.cpp")