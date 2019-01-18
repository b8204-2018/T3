#include "operations.h"
#include <iostream>
#include <bitset>

#define EMPTY_STRING "Empty string";
#define WRONG_LETTER "Unknown letter in string";
#define INVALID_STRING_LENGTH "Invalid string length";

static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'}; // 0 - 63


char *encode(const char *s) {

    if (s[0] == '\0') { throw EMPTY_STRING }
    else {

        /** Count original letters */
        int i = 0;

        while (s[i] != '\0') {
            i++;
        }

        int OSL_count = i;

        /** Count result string letters */
        if (i % 3 == 0) {
            i = (i * 4) / 3 + 1;
        } else {
            i = ((i / 3) + 1) * 4 + 1;
        }

        /** Var */
        char *res = new char[i];
        res[i] = '\0';
        int this_r_part = 0;
        int m_count = 0;
        int sdvig;
        int l = 0;
        int step = 1;

        /** Main algorithm  */
        while (l < i) {


            sdvig = step * 2;

            if (m_count >= OSL_count) {
                res[l] = (this_r_part << (8 - sdvig));
                this_r_part = 0;

            } else {
                res[l] = (s[m_count] >> sdvig) + (this_r_part << (8 - sdvig));
                this_r_part = s[m_count] & (3 + (12 * (step - 1) + (36 * ((step - 1) / 2))));
            }

            m_count++;
            l++;
            step++;

            if (step == 4) {
                res[l] = this_r_part;
                l++;
                this_r_part = 0;
                step = 1;
            }
        }

        /** Empty last bits */
        sdvig = OSL_count % 3;

        l--;
        while ((sdvig != 3) && (sdvig != 0)) {
            l--;
            res[l] = '=';
            sdvig++;
        }

        /** Convert result to original */
        i = 0;

        while (i < l) {
            res[i] = encoding_table[res[i]];
            i++;
        }

        return res;
    }
}

char *decode(const char *s) {

    int l = 0;

    while (s[l] != '\0')
        l++;


    if (l % 4 != 0) {throw INVALID_STRING_LENGTH}
    else {
        l = 0;
        while ((s[l] != '\0') && (s[l] != '=')) {
            l++;
        }

        if (l == 0) { throw EMPTY_STRING }
        else {

            l = (l % 4) + ((l / 4) * 3) + 1;

            char *res = new char[l];
            res[l] = '\0';

            /** Search letter in encoding table */
            l = 0;
            int i;
            while ((s[l] != '\0') && (s[l] != '=')) {
                for (i = 0; i <= 63; i++) {
                    if (encoding_table[i] == s[l]) {
                        break;
                    }
                }
                if (i == 64)
                    throw WRONG_LETTER
                else {
                    res[l] = i;
                    l++;
                }
            }

            /** main algorithm */
            int sdvig;
            int step = 1;
            int new_array_counter = 0;
            l = 0;

            while (s[l] != '\0') {
                sdvig = step * 2;

                res[new_array_counter] = (res[l] << sdvig) + (res[l + 1] >> (6 - sdvig));
                step++;

                l++;

                if (step == 5) {
                    step = 1;
                } else {
                    new_array_counter++;
                }
            }

            return res;
        }
    }
}
