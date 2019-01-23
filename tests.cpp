#include "base64.hpp"
#include "gtest/gtest.h"

TEST(Encode, fiveLetters) {
    char *s = base64_encode((const char*)"Hello");
    EXPECT_STREQ(s, "SGVsbG8=");
}


TEST(Encode, fourLetters) {
    char *s = base64_encode((const char*)"Code");
    EXPECT_STREQ(s, "Q29kZQ==");
}

TEST(Encode, sixLetters) {
    char *s = base64_encode((const char*)"Laptop");
    EXPECT_STREQ(s, "TGFwdG9w");
}


TEST(Encode, empty) {
    char *s = base64_encode((const char*)"");
    EXPECT_STREQ(s, "");
}

TEST(Decode, noEqualSigns) {
    char *s = base64_decode((const char*)"VGFzaw==");
    EXPECT_STREQ(s, "Task");
}


TEST(Decode, twoEqualSigns) {
    char *s = base64_decode((const char*)"SGVsbG8=");
    EXPECT_STREQ(s, "Hello");
}

TEST(Decode, empty) {
    char *s = base64_decode((const char*)"");
    EXPECT_STREQ(s, "");
}

TEST(Decoding, Exceptions) {

    EXPECT_THROW(base64_decode((const char*)"AAA"), std::invalid_argument);
    EXPECT_THROW(base64_decode((const char*)"******"), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}