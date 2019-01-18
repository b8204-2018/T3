#include "base64.hpp"
#include "gtest/gtest.h"

TEST(Encode, threeLetters) {
char *s = base64_encode((const char*)"ups");
EXPECT_STREQ(s, "dXBz");
}


TEST(Encode, fourLetters) {
char *s = base64_encode((const char*)"oops");
EXPECT_STREQ(s, "b29wcw==");
}

TEST(Encode, fiveLetters) {
char *s = base64_encode((const char*)"param");
EXPECT_STREQ(s, "cGFyYW0=");
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
char *s = base64_decode((const char*)"ZG9nZw==");
EXPECT_STREQ(s, "dogg");
}

TEST(Decode, empty) {
char *s = base64_decode((const char*)"");
EXPECT_STREQ(s, "");
}

TEST(Decode, oneEqualSign) {
char *s = base64_decode((const char*)"ZG9nIGc=");
EXPECT_STREQ(s, "dog g");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}