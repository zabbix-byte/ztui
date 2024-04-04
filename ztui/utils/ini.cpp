#include "ini.h"


mINI::INIStructure INI::read(const std::string& file_path)
{
    mINI::INIFile file(file_path);
    mINI::INIStructure ini;
    file.read(ini);
    return ini;
}


void INI::write(const std::string& file_path, mINI::INIStructure ini_structure)
{
    mINI::INIFile file(file_path);
    file.write(ini_structure);
}