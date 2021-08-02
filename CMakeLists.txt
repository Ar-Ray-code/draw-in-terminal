cmake_minimum_required(VERSION 2.8)
project(test_cmake CXX)

add_executable(draw_in_terminal main.cpp)

find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    target_include_directories(draw_in_terminal PUBLIC ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(draw_in_terminal ${OpenCV_LIBS})
    # Install bin
    install(TARGETS draw_in_terminal DESTINATION /usr/local/bin)
endif()
