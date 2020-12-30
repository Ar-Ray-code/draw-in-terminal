cmake_minimum_required(VERSION 2.8)
project(test_cmake CXX)

add_executable(draw_on_terminal main.cpp)

find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    target_include_directories(draw_on_terminal PUBLIC ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(draw_on_terminal ${OpenCV_LIBS})
endif()