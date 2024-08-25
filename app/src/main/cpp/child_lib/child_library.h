//
// Created by wajahat on 25/08/2024.
//

#ifndef NATIVEBRIDGEPROJECT_CHILD_LIBRARY_H
#define NATIVEBRIDGEPROJECT_CHILD_LIBRARY_H
#include <iostream>

extern "C" {
std::basic_string<char> display_message();
}

// child_lib.cpp

extern "C" const char* getStringFromChildLib() {
    return "Hello from Child Library!YEAH";
}


#endif //NATIVEBRIDGEPROJECT_CHILD_LIBRARY_H
