#include <iostream>
#include <cstring>
#include "src/base64.hpp"
#include "gtest/gtest.h"

using namespace std;

const char OPT_ENCODE[] = "-e";
const char OPT_DECODE[] = "-d";

int main(int argc, char *argv[]) {

    if (argc == 1 || argc > 3) {
        throw std::invalid_argument("No arguments provided"); //создаем свое исключение
    }

    if (argc == 2) {
        std::cout << base64_encode(argv[1]);
    }

    if (argc == 3) {
        size_t i = 1;
        if (strcmp(OPT_ENCODE, argv[i++]) == 0 || strcmp(OPT_ENCODE, argv[i--]) == 0) {
            std::cout << base64_encode(argv[i]);
        } else if (strcmp(OPT_DECODE, argv[i++]) == 0 || strcmp(OPT_DECODE, argv[i--]) == 0) {
            std::cout << base64_decode(argv[i]);
        }
    }

    return 0;
}