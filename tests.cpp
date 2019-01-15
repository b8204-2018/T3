#include "base64.hpp"
#include "gtest/gtest.h"

TEST(Encode, E1) {
    char *s = base64_encode((const char*)"");
    EXPECT_STREQ(s, "");
}

TEST(Encode, E2) {
    char *s = base64_encode((const char*)"В лесу родилась елочка,");
    EXPECT_STREQ(s, "0JIg0LvQtdGB0YMg0YDQvtC00LjQu9Cw0YHRjCDQtdC70L7Rh9C60LAs");
}

TEST(Encode, E3) {
    char *s = base64_encode((const char*)"В лесу она росла");
    EXPECT_STREQ(s, "0JIg0LvQtdGB0YMg0L7QvdCwINGA0L7RgdC70LA=");
}

TEST(Decode, D1) {
    char *s = base64_decode((const char*)"0JfQuNC80L7QuSDQuCDQu9C10YLQvtC8INGB0YLRgNC+0LnQvdCw0Y8s");
    EXPECT_STREQ(s, "Зимой и летом стройная,");
}

TEST(Decode, D2) {
    char *s = base64_decode((const char*)"0JfQtdC70LXQvdCw0Y8g0LHRi9C70LA=");
    EXPECT_STREQ(s, "Зеленая была");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}