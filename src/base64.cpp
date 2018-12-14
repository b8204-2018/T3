#include <cstring>
#include "base64.hpp"

char base [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *base64_encode(const char *s) {
    int con = 0x3f, len = (int) strlen(s);
    int temp;
    char symb [4];
    char* encoded;

    if (strlen(s) % 3 == 0) {
        encoded = new char[(4*len/3) + 1];
    }
    else{
        encoded = new char[4*(len/3) + 5];
    }

    for (int i = 0, j = 0; i < 3 * (len / 3); i += 3, j += 4){
        temp = (s[i] << 16) + (s[i+1] << 8) + s[i+2];
        for (int k = j; k < j + 4; k++){
            encoded[k] = base[((temp & (con << (3 - (k - j))*6)) >> (3 - (k - j))*6)];
        }
    }

    if(len % 3 != 0){
        temp = 0;
        for (int i = (int) (len - len % 3); i < len; i++){
            temp = temp + (s[i] << (16 - 8*(i - (len - len%3))));
        }
        switch (len % 3){
            case 1:
                for(int i = 0; i <=1; i++){
                    encoded[4*(len/3) + i] = base[((temp & (con << (3 - i)*6)) >> (3 - i)*6)];
                }
                for(int i = 2; i <=3; i++){
                    encoded[4*(len/3) + i] = '=';
                }
                break;
            case 2:
                for(int i = 0; i <=2; i++){
                    encoded[4*(len/3) + i] = base[((temp & (con << (3 - i)*6)) >> (3 - i)*6)];
                }
                    encoded[4*(len/3) + 3] = '=';
                break;
            default:{}
        }

    }
    encoded[strlen(encoded)] = '\0';
    return encoded;
}

char *base64_decode(const char *s) {
    return (char *)"decoded";
}
