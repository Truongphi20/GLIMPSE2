#include "TestFile.hpp"
#include <fstream>
#include <htslib/bgzf.h>
#include <htslib/tbx.h>
#include <iostream>

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
    },
    {"simple_pos_file",
        "##fileformat=VCFv4.2\n"
        "##contig=<ID=1,length=1000000>\n"
        "##FORMAT=<ID=GT,Number=1,Type=String,Description=\"Genotype\">\n"
        "##FORMAT=<ID=DS,Number=1,Type=Float,Description=\"Genotype Dosage\">\n"
        "#CHROM\tPOS\tID\tREF\tALT\tQUAL\tFILTER\tINFO\tFORMAT\tsample1\tsample2\tsample3\n"
        "1\t123456\t.\tA\tG\t100\tPASS\t.\tGT:DS\t0|0:0.0\t0|1:1.0\t1|1:2.0\n"
        "1\t123789\t.\tC\tT\t99\tPASS\t.\tGT:DS\t0|1:0.8\t0|0:0.1\t1|1:1.9\n"
        "1\t200123\trs123\tG\tA\t300\tPASS\t.\tGT:DS\t1|1:0.2\t0|1:0.7\t1|0:1.1\n"
        "1\t250000\t.\tT\tC\t150\tPASS\t.\tGT:DS\t1|1:1.95\t0|0:0.05\t0|1:1.2\n"
        "1\t260000\t.\tA\tC\t150\tPASS\t.\tGT:DS\t0|1:1.55\t1|0:0.15\t1|1:1.5\n"
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

fs::path TestFile::create_tmp_file(std::string file_context, std::string prefix)
{
    // Generate a unique file name
    fs::path temp_dir = fs::temp_directory_path();
    fs::path temp_file;
    do {
        temp_file = temp_dir / ("tmp_test" + std::to_string(std::rand()) + prefix);
    } while (fs::exists(temp_file));

    // Write the VCF content
    std::ofstream out(temp_file);
    out << file_context;
    out.close();

    return temp_file;
}


fs::path TestFile::get_tmp_vcf_file(std::string file_key)
{
    // Step 1: Generate a unique .vcf.gz path
    fs::path temp_dir = fs::temp_directory_path();
    fs::path temp_file;
    do {
        temp_file = temp_dir / ("tmp_vcf_" + std::to_string(std::rand()) + ".vcf.gz");
    } while (fs::exists(temp_file));

    // Step 2: Write compressed (bgzipped) content using HTSlib's BGZF
    BGZF* out = bgzf_open(temp_file.c_str(), "w");
    if (!out) {
        throw std::runtime_error("Failed to open BGZF file for writing: " + temp_file.string());
    }

    const std::string& content = this->file_menu[file_key];
    if (bgzf_write(out, content.data(), content.size()) < 0) {
        bgzf_close(out);
        throw std::runtime_error("Failed to write BGZF content");
    }

    bgzf_close(out);

    // Step 3: Index the .vcf.gz file
    int ret = tbx_index_build(temp_file.c_str(), 0, &tbx_conf_vcf);
    if (ret != 0) {
        throw std::runtime_error("Failed to index VCF: " + temp_file.string());
    }

    return temp_file;
}