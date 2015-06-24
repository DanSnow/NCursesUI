CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "-std=gnu++11 -g -Wall")

include_directories(../../include)
add_executable(box box.cpp)
set_target_properties(box PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(box NCursesUI)

