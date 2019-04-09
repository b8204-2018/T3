#ifndef T3_BASE64_H
#define T3_BASE64_H

/*
 * Преобразует(кодирует) переданный массив символов в base64
 */
char *base64_encode(const char *);

/*
 * Преобразует(декодирует) переданный массив символов из base64
 */
char *base64_decode(const char *);

#endif //T3_BASE64_H