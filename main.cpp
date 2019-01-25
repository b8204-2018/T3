#include <iostream>
#include <cstring>

#include "src/base64.h"
#include "src/base64.cpp"

#include <gtest/gtest.h>


int main () {

  char * str = new char;
  char *strEnc = new char;
  char *strDec = new char;

  std::cout << "Введите строку для кодирования \n" << std::endl;
  std::cin >> str;

TEST (base64Tests, encodeTest) {

  ASSERT_STREQ (base64::encode (strTest), base64::encode (str));

}

TEST (base64Tests, decodeTest) {

  char *strCode = base64::encode (str);


  ASSERT_STREQ (base64::decode (strCode), base64::decode (strCode));

}

TEST (base64Tests, encodeDecodeTest) {

  ASSERT_STREQ (base64::decode (base64::encode (str)), str);

}

  std::cout << "Введённая вами строка для кодирования: " << str << std::endl;

  strEnc = base64::encode (str);

 Результат кодирования строки: " << str << std::endl;
  std::cout << "Имеет вид: " << strEnc << std::endl;

  std::cout << "Строка для декодирования: " << strEnc << std::endl;


  strDec = base64::decode (strEnc);


 Результат декодирования закодированной строки: " << strEnc << std::endl;
  std::cout << "Имеет вид: " << strDec << std::endl;


  return 0;
}
