#include "base64.hpp"
#include "gtest/gtest.h"

TEST(Encode, fiveLetters) {
    char *s = base64_encode((const char*)"Rooms");
    EXPECT_STREQ(s, "Um9vbXM=");
}


TEST(Encode, fourLetters) {
    char *s = base64_encode((const char*)"Cats");
    EXPECT_STREQ(s, "Q2F0cw==");
}

TEST(Encode, sixLetters) {
    char *s = base64_encode((const char*)"Yellow");
    EXPECT_STREQ(s, "WWVsbG93");
}


TEST(Encode, empty) {
    char *s = base64_encode((const char*)"");
    EXPECT_STREQ(s, "");
}

TEST(Decode, noEqualSigns) {
    char *s = base64_decode((const char*)"TW9vbg==");
    EXPECT_STREQ(s, "Moon");
}


TEST(Decode, twoEqualSigns) {
    char *s = base64_decode((const char*)"Um9vbXM=");
    EXPECT_STREQ(s, "Rooms");
}

TEST(Decode, empty) {
    char *s = base64_decode((const char*)"");
    EXPECT_STREQ(s, "");
}

TEST(Decoding, Exceptions) {

    EXPECT_THROW(base64_decode((const char*)"III"), std::invalid_argument);
    EXPECT_THROW(base64_decode((const char*)"-----"), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}