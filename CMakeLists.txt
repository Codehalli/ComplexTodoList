
cmake_minimum_required(VERSION 3.5)
project(Proj1-NOTE CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NODE_SOURCE
node.hpp node.txx)

set(LIST_SOURCE
list.hpp list.txx)

set(SLIST_SOURCE
sorted_list.hpp sorted_list.txx)

set(TODO_SOURCE
todo.hpp todo.cpp)

set(TEST_SOURCE
student_tests.cpp)

set(SOURCE ${NODE_SOURCE} ${LIST_SOURCE} ${SLIST_SOURCE})

# create unittests
#add_executable(student-tests catch.hpp ${SOURCE} ${TEST_SOURCE})

# create todo
add_executable(note main.cpp ${SOURCE} ${TODO_SOURCE})

# some simple tests
#enable_testing()
#add_test(student-tests student-tests)

add_custom_target(submission COMMAND
${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
main.cpp todo.hpp todo.cpp list.txx sorted_list.txx
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
