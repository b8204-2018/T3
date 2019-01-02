#include <iostream>
#include "src/base64.hpp"
#include "gtest/gtest.h"

const char OPT_ENCODE[] = "-e";
const char OPT_DECODE[] = "-d";

/*
 * Тест не собирается.
 * Куча ошибок:
 * https://gist.github.com/SpiderKisa/4c28a2a5202b9cee46068c1e46cc24e1
 * */
TEST(TEST_Base64, Encode) {
    EXPECT_STREQ("RWwgUHN5IENvbmdyb28=", base64_encode((const char*)"El Psy Congroo"));
}

int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 3) {
        throw std::invalid_argument("No arguments provided");
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
