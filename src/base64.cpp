#include "base64.hpp"
#include<iostream>

using namespace std;
/* случайно сегодня изменил ветку master , испытав адский выброс адреналина в поисках способа откатить коммиты случайно удалил оригинал
 * пока еще не готово
 * данная версия даже не проверялась т.к писалась по памяти
 * пожадуйста запускайте
 * google test пока еще даже не пытался присоединять
 */

const char base64[]{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

char *base64_encode(const char *s) {
    unsigned char in[3];
    unsigned char out[4];
    int len = 0, i = 0;
    char enc[len * 2];
    while (s[len] != 0) {
        len++;
    }
    for (i = 0; i < len / 3; i++) {
        in[0] = s[3 * i];
        in[1] = s[3 * i + 1];
        in[2] = s[3 * i + 2];

        out[0] = (in[0] & 0xfc >> 2);
        out[1] = (((in[0] & 0x03) << 4) + ((in[1] & 0xf0) >> 4));
        out[2] = (((in[1] & 0x0f) << 2) + ((in[2] & 0xc0) >> 6));
        out[3] = (in[2] & 0x3f);

        for (int j = 4 * i; j < 4 * (i + 1); j++) {
            enc[j] = base64[out[j - i]];
        }

    }
    switch (len % 3) {
        case 1: {
            in[0] = s[3 * i];
            out[0] = (in[0] & 0xfc >> 2);
            out[1] = ((in[0] & 0x03) << 4);
            for (int j = 4 * i; j < 4 * (i + 1); j++) {
                if (j < 4 * (i + 1) - 2) {
                    enc[j] = base64[j - i];
                } else {
                    enc[j] = 0x3D;
                }
            }
        }
        case 2: {
            in[0] = s[3 * i];
            in[1] = s[3 * i + 1];

            out[0] = (in[0] & 0xfc >> 2);
            out[1] = (((in[0] & 0x03) << 4) + ((in[1] & 0xf0) >> 4));
            out[2] = ((in[1] & 0x0f) << 2);

            for (int j = 4 * i; j < 4 * (i + 1); j++) {
                if (j < 4 * (i + 1) - 1) {
                    enc[j] = base64[j - i];
                } else {
                    enc[j] = 0x3D;
                }
            }
        }
    }


    return enc;
}

char *base64_decode(const char *s) {
    unsigned char in[4];
    unsigned char out[3];
    int len = 0;
    while (s[len] != 0) {
        len++;
    }
    char dec[len / 4 * 3];
    int k = 0;
    for (int i = 0; i < len / 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i * 4 + j] == 0x3D) {
                k++;
            }
        }
        in[0] = s[4 * i];
        in[1] = s[4 * i + 1];
        in[2] = s[4 * i + 2];
        in[3] = s[4 * i + 3];

        out[0] = (in[0] << 2 | in[1] >> 4);
        out[1] = (in[1] << 4 | in[2] >> 2);
        out[2] = (((in[2] << 6) & 0xc0) | in[3]);

        for (int c=3*i;c<3*(i+1)-k;c++){
            dec[c]=out[c-i];
        }

    }
    return dec;
}