//
// Created by 1 on 13.01.2019.
//

#include "base64.h"
#include <iostream>
#include <bitset>

#define EMPTY_STRING "Empty string";
#define WRONG_LETTER "Unknown letter in string";
#define INVALID_STRING_LENGTH "Invalid string length";

static char encoding[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                          'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                          'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                          'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

char *encode(const char *s) {

    int i = 0;
    for ( i = 0; s[i] != '\0'; i++);
    int n = i;//кол-во букв в начальной строке

    if (i % 3 == 0) {
        i = (i * 4) / 3 + 1;
    } else {
        i = ((i / 3) + 1) * 4 + 1;
    }

    char *res = new char[i];
    res[i] = '\0';
    int g =0, m=0, l = 0, step =1, z = 0, sdvig;

    for ( ; l < i; m++, l++, step ++) {

        if (step == 4) {
            res[l] = g;
            l++;
            g = 0;
            step = 1;
            z = 0;
        }

        if (m >= n) {
            sdvig = step * 2;
            res[l] = (g << (8 - sdvig));
            g = 0;

        } else {
            sdvig = step * 2;
            res[l] = (s[m] >> sdvig) + (g << (8 - sdvig));
            z = (z<<2) | 3;
            g = s[m] & z;
        }
    }

    sdvig = n % 3;
    l--;

    for(; (sdvig != 3) && (sdvig != 0); l--, res[l] = '=', sdvig++);
    for(int i(0); i < l; res[i] = encoding[res[i]], i++);

    return res;
}

char *decode(const char *s) {


    int l = 0, n = 0, p = 0;

    while (s[l] != '\0')
        l++;


    if (l % 4 != 0) { throw INVALID_STRING_LENGTH }
    else {
        l = 0;
        for (p = 0; (s[p] != '\0') && (s[p] != '='); p++);


    }

    if (p == 0) { throw EMPTY_STRING }
    else {

        n = (p % 4) + ((p / 4) * 3);

        char *res = new char[p];
        res[p] = '\0';
        int i;

        for (; (s[l] != '\0') && (s[l] != '='); l++) {
            for (i = 0; i <= 63; i++) {
                if (encoding[i] == s[l]) {
                    break;
                }
            }
            if (i == 64)
                throw WRONG_LETTER
            else {
                res[l] = i;
            }
        }

        for (int l = 0, step = 1, count = 0, z = 0, sdvig; l < p; step++, l++, count++) {

            if (step == 4) {
                step = 1;
                l++;
                z = 0;
            }

            z = (z >> 2) | 48;
            sdvig = step * 2;
            res[count] = (res[l] << sdvig) + ((res[l + 1] & z) >> (6 - sdvig));
        }
        res[n - 1] = '\0';

        return res;
    }
}