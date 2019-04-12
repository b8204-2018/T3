#include "base64.hpp"
#include <cstring>
#include <cstdlib>

char *base64_encode(const char *s) {
    const char alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                              'H', 'I', 'J', 'K', 'L', 'M', 'N',
                              'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                              'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
                              'c', 'd', 'e', 'f', 'g', 'h', 'i',
                              'j', 'k', 'l', 'm', 'n', 'o', 'p',
                              'q', 'r', 's', 't', 'u', 'v', 'w',
                              'x', 'y', 'z', '0', '1', '2', '3',
                              '4', '5', '6', '7', '8', '9', '+',
                              '/', '=' };

    int i = 0, j = 0;
    int length = strlen(s);   //длина строки
    int bs = length - (length % 3);
    int  ob = length - bs; //оставшееся количество бит
    unsigned short int k;
    char encode[k];

    // Разбивает слово на 3 слова.
    for (i=0; i < bs; i += 3) {
        // Разделяет 3 слова на 4 слова с помощью побитовой операции. (из 8 бит до 6 бит.)

        //1
        encode[j] = alphabet[(s[i] >> 2) & 0b111111];
        j=j+1;

        //2
        encode[j] = alphabet[((s[i] & 0b11) << 4) + ((s[i+1] >> 4) & 0b1111)];
        j=j+1;

        // 3
        encode[j] = alphabet[((s[i+1] & 0b1111) << 2) + ((s[i+2] >> 6) & 0b11)];
        j=j+1;

        // 4
        encode[j] = alphabet[s[i+2] & 0b111111];
        j=j+1;
    }


    if (ob != 0) {
        encode[j++] = alphabet[s[i] >> 2 & 0b111111];

        if (length - i == 2) { // Если осталось 2 байта
            encode[j] = alphabet[((s[i] & 0b11) << 4) + ((s[i + 1] >> 4) & 0b1111)];
            j=j+1;
            encode[j] = alphabet[(s[i + 1] & 0b1111) << 2];
            j=j+1;
        }else { // Если остается один байт
            encode[j] = alphabet[(s[i] & 0b11) << 4];
            j=j+1;
            encode[j] = alphabet[64];
            j=j+1;
        }
        encode[j] = alphabet[64];
        j=j+1;
    }

    encode[j] = NULL;
    j=j+1;

    int size = sizeof(char) * j;

    char *result = (char *)malloc(size);

    memset(result, NULL, size);

    memcpy(result, encode, size);

    return result;
}


char *base64_decode(const char *s) {
    const char alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                              'H', 'I', 'J', 'K', 'L', 'M', 'N',
                              'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                              'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
                              'c', 'd', 'e', 'f', 'g', 'h', 'i',
                              'j', 'k', 'l', 'm', 'n', 'o', 'p',
                              'q', 'r', 's', 't', 'u', 'v', 'w',
                              'x', 'y', 'z', '0', '1', '2', '3',
                              '4', '5', '6', '7', '8', '9', '+',
                              '/', '=' };

    int length=0;
    for (int i = 0; s[i] != '\0'; i++, length++);
    char *encode = new char[length];
    int eq=0.;
    if (s[length - 1] == '=') {eq = 1;}
    if (s[length - 2] == '=') {eq = 2;}
    int count=1, i=0, j=0;
    unsigned char n, poz, poz1;
    while (count <= ((length - eq + 1) / 4)) {
        for(poz = 0; s[i] != alphabet[poz]; poz++);
        n = poz << 2;
        encode[j] = n;
        j++;

        for(poz = 0; s[i + 1] != alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 2] != alphabet[poz1]; poz1++);
        n = (poz << 4) + (poz1 >> 2);
        encode[j] = n;
        j++;

        for(poz = 0; s[i + 2] != alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 3] != alphabet[poz1]; poz1++);
        n = (poz << 6) + poz1;
        encode[j] = n;
        j++;
        count++;
        if (eq == 1) { count++; }
        i += 3;
    }
    if (eq == 1) {
        i++;
        for(poz = 0; s[i] != alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 1] != alphabet[poz1]; poz1++);
        n = (poz << 2) + (poz1 >> 4);
        encode[j] = n;
        j++;

        for(poz = 0; s[i + 1] != alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 2] != alphabet[poz1]; poz1++);
        n = (poz << 4) + (poz1 >> 2);
        encode[j] = n;
        j++;
        encode[j] = '\0';
    }
    else if (eq == 2) {
        i++;
        for(poz = 0; s[i] != alphabet[poz]; poz++);
        for(poz1 = 0; s[i + 1] != alphabet[poz1]; poz1++);
        n = (poz << 2) + (poz1 >> 4);
        encode[j] = n;
        j++;
        encode[j] = '\0';
    } else {
        encode[j] = '\0';
    }
    return encode;
}


