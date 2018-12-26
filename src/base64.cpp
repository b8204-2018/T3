#include "base64.hpp"
#include <iostream>
using namespace std;

char *base64_encode(const char *s) {
  const char alf_64[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                         "abcdefghijklmnopqrstuvwxyz"
                         "0123456789+/"};
  const int three = 3;

  unsigned char buf_3[three]; // array for bytes
  unsigned char buf_4[4];     // array for 6-bit's bytes
  int i = 0, j = 0;
  int len = 0;
  while (s[len] != 0) {
    len++;
  }
  char *result = new char[len * 2]; // array result base64_encode

  for (i = 0; i < len / three; i++) {
    buf_3[0] = s[i * three];
    buf_3[1] = s[i * three + 1];
    buf_3[2] = s[i * three + 2];

    buf_4[0] = (buf_3[0] & 0xfc) >> 2;
    buf_4[1] = ((buf_3[0] & 0x03) << 4) + ((buf_3[1] & 0xf0) >> 4);
    buf_4[2] = ((buf_3[1] & 0x0f) << 2) + ((buf_3[2] & 0xc0) >> 6);
    buf_4[3] = buf_3[2] & 0x3f;

    for (j = i * 4; j < 4 * (i + 1); j++) {
      result[j] = alf_64[buf_4[j - i * 4]];
    }
  }

  if (len % three == 2) { // remain 2 bytes
    buf_3[0] = s[i * three];
    buf_3[1] = s[i * three + 1];

    buf_4[0] = (buf_3[0] & 0xfc) >> 2;
    buf_4[1] = ((buf_3[0] & 0x03) << 4) + ((buf_3[1] & 0xf0) >> 4);
    buf_4[2] = ((buf_3[1] & 0x0f) << 2);

    for (j = i * 4; j < 4 * (i + 1); j++) {
      if (j < 4 * (i + 1) - 1) {
        result[j] = alf_64[buf_4[j - i * 4]];
      } else {
        result[j] = 0x3d; //"="
      }
    }
  } else if (len % three == 1) { // remain 1 byte
    buf_3[0] = s[i * three];
    buf_4[0] = (buf_3[0] & 0xfc) >> 2;
    buf_4[1] = ((buf_3[0] & 0x03) << 4);

    for (j = i * 4; j < 4 * (i + 1); j++) {
      if (j < 4 * (i + 1) - 2) {
        result[j] = alf_64[buf_4[j - i * 4]];
      } else {
        result[j] = 0x3d; //"="
      }
    }
  }

  return result;
}

char *base64_decode(const char *s) { return (char *)"decoded"; }
