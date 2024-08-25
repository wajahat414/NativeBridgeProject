#include "child_library.h"
#include <iostream>

std::basic_string<char> display_message() {
    std::cout << "Hello from the Child Library!" << std::endl;
    std::string hellodFromChild = "Hello from Child Function";
    return hellodFromChild;
}
