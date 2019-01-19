#include "base64.hpp"
#include<iostream>

using namespace std;

const char base64[]{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

char *base64_encode(const char *s) {
    unsigned char in[3];
    unsigned char out[4];
    int len = 0, i = 0, d = 0;

    while (s[len] != 0) {
        len++;
    }
    (len % 3 != 0) ? (d = len / 3 * 4 + 4) : d = len / 3 * 4;

    char *enc = new char[d];
    for (i = 0; i < len / 3; i++) {
        in[0] = s[3 * i];
        in[1] = s[3 * i + 1];
        in[2] = s[3 * i + 2];

        out[0] = ((in[0] & 0xfc) >> 2);
        out[1] = (((in[0] & 0x03) << 4) + ((in[1] & 0xf0) >> 4));
        out[2] = (((in[1] & 0x0f) << 2) + ((in[2] & 0xc0) >> 6));
        out[3] = (in[2] & 0x3f);

        for (int j = 4 * i; j < 4 * (i + 1); j++) {
            enc[j] = base64[out[j - i * 4]];
        }

    }
    switch (len % 3) {
        case 1: {
            in[0] = s[3 * i];
            out[0] = ((in[0] & 0xfc) >> 2);
            out[1] = ((in[0] & 0x03) << 4);
            for (int j = 4 * i; j < 4 * (i + 1); j++) {
                if (j < 4 * (i + 1) - 2) {
                    enc[j] = base64[out[j - i * 4]];
                } else {
                    enc[j] = 0x3D;
                }
            }
            break;
        }
        case 2: {
            in[0] = s[3 * i];
            in[1] = s[3 * i + 1];

            out[0] = ((in[0] & 0xfc) >> 2);
            out[1] = ((in[0] & 0x03) << 4) + ((in[1] & 0xf0) >> 4);
            out[2] = ((in[1] & 0x0f) << 2);

            for (int j = 4 * i; j < 4 * (i + 1); j++) {
                if (j < 4 * (i + 1) - 1) {
                    enc[j] = base64[out[j - i * 4]];
                } else {
                    enc[j] = 0x3D;
                }
            }
            break;
        }
    }


    return enc;
}

char *base64_decode(const char *s) {
    unsigned char in[4];
    unsigned char out[3];
    int len = 0,k=0;

    while (s[len] != 0) {
        len++;
    }

    char *dec = new char[len / 4 * 3];

    for (int i = 0; i < len / 4; i++) {
        in[0]=0;
        in[1]=0;
        in[2]=0;
        in[3]=0;

        for (int j = 0; j < 4; j++) {
            if (s[i * 4 + j] != 0x3d) {
                while (base64[in[j]] != s[i * 4 + j]) {
                    in[j]++;
                }
            } else {
                k++;
            }
        }

        out[0] = (in[0] << 2) + ((in[1] & 0x30) >> 4);
        out[1] = ((in[1] & 0xf) << 4) + ((in[2] & 0x3c) >> 2);
        out[2] = ((in[2] & 0x3) << 6) + in[3];

        for (int j = i * 3; j < 3 * (i + 1) - k; j++) {
            dec[j] = out[j - i * 3];
        }
    }

    return dec;
}