#include "base64.hpp"
#include "gtest/gtest.h"

TEST(Encode, threeLetters) {
char *s = base64_encode((const char*)"Test");
EXPECT_STREQ(s, "VGVzdA==");
}


TEST(Encode, fourLetters) {
char *s = base64_encode((const char*)"Sunday");
EXPECT_STREQ(s, "U3VuZGF5");
}

TEST(Encode, fiveLetters) {
char *s = base64_encode((const char*)"Mouse");
EXPECT_STREQ(s, "TW91c2U=");
}


TEST(Encode, empty) {
char *s = base64_encode((const char*)"");
EXPECT_STREQ(s, "");
}

TEST(Decode, noEqualSigns) {
char *s = base64_decode((const char*)"VGVzdA==");
EXPECT_STREQ(s, "Test");
}


TEST(Decode, twoEqualSigns) {
char *s = base64_decode((const char*)"SGVsbG8=");
EXPECT_STREQ(s, "Hello");
}

TEST(Decode, empty) {
char *s = base64_decode((const char*)"");
EXPECT_STREQ(s, "");
}

TEST(Decode, oneEqualSign) {
char *s = base64_decode((const char*)"RGF5");
EXPECT_STREQ(s, "Day");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}