#include "base64.hpp"
#include <cstring>

char *base64_encode(const char *s) {
    char alphabet[][2] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K",
                          "L", "M", "N", "O", "P", "Q", "R","S", "T","U", "V",
                          "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g",
                          "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                          "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2",
                          "3", "4", "5", "6", "7","8", "9", "+", "/"};

    int length(0), j(0);
    unsigned char n;
    length = strlen(s);
    char *decode =  new char[length * 2];
    char *add = new char[3];
    if (length % 3 == 0){
        add[0] = '\0';
    }
    if (length % 3 == 1){
        add[0] = '=';
        add[1] = '=';
        add[2] = '\0';
    }
    if (length % 3 == 2){
        add[0] = '=';
        add[1] = '\0';
    }
    int i(0), count(1);
    while (count <= (length / 3)){
        n = ((unsigned char)s[i]) >> 2;
        memcpy(decode + j, alphabet[n], 1);
        j++;
        n = ((unsigned char)(s[i] << 6) >> 2) + ((unsigned char)s[i + 1] >> 4);
        memcpy(decode + j, alphabet[n], 1);
        j++;
        n =((unsigned char)(s[i + 1] << 4) >> 2) + ((unsigned char)s[i + 2] >> 6);
        memcpy(decode + j, alphabet[n], 1);
        j++;
        n = (unsigned char)(s[i + 2] << 2) >> 2;
        memcpy(decode + j, alphabet[n], 1);
        j++;
        i += 3;
        count++;
    }
    if (length % 3 == 2){
        n = (unsigned char)s[i] >> 2;
        memcpy(decode + j, alphabet[n], 1);
        j++;
        n = ((unsigned char)(s[i] << 6) >> 2) + ((unsigned char)(s[i + 1]) >> 4);
        memcpy(decode + j, alphabet[n], 1);
        j++;
        n = ((unsigned char)(s[i + 1] << 4)) >> 2;
        memcpy(decode + j, alphabet[n], 1);
        j++;
    }
    if (length % 3 == 1){
        n = (unsigned char)s[i] >> 2;
        memcpy(decode + j, alphabet[n], 1);
        j++;
        n = ((unsigned char)(s[i] << 6) >> 2);
        memcpy(decode + j, alphabet[n], 1);
        j++;
    }

    for (int i = 0; i < strlen(add) + 1; i++){
        memcpy(decode + j, add + i, 1);
        j++;
    }
    return decode;
}

char *base64_decode(const char *s) {
    char alphabet[][2] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K",
                          "L", "M", "N", "O", "P", "Q", "R","S", "T","U", "V",
                          "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g",
                          "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                          "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2",
                          "3", "4", "5", "6", "7","8", "9", "+", "/"};

    int length(0);
    for (int i = 0; s[i] != '\0'; i++, length++);
    char *encode = new char[length];
    int eq(0);
    if (s[length - 1] == '=') {eq = 1;}
    if (s[length - 2] == '=') {eq = 2;}
    int count(1), i(0), j(0);
    unsigned char n, poz, poz1;
    while (count <= ((length - eq + 1) / 4)) {
        for(poz = 0; s[i] != *alphabet[poz]; poz++);
        n = poz << 2;
        encode[j] = n;
        j++;

        for(poz = 0; s[i + 1] != *alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 2] != *alphabet[poz1]; poz1++);
        n = (poz << 4) + (poz1 >> 2);
        encode[j] = n;
        j++;

        for(poz = 0; s[i + 2] != *alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 3] != *alphabet[poz1]; poz1++);
        n = (poz << 6) + poz1;
        encode[j] = n;
        j++;
        count++;
        if (eq == 1) { count++; }
        i += 3;
    }
    if (eq == 1) {
        i++;
        for(poz = 0; s[i] != *alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 1] != *alphabet[poz1]; poz1++);
        n = (poz << 2) + (poz1 >> 4);
        encode[j] = n;
        j++;

        for(poz = 0; s[i + 1] != *alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 2] != *alphabet[poz1]; poz1++);
        n = (poz << 4) + (poz1 >> 2);
        encode[j] = n;
        j++;
        encode[j] = '\0';
    }
    else if (eq == 2) {
        i++;
        for(poz = 0; s[i] != *alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 1] != *alphabet[poz1]; poz1++);
        n = (poz << 2) + (poz1 >> 4);
        encode[j] = n;
        j++;
        encode[j] = '\0';
    } else {
        encode[j] = '\0';
    }
    return encode;
}