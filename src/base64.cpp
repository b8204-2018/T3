#include "base64.hpp"
#include <cstring>
#include <iostream>

static const char Sim[][2]= { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K",
						  "L", "M", "N", "O", "P", "Q", "R","S", "T","U", "V",
						  "W", "X", "Y", "Z", "a", "b", "c", "d", "e", "f", "g",
						  "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
						  "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2",
						  "3", "4", "5", "6", "7","8", "9", "+", "/" };

char *base64_encode(const char *s) {
	int len = (int)strlen(s);
	unsigned char pos;
	char *decode = new char[len * 2];
	char *add = new char[3];
	if (len % 3 == 0) {
		add[0] = '\0';
	}
	if (len % 3 == 1) {
		add[0] = '=';
		add[1] = '=';
		add[2] = '\0';
	}
	if (len % 3 == 2) {
		add[0] = '=';
		add[1] = '\0';
	}
	int i = 0, thripleCount = 1;
	while (thripleCount <= (len / 3)) {
		pos = ((unsigned char)s[i]) >> 2;
		memcpy(decode + j, Sim[pos], 1);
		j++;
		pos = ((unsigned char)(s[i] << 6) >> 2) | ((unsigned char)s[i + 1] >> 4);
		memcpy(decode + j, Sim[pos], 1);
		j++;
		pos = ((unsigned char)(s[i + 1] << 4) >> 2) | ((unsigned char)s[i + 2] >> 6);
		memcpy(decode + j, Sim[pos], 1);
		j++;
		pos = (unsigned char)(s[i + 2] << 2) >> 2;
		memcpy(decode + j, Sim[pos], 1);
		j++;
		i += 3;
		thripleCount++;
	}
	if (len % 3 == 2) {
		pos = (unsigned char)s[i] >> 2;
		memcpy(decode + j, Sim[pos], 1);
		j++;
		pos = ((unsigned char)(s[i] << 6) >> 2) | (unsigned char)(s[i + 1] >> 4);
		memcpy(decode + j, Sim[pos], 1);
		j++;
		pos = ((unsigned char)(s[i + 1] << 4)) >> 2;
		memcpy(decode + j, Sim[pos], 1);
		j++;
	}
	if (len % 3 == 1) {
		pos = (unsigned char)s[i] >> 2;
		memcpy(decode + j, Sim[pos], 1);
		j++;
		pos = ((unsigned char)(s[i] << 6) >> 2);
		memcpy(decode + j, Sim[pos], 1);
		j++;
	}

	for (int i = 0; i < strlen(add) + 1; i++) {
		memcpy(decode + j, add + i, 1);
		j++;
	}
	return decode;
}

int lin_search(const char key) {
	for (int i = 0; i < 63; i++) {
		if (key ==(char) Sim[i]) {
			return i;
		}
	}
	return -1;
}

char *base64_decode(const char *s) {
	int len = (int)strlen(s), con = 255;
	int temp, decLen;
	if (s[len - 2] == '=') {
		decLen = 3 * len / 4 - 1;
	}
	else if (s[len - 1] == '=') {
		decLen = 3 * len / 4;
	}
	else {
		decLen = 3 * len / 4 + 1;
	}
	char* decoded = new char[decLen];
	for (int i = 0, j = 0; i < len - 1; i += 4, j += 3) {
		temp = 0;
		for (int k = i; k < i + 4; k++) {
			if (lin_search(s[k]) != -1) {
				temp += (lin_search(s[k]) << (3 - (k - i)) * 6);
			}
			else {
				throw std::invalid_argument("Incorrect data");
				return 0;
			}
		}
		for (int k = j; (k < j + 3) && k < decLen; k++) {
			decoded[k] = (char)((temp & (con << (2 - (k - j)) << 3)) >> (2 - (k - j)) << 3);
		}
	}
	decoded[strlen(decoded)] = '\0';
	return decoded;
}
