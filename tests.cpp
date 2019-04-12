//
// Created by maria on 20.02.19.
//

#include "src/base64.hpp"
#include "gtest/gtest.h"

TEST(Encode, threeLetters) {
char *s = base64_encode((const char*)"dog");
EXPECT_STREQ(s, "ZG9n");
}


TEST(Encode, fourLetters) {
char *s = base64_encode((const char*)"love");
EXPECT_STREQ(s, "bG92ZQ==");
}

TEST(Encode, sixLetters) {
char *s = base64_encode((const char*)"google");
EXPECT_STREQ(s, "Z29vZ2xl");
}


TEST(Encode, empty) {
char *s = base64_encode((const char*)"");
EXPECT_STREQ(s, "");
}

TEST(Decode, noEqualSigns) {
char *s = base64_decode((const char*)"ZG9n");
EXPECT_STREQ(s, "dog");
}


TEST(Decode, twoEqualSigns) {
char *s = base64_decode((const char*)"aG9uZXk=");
EXPECT_STREQ(s, "honey");
}

TEST(Decode, empty) {
char *s = base64_decode((const char*)"");
EXPECT_STREQ(s, "");
}

TEST(Decode, one) {
char *s = base64_decode((const char*)"bG92ZQ==");
EXPECT_STREQ(s, "love");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}