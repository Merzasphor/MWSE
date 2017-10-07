#pragma once

#include <windows.h>
#include <string>

class ModuleVersion
{
public:

    static ModuleVersion ModuleVersion::getModuleVersion(std::string &module)
    {
        return getModuleVersion(module.c_str());
    }
    static ModuleVersion getModuleVersion(const char *string);
    int getMajorVersion() const
    {
        return HIWORD(info.dwFileVersionMS);
    }
    int getMinorVersion() const
    {
        return LOWORD(info.dwFileVersionMS);
    }
    int getMajorBuild() const
    {
        return HIWORD(info.dwFileVersionLS);
    }
    int getMinorBuild() const
    {
        return LOWORD(info.dwFileVersionLS);
    }
    std::string getVersionString() const;
private:
    ModuleVersion(VS_FIXEDFILEINFO &info);
    VS_FIXEDFILEINFO info;
};
