CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(NCursesUI)

set(CMAKE_CXX_FLAGS "-g -std=gnu++11 -Wall")
include_directories(../include)

set(SRCS ncurses_app.cpp
         widget.cpp
         label.cpp
         box.cpp
         layout.cpp
         event.cpp
         key_down_event.cpp
         event_handler.cpp
         menu.cpp
         menu_item.cpp
)

add_library(NCursesUI ${SRCS})
set_target_properties(NCursesUI PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
target_link_libraries(NCursesUI ncurses)
