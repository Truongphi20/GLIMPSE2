#pragma once

#include <string>
#include <map>
#include <filesystem>

class TestFile
{
    public:
    std::filesystem::path get_tmp_file(std::string file_name);

    private:
    static std::map<std::string, std::string> file_menu;

};