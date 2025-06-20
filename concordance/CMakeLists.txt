# Create concordance library
add_library(Concordance INTERFACE)

# Add directories
add_subdirectory(src/checker)
add_subdirectory(src/containers)

# Link to libraries
target_link_libraries(Concordance INTERFACE ConcorChecker 
                                  INTERFACE ConcorContainer
)

# Link to implement header files
target_link_directories(Concordance INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/utils)


