#include "base64.hpp"
#include <cstring>
#include <stdexcept>

char *base64_encode(const char *s) {
    char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int j = 0;
    unsigned char n;
    int length = strlen(s);
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
    char *encoded =  new char[2 * length];
    int i(0);
    while ((length - i) > (strlen(add) + 1)){
        n = ((unsigned char)s[i]) >> 2;
        memcpy(encoded + j, base64 + n, 1);
        j++;
        n = ((unsigned char)(s[i] << 6) >> 2) + ((unsigned char)s[i + 1] >> 4);
        memcpy(encoded + j, base64 + n, 1);
        j++;
        n =((unsigned char)(s[i + 1] << 4) >> 2) + ((unsigned char)s[i + 2] >> 6);
        memcpy(encoded + j, base64 + n, 1);
        j++;
        n = ((unsigned char)(s[i + 2] << 2) >> 2);
        memcpy(encoded + j, base64 + n, 1);
        j++;
        i += 3;
    }
    if (length % 3 == 2){
        n = (unsigned char)s[i] >> 2;
        memcpy(encoded + j, base64 + n, 1);
        j++;
        n = ((unsigned char)(s[i] << 6) >> 2) + ((unsigned char)(s[i + 1]) >> 4);
        memcpy(encoded + j, base64 + n, 1);
        j++;
        n = ((unsigned char)(s[i + 1] << 4)) >> 2;
        memcpy(encoded + j, base64 + n, 1);
        j++;
    }
    if (length % 3 == 1){
        n = (unsigned char)s[i] >> 2;
        memcpy(encoded + j, base64 + n, 1);
        j++;
        n = ((unsigned char)(s[i] << 6) >> 2);
        memcpy(encoded + j, base64 + n, 1);
        j++;
    }
    memcpy(encoded + j, add, strlen(add) + 1);
    return encoded;
}

unsigned char pos (char s){
    char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int i(0);
    for (i = 0; s != base64[i]; i++);
    return ((unsigned char)(i));
}

char *base64_decode(const char *s) {
    if (strlen(s) % 4 != 0){
        throw std::invalid_argument("Error: incorrect string.");
    } else {
        char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        int i(0), j(0);
        for (i = 0; i < strlen(s); i++) {
            for (j = 0; (s[i] != base64[j]) && (j < strlen(base64)); j++);
            if (j == strlen(base64) - 1 && (s[i] != base64[j - 1])) {
                throw std::invalid_argument("Error: invalid symbols in string.");
            }
        }
    }
    if (strcmp(s, "") == 0){
        return (char*)"";
    }
    int length = strlen(s) - 1;
    char *decoded = new char[length];
    unsigned char *add = new unsigned char [3];
    if (s[length] == '=' && s[length - 1] == '='){
        length -= 2;
        add[0] = (pos(s[length - 1]) << 2) + (pos(s[length]) >> 4);
        add[1] = '\0';
        length -= 2;
    } else if (s[length] == '=' && s[length - 1] != '='){
        length -= 1;
        add[0] = (pos(s[length - 2]) << 2) + (pos(s[length - 1]) >> 4);
        add[1] = (pos(s[length - 1]) << 4) + (pos(s[length]) >> 2);
        add[2] = '\0';
        length -= 3;
    } else {
        add[0] = '\0';
    }
    int j(0), i(0);
    unsigned char buff;
    while (i < length){
        buff =(pos(s[i]) << 2) + (pos(s[i + 1]) >> 4);
        decoded[j] = (char)(buff);
        j++;
        buff = (pos(s[i + 1]) << 4) + (pos(s[i + 2]) >> 2);
        decoded[j] = (char)(buff);
        j++;
        buff = (pos(s[i + 2]) << 6) + pos(s[i + 3]);
        decoded[j] = (char)(buff);
        j++;
        i += 4;
    }
    memcpy(decoded + j, add, strlen((const char*)add) + 1);
    return decoded;
}