cmake_minimum_required(VERSION 3.14)
project(GLIMPSE2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set Policy
cmake_policy(SET CMP0167 NEW)

# Define Git information
execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE __COMMIT_ID__
    OUTPUT_STRIP_TRAILING_WHITESPACE
) 

execute_process(
    COMMAND git log -1 --format=%cd --date=short
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE __COMMIT_DATE__
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

configure_file(
    ${CMAKE_SOURCE_DIR}/versions/versions.h.in
    ${CMAKE_BINARY_DIR}/versions/versions.h
)

# Create Version packages
add_library(Version_tools INTERFACE)
target_include_directories(Version_tools INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/versions)


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