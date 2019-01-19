#include "base64.hpp"
#include "gtest/gtest.h"

TEST(Encode, threeLetters) {
    char *s = base64_encode((const char*)"hey");
    EXPECT_STREQ(s, "aGV5");
}

TEST(Encode, fourLetters) {
    char *s = base64_encode((const char*)"rest");
    EXPECT_STREQ(s, "cmVzdA==");
}

TEST(Encode, fiveLetters) {
    char *s = base64_encode((const char*)"Night");
    EXPECT_STREQ(s, "TmlnaHQ=");
}


TEST(Encode, empty) {
    char *s = base64_encode((const char*)"");
    EXPECT_STREQ(s, "");
}

TEST(Decode, twoEqualSigns) {
    char *s = base64_decode((const char*)"VGFzaw==");
    EXPECT_STREQ(s, "Task");
}

TEST(Decode, oneEqualSigns) {
    char *s = base64_decode((const char*)"bGlnaHQ=");
    EXPECT_STREQ(s, "light");
}

TEST(Decode, empty) {
    char *s = base64_decode((const char *) "");
    EXPECT_STREQ(s, "");
}

TEST(Decoding, Exceptions) {

    EXPECT_THROW(base64_decode((const char*)"AAA"), std::invalid_argument);
    EXPECT_THROW(base64_decode((const char*)"*$%@"), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}