# Create concordance library
add_library(Concordance INTERFACE)

# Create utils package
add_library(Utils INTERFACE)
target_include_directories(Utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils)

# Link packages
find_package(Boost REQUIRED COMPONENTS program_options)

# Add directories
add_subdirectory(src/checker)
add_subdirectory(src/containers)


# Link to libraries
target_link_libraries(Concordance INTERFACE ConcorChecker 
                                  INTERFACE ConcorContainer
                                  INTERFACE Boost::program_options
)


