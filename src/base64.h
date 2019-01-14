//
// Created by 1 on 13.01.2019.
//

#ifndef UNTITLED10_BASE64_H
#define UNTITLED10_BASE64_H

/*
 * Преобразует(кодирует) переданный массив символов в base64
 */
char *encode(const char *s);

/*
 * Преобразует(декодирует) переданный массив символов из base64
 */
char *decode(const char *s);

#endif //UNTITLED10_BASE64_H
