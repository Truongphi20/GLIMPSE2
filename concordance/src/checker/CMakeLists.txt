# Create checker library
add_library(ConcorChecker checker_finalise.cpp
                          checker_initialise.cpp
                          checker_management.cpp
                          checker_parameters.cpp
)

# Link to library
target_link_libraries(ConcorChecker PUBLIC Utils 
                                    PUBLIC Version_tools
                                    PUBLIC ConcorContainer
)

# Link to header files
target_include_directories(ConcorChecker  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})