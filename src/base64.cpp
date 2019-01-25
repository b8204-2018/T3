#include "base64.h"


namespace base64 {

  char Base64Table [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


  char * encode (const char * str) {

    int strSize = std::strlen (str);
    int b64byte [5];

    char *strEnc = new char;
    unsigned char *buftemp = new unsigned char [strSize + 3];


    memset (buftemp, '\0', strSize + 3);
    memcpy (buftemp, str, strSize);


    for (int i = 0; i < strSize; i += 3) {

      b64byte [0] = buftemp [i] >> 2;
      b64byte [1] = ((buftemp [i] & 3) << 4)  |  (buftemp [i + 1] >> 4);
      b64byte [2] = ((buftemp [i + 1] & 0x0F) << 2)  |  (buftemp [i + 2] >> 6);
      b64byte [3] = buftemp [i + 2] & 0x3F;


      if (b64byte [0] == 0) {
        strEnc [i + (i / 3)] = '=';
      }

      strEnc [i + (i / 3)] = Base64Table[b64byte [0]];


      if (b64byte [1] == 0) {
        strEnc [i + (i / 3) + 1] = '=';
      }

      strEnc [i + (i / 3) + 1] = Base64Table[b64byte[1]];


      if (b64byte [2] == 0) {
        strEnc [i + (i / 3) + 2] = '=';
      }

      strEnc [i + (i / 3) + 2] = Base64Table[b64byte[2]];


      if (b64byte [3] == 0) {
        strEnc [i + (i / 3) + 3] = '=';
      }

      strEnc [i + (i / 3) + 3] = Base64Table[b64byte[3]];

    }


    delete buftemp;

    return strEnc;

  }

  char * decode (const char *str) {

    int strSize = std::strlen (str);
    int cpos[5];


    char *strDec = new char;
    unsigned char *buftemp = new unsigned char [strSize];
    unsigned char binbyte [4];


    memset (buftemp, '\0', strSize);
    memcpy (buftemp, str, strSize);


    for (int i = 0; i < strSize; i += 4) {

      if (buftemp [i] == '=') {
        cpos [0] = 0;
      }

      cpos [0] = std::strchr (Base64Table, buftemp [i]) - Base64Table;


      if (buftemp [i + 1] == '=') {
        cpos [1] = 0;
      }

      cpos [1] = std::strchr (Base64Table, buftemp [i + 1]) - Base64Table;


      if (buftemp [i + 2] == '=') {
        cpos [2] = 0;
      }

      cpos [2] = std::strchr (Base64Table, buftemp [i + 2]) - Base64Table;


      if (buftemp [i + 3] == '=') {
        cpos [3] = 0;
      }

      cpos [3] = std::strchr (Base64Table, buftemp [i + 3]) - Base64Table;


      binbyte [0] = ((cpos [0] << 2)  |  (cpos [1] >> 4));
      binbyte [1] = ((cpos [1] << 4)  |  (cpos [2] >> 2));
      binbyte [2] = (((cpos [2]  &  0x03 ) << 6)  |  (cpos [3]  &  0x3f));


      strDec [i - (i / 4)] = binbyte [0];
      strDec [i - (i / 4) + 1] = binbyte [1];
      strDec [i - (i / 4) + 2] = binbyte [2];

    }


    delete buftemp;

    return strDec;

  }

}





