#include "base64.hpp"
#include "gtest/gtest.h"

TEST(Encoding, emptyString) {
    char *s = base64_encode((const char*)"");
    EXPECT_STREQ(s, "");
}


TEST(Encoding, oneEqSign) {
    char *s = base64_encode((const char*)"Матрица повсюду");
    EXPECT_STREQ(s, "0JzQsNGC0YDQuNGG0LAg0L/QvtCy0YHRjtC00YM=");
}


TEST(Encoding, noEqSigns) {
    char *s = base64_encode((const char*)"Она окружает нас");
    EXPECT_STREQ(s, "0J7QvdCwINC+0LrRgNGD0LbQsNC10YIg0L3QsNGB");
}

TEST(Encoding, twoEqSigns) {
    char *s = base64_encode((const char*)"Даже сайчас она с нами рядом.");
    EXPECT_STREQ(s, "0JTQsNC20LUg0YHQsNC50YfQsNGBINC+0L3QsCDRgSDQvdCw0LzQuCDRgNGP0LTQvtC8Lg==");
}


TEST(Decoding, emptyString) {
    char *s = base64_decode((const char*)"");
    EXPECT_STREQ(s, "");
}

TEST(Decoding, noEqSigns) {
    char *s = base64_decode((const char*)"0KLRiyDQvtGJ0YPRidCw0LXRiNGMINC10LUs");
    EXPECT_STREQ(s, "Ты ощущаешь ее,");
}

TEST(Decoding, oneEqSign) {
    char *s = base64_decode((const char*)"0LrQvtCz0LTQsCDRgNCw0LHQvtGC0LDQtdGI0Yw=");
    EXPECT_STREQ(s, "когда работаешь");
}

TEST(Decoding, twoEqSigns) {
    char *s = base64_decode((const char*)"0YHQvNC+0YLRgNC40YjRjCDQsiDQvtC60L3Qvg==");
    EXPECT_STREQ(s, "смотришь в окно");
}


TEST(Decoding, Exceptions) {

    EXPECT_THROW(base64_decode((const char*)"0YH"), std::invalid_argument);
    EXPECT_THROW(base64_decode((const char*)"******"), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
