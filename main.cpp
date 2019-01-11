#include <iostream>
#include "src/base64.hpp"
#include "string.h"
#include <gtest/gtest.h>

const char OPT_ENCODE[] = "-e";
const char OPT_DECODE[] = "-d";

TEST(BasicTests, TestEncode) {
    ASSERT_STREQ(base64_encode("Hello"), "SGVsbG8=");
    ASSERT_STREQ(base64_encode("Roman"), "Um9tYW4=");
    ASSERT_STREQ(base64_encode("Petrovich"), "UGV0cm92aWNo");
    ASSERT_STREQ(base64_encode("I understood how to use the framework"),
                 "SSB1bmRlcnN0b29kIGhvdyB0byB1c2UgdGhlIGZyYW1ld29yaw==");
}

TEST(BasicTests, TestDecode) {
    ASSERT_STREQ(base64_decode("SGVsbG8="), "Hello");
    ASSERT_STREQ(base64_decode("Um9tYW4="), "Roman");
    ASSERT_STREQ(base64_decode("UGV0cm92aWNo"), "Petrovich");
    ASSERT_STREQ(base64_decode("SSB1bmRlcnN0b29kIGhvdyB0byB1c2UgdGhlIGZyYW1ld29yaw=="),
                 "I understood how to use the frameworkT3");

}

TEST(BasicTest, TestEncodeDecode) {
    ASSERT_STREQ(base64_decode(base64_encode("Hello")), "Hello");
    ASSERT_STREQ(base64_decode(base64_encode("Roman")), "Roman");
    ASSERT_STREQ(base64_decode(base64_encode("Petrovich")), "Petrovich");
    ASSERT_STREQ(base64_decode(base64_encode("I understood how to use the framework")),
                 "I understood how to use the framework");
}


TEST(BasicTest, TestDecodeEncode) {
    ASSERT_STREQ(base64_encode(base64_decode("SGVsbG8=")), "SGVsbG8=");
    ASSERT_STREQ(base64_encode(base64_decode("Um9tYW4=")), "Um9tYW4=");
    ASSERT_STREQ(base64_encode(base64_decode("UGV0cm92aWNo")), "UGV0cm92aWNo");
    ASSERT_STREQ(base64_encode(base64_decode("SSB1bmRlcnN0b29kIGhvdyB0byB1c2UgdGhlIGZyYW1ld29yaw==")),
                 "SSB1bmRlcnN0b29kIGhvdyB0byB1c2UgdGhlIGZyYW1ld29yaw==");

}
/*
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
*/