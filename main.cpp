#include <iostream>
#include "src/operations.h"
#include "string.h"
#include <gtest/gtest.h>

  TEST(BasicTest, TestEncode) {
      ASSERT_STREQ(encode("wait a minute"), "d2FpdCBhIG1pbnV0ZQ==");
      ASSERT_STREQ(encode("it's wednesday my dudes"), "aXQncyB3ZWRuZXNkYXkgbXkgZHVkZXM=");
      ASSERT_STREQ(encode("ladies and gentleman we got him"), "bGFkaWVzIGFuZCBnZW50bGVtYW4gd2UgZ290IGhpbQ==");
      ASSERT_STREQ(encode("A"), "QQ==");
  }

  TEST(BasicTest, TestDecode) {
      ASSERT_STREQ(decode("d2FpdCBhIG1pbnV0ZQ=="), "wait a minute");
      ASSERT_STREQ(decode("aXQncyB3ZWRuZXNkYXkgbXkgZHVkZXM="), "it's wednesday my dudes");
      ASSERT_STREQ(decode("bGFkaWVzIGFuZCBnZW50bGVtYW4gd2UgZ290IGhpbQ=="), "ladies and gentleman we got him");
      ASSERT_STREQ(decode("QQ=="), "A");
  }

  TEST(BasicTest, TestDecodeEncode) {
      ASSERT_STREQ(decode(encode("wait a minute")), "wait a minute");
      ASSERT_STREQ(decode(encode("it's wednesday my dudes")), "it's wednesday my dudes");
      ASSERT_STREQ(decode(encode("ladies and gentleman we got him")), "ladies and gentleman we got him");
      ASSERT_STREQ(decode(encode("A")), "A");
  }

  TEST(BasicTest, TestEncodeDecode) {
      ASSERT_STREQ(encode(decode("d2FpdCBhIG1pbnV0ZQ==")), "d2FpdCBhIG1pbnV0ZQ==");
      ASSERT_STREQ(encode(decode("aXQncyB3ZWRuZXNkYXkgbXkgZHVkZXM=")), "aXQncyB3ZWRuZXNkYXkgbXkgZHVkZXM=");
      ASSERT_STREQ(encode(decode("bGFkaWVzIGFuZCBnZW50bGVtYW4gd2UgZ290IGhpbQ==")),
                   "bGFkaWVzIGFuZCBnZW50bGVtYW4gd2UgZ290IGhpbQ==");
      ASSERT_STREQ(encode(decode("QQ==")), "QQ==");
  }

  TEST(BasicTest,StringsTest){
     ASSERT_THROW(encode(""),const char*);
     ASSERT_THROW(decode(""),const char*);
     ASSERT_THROW(decode("русские буквы"),const char*);
     ASSERT_THROW(decode("XyA"),const char*);
 }


//  int main() {
//
//      //std::cout << decode("привет") << std::endl;
//      std::cout << encode("");
//
//      return 0;
//  }

