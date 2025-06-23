#include "TestFile.hpp"
#include <fstream>

namespace fs = std::filesystem;

std::map<std::string, std::string> TestFile::file_menu
{
    {"simple_file",
        "##fileformat=VCFv4.2\n"
        "##contig=<ID=1,length=1000000>\n"
        "##FORMAT=<ID=GT,Number=1,Type=String,Description=\"Genotype\">\n"
        "##FORMAT=<ID=DS,Number=1,Type=Float,Description=\"Genotype Dosage\">\n"
        "#CHROM\tPOS\tID\tREF\tALT\tQUAL\tFILTER\tINFO\tFORMAT\tsample1\tsample2\tsample3\n"
        "1\t123456\t.\tA\tG\t100\tPASS\t.\tGT:DS\t0|0:0.0\t0|1:1.0\t1|1:2.0\n"
        "1\t123789\t.\tC\tT\t99\tPASS\t.\tGT:DS\t0|1:0.8\t0|0:0.1\t1|1:1.9\n"
        "1\t200123\trs123\tG\tA\t300\tPASS\t.\tGT:DS\t1|1:0.2\t0|1:0.7\t1|0:1.1\n"
        "1\t250000\t.\tT\tC\t150\tPASS\t.\tGT:DS\t1|1:1.95\t0|0:0.05\t0|1:1.2\n"
    }

};


fs::path TestFile::get_tmp_file(std::string file_key)
{
    // Generate a unique file name
    fs::path temp_dir = fs::temp_directory_path();
    fs::path temp_file;
    do {
        temp_file = temp_dir / ("tmp_vcf_" + std::to_string(std::rand()) + ".vcf");
    } while (fs::exists(temp_file));

    // Write the VCF content
    std::ofstream out(temp_file);
    out << this->file_menu[file_key];
    out.close();

    return temp_file;

}
