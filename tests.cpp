//
// Created by 1 on 14.01.2019.
//
#include <iostream>
#include "src/base64.h"
#include <gtest/gtest.h>

TEST(Base64Test, TestEncode) {
    ASSERT_STREQ(encode("MyFriend"), "TXlGcmllbmQ=");
    ASSERT_STREQ(encode("gfHJDkdllcyruerett"), "Z2ZISkRrZGxsY3lydWVyZXR0");
    ASSERT_STREQ(encode("They were great people with huge flaws"), "VGhleSB3ZXJlIGdyZWF0IHBlb3BsZSB3aXRoIGh1Z2UgZmxhd3M=");
    ASSERT_STREQ(encode("KK"), "S0s=");
}

TEST(Base64Test, TestDecode) {
    ASSERT_STREQ(decode("TXlGcmllbmQ="), "MyFriend");
    ASSERT_STREQ(decode("Z2ZISkRrZGxsY3lydWVyZXR0"), "gfHJDkdllcyruerett");
    ASSERT_STREQ(decode("VGhleSB3ZXJlIGdyZWF0IHBlb3BsZSB3aXRoIGh1Z2UgZmxhd3M="), "They were great people with huge flaws");
    ASSERT_STREQ(decode("S0s="), "KK");
}

TEST(Base64Test, TestDecodeEncode) {
    ASSERT_STREQ(decode(encode("MyFriend")), "MyFriend");
    ASSERT_STREQ(decode(encode("gfHJDkdllcyruerett")), "gfHJDkdllcyruerett");
    ASSERT_STREQ(decode(encode("They were great people with huge flaws")), "They were great people with huge flaws");
    ASSERT_STREQ(decode(encode("KK")), "KK");
}

TEST(Base64Test, TestEncodeDecode) {
    ASSERT_STREQ(encode(decode("TXlGcmllbmQ=")), "TXlGcmllbmQ=");
    ASSERT_STREQ(encode(decode("Z2ZISkRrZGxsY3lydWVyZXR0")), "Z2ZISkRrZGxsY3lydWVyZXR0");
    ASSERT_STREQ(encode(decode("VGhleSB3ZXJlIGdyZWF0IHBlb3BsZSB3aXRoIGh1Z2UgZmxhd3M=")),
                 "VGhleSB3ZXJlIGdyZWF0IHBlb3BsZSB3aXRoIGh1Z2UgZmxhd3M=");
    ASSERT_STREQ(encode(decode("S0s=")), "S0s=");
}

TEST(BasicTest,StringsTest){
    ASSERT_THROW(encode(""),const char*);
    ASSERT_THROW(decode(""),const char*);
    ASSERT_THROW(decode("ававцц"),const char*);
    ASSERT_THROW(decode("LKI"),const char*);
}
