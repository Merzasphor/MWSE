#include "ModuleVersion.h"

#include <sstream>

ModuleVersion ModuleVersion::getModuleVersion(const char *module)
{
    DWORD dwUseless;

    int length = GetFileVersionInfoSize(module, &dwUseless);
    if (length == 0) {
        throw new std::string("Could not get version info size");
    }

    void *data = alloca(length);
    VS_FIXEDFILEINFO *versionBlock;
    UINT returnedSize;

    GetFileVersionInfo(module, NULL, length, data);
    // Get root block. This is VS_FIXEDFILEINFO data.
    if (!VerQueryValue(data, "\\", reinterpret_cast<LPVOID *>(&versionBlock), &returnedSize)) {
        throw new std::string("Could not get fixed version info");
    }
    return ModuleVersion(*versionBlock);
}

ModuleVersion::ModuleVersion(VS_FIXEDFILEINFO &ctor_info):
    info(ctor_info)
{
}
 
std::string ModuleVersion::getVersionString() const
{
    std::ostringstream out;
    out << getMajorVersion() << "." << getMinorVersion() <<
        "." << getMajorBuild() << "." << getMinorBuild();
    return out.str();
}
