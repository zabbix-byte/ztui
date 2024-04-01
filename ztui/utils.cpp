#include <windows.h>
#include <string>
#include "utils.h"
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

TCHAR* exe_path(TCHAR* dest, size_t dest_size) {
    if (!dest) return NULL;
    if (MAX_PATH > dest_size) return NULL;

    DWORD length = GetModuleFileName(NULL, dest, dest_size);
    PathRemoveFileSpec(dest);
    return dest;
}