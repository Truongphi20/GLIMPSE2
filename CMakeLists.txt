cmake_minimum_required(VERSION 3.14)
project(GLIMPSE2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add modules
add_subdirectory(concordance)

# Switch Test modules or run main
option(TEST "DO GTEST" OFF)
if (TEST)
    # Run tests
    add_subdirectory(tests)
else()
    # Create main exe
    add_executable(glimpse2 main.cpp)
    
    # Link to library
    target_link_libraries(glimpse2  Concordance)
endif()