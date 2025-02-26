set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)       # Executables
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)       # Shared libraries (.so/.dylib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)       # Static libraries (.a/.lib)



cmake_minimum_required(VERSION 3.20)
project(TaskScheduler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



include_directories(${CMAKE_SOURCE_DIR}/include)


file(GLOB_RECURSE SOURCES "src/*.cpp")



add_library(TaskScheduler STATIC ${SOURCES})
add_executable(TaskSchedulerExec src/main.cpp)
target_link_libraries(TaskSchedulerExec PRIVATE TaskScheduler)


# Include directories
target_include_directories(TaskScheduler PUBLIC  ${CMAKE_SOURCE_DIR}/include)


install(TARGETS TaskScheduler
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)
