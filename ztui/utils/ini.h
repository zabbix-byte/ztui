#pragma once
#include "mini.h"


namespace INI
{
    mINI::INIStructure read(const std::string& file_path);
    void write(const std::string& file_path, mINI::INIStructure ini_structure);
}