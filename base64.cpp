#include <iostream>
#include <cstring>

#include "base64.hpp"


int main () {

  char * str = new char;
  char *strEnc = new char;
  char *strDec = new char;


  std::cout << "Введите строку для кодирования \n" << std::endl;
  std::cin >> str;

  std::cout << "Введённая вами строка для кодирования: " << str << std::endl;
  std::cout << "Производим кодирование \n" << std::endl;


  strEnc = base64::encode (str);


  std::cout << "Процесс кодирования выполнен. Результат кодирования строки: " << str << std::endl;
  std::cout << "Имеет вид: " << strEnc << std::endl;

  std::cout << "Строка для декодирования: " << strEnc << std::endl;
  std::cout << "Производим декодирование \n" << std::endl;


  strDec = base64::decode (strEnc);


  std::cout << "Процесс декодирования выполнен. Результат декодирования закодированной строки: " << strEnc << std::endl;
  std::cout << "Имеет вид: " << strDec << std::endl;


  return 0;
}
