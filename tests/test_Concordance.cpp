#include "checker_header.h"
#include "TestFile.hpp"

#include <gtest/gtest.h>

namespace fs = std::filesystem;

// COPY FROM concordance/src/concordance.cpp
// nt main(int argc, char ** argv) {
// 	std::vector < std::string > args;
// 	for (int a = 1 ; a < argc ; a ++) args.push_back(std::string(argv[a]));
// 	checker().check(args);
// 	return EXIT_SUCCESS;
// }


// Checking tmp file working normally.
TEST(Initial, test_create_tmp_vcf_file) {
  // Expected context
  std::string expected_context =  "##fileformat=VCFv4.2\n"
                                  "##contig=<ID=1,length=1000000>\n"
                                  "##FORMAT=<ID=GT,Number=1,Type=String,Description=\"Genotype\">\n"
                                  "##FORMAT=<ID=DS,Number=1,Type=Float,Description=\"Genotype Dosage\">\n"
                                  "#CHROM\tPOS\tID\tREF\tALT\tQUAL\tFILTER\tINFO\tFORMAT\tsample1\tsample2\tsample3\n"
                                  "1\t123456\t.\tA\tG\t100\tPASS\t.\tGT:DS\t0|0:0.0\t0|1:1.0\t1|1:2.0\n"
                                  "1\t123789\t.\tC\tT\t99\tPASS\t.\tGT:DS\t0|1:0.8\t0|0:0.1\t1|1:1.9\n"
                                  "1\t200123\trs123\tG\tA\t300\tPASS\t.\tGT:DS\t1|1:0.2\t0|1:0.7\t1|0:1.1\n"
                                  "1\t250000\t.\tT\tC\t150\tPASS\t.\tGT:DS\t1|1:1.95\t0|0:0.05\t0|1:1.2\n";

  // Get context of tmp file
  fs::path vcf_path = TestFile().get_tmp_file("simple_file");
  std::cout << "Temp VCF file created at: " << vcf_path << '\n';
  std::ifstream actual_file_flow(vcf_path);
  std::string actual_context((std::istreambuf_iterator<char>(actual_file_flow)), std::istreambuf_iterator<char>());
  actual_file_flow.close();

  // Clear tmp file
  fs::remove(vcf_path);

  // Check Expected context and actual context
  EXPECT_EQ(actual_context, expected_context);
}