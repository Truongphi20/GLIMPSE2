include(FetchContent)

# Invoke Gtest
fetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Set up test_Concordance
add_executable(test_Concordance test_Concordance.cpp TestFile.cpp)
target_link_libraries(test_Concordance GTest::gtest_main Concordance)
add_test(NAME test_Concordance COMMAND test_Concordance)

# Set up test_Chunk