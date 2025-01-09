cmake_minimum_required(VERSION 3.10)

# Set the project name
project(KyleKalendar)

# Add the executable
add_executable(KyleKalendar src/main.cpp)

# Add in directory to store events and toDos
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Release/events) 
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Release/toDos) 
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Debug/events) 
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Debug/toDos) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})