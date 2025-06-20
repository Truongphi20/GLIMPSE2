# Create container library
add_library(ConcorContainer call_set_management.cpp
                            call_set_reading.cpp
                            call_set_writing.cpp
)

# Link to header files
target_include_directories(ConcorContainer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})