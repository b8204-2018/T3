#include <iostream>
#include "src/base64.h"
#include "string.h"

int main() {
    std::cout << encode((const char *) "They were great people with huge flaws") << std::endl;
    std::cout << decode((const char *) "VGhleSB3ZXJlIGdyZWF0IHBlb3BsZSB3aXRoIGh1Z2UgZmxhd3M=") << std::endl;
    return 0;
}