#include <iostream>
#include "gtest/gtest.h"
#include "src/base64.hpp"

const char OPT_ENCODE[] = "-e";
const char OPT_DECODE[] = "-d";

TEST(BasicTests, TestEncode) {
ASSERT_STREQ(base64_encode("Hello"), "SGVsbG8=");
ASSERT_STREQ(base64_encode("kabachok"), "a2FiYWNob2s=");
ASSERT_STREQ(base64_encode("Ia ogurec"), "SWEgb2d1cmVj");
ASSERT_STREQ(base64_encode("Prostite ya xochu spat"),
"UHJvc3RpdGUgeWEgeG9jaHUgc3BhdA==");
}

TEST(BasicTests, TestDecode) {
ASSERT_STREQ(base64_decode("SGVsbG8="), "Hello");
ASSERT_STREQ(base64_decode("a2FiYWNob2s="), "kabachok");
ASSERT_STREQ(base64_decode("SWEgb2d1cmVj"), "Ia ogurec");
ASSERT_STREQ(base64_decode("UHJvc3RpdGUgeWEgeG9jaHUgc3BhdA=="),
"Prostite ya xochu spat");

}

TEST(BasicTest, TestEncodeDecode) {
ASSERT_STREQ(base64_decode(base64_encode("Hello")), "Hello");
ASSERT_STREQ(base64_decode(base64_encode("kabachok")), "kabachok");
ASSERT_STREQ(base64_decode(base64_encode("clion")), "clion");
ASSERT_STREQ(base64_decode(base64_encode("karl y klari ykral karali klara y karla ykrala kvartet")),
"karl y klari ykral karali klara y karla ykrala kvartet");
}

/*
int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 3) {
        throw std::invalid_argument("No arguments provided");
    }

    if (argc == 2) {
        std::cout << base64_encode("Hello");//argv[1]);
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
*/