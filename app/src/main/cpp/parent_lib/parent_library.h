//
// Created by wajahat on 25/08/2024.
//

#ifndef NATIVEBRIDGEPROJECT_PARENT_LIBRARY_H
#define NATIVEBRIDGEPROJECT_PARENT_LIBRARY_H
#include <string>

class ParentLibrary {
public:
    char * loadChildLibrary(const std::string& libPath);
    std::basic_string<char> executeChildFunction();
private:
    void* handle = nullptr;  // Pointer to the loaded library
    void (*childFunction)();  // Function pointer to child function
};

#endif //NATIVEBRIDGEPROJECT_PARENT_LIBRARY_H
