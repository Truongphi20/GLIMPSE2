#include "checker_header.h"

#include <gtest/gtest.h>

// COPY FROM concordance/src/concordance.cpp
// nt main(int argc, char ** argv) {
// 	std::vector < std::string > args;
// 	for (int a = 1 ; a < argc ; a ++) args.push_back(std::string(argv[a]));
// 	checker().check(args);
// 	return EXIT_SUCCESS;
// }


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}