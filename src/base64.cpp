#include "base64.hpp"
#include <cstring>

char *base64_encode(const char *s) {
    char litters[][2]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                       'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                       'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                       'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                       'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                       'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                       'w', 'x', 'y', 'z', '0', '1', '2', '3',
                       '4', '5', '6', '7', '8', '9', '+', '/'};
    int i, length, j;
    i=1;
    j=0;
    char* decode = new char[length * 2];
    length=strlen(s);
    unsigned char n;
    while (i<=(length/3)){
        n=((unsigned char)(s[i] >> 2));
        memcpy(decode+j,litters[n], 1);
        j++;
        n=((unsigned char)((s[i]<<6)>>2))+((unsigned char)(s[i+1]>>4));
        memcpy(decode+j, litters[n], 1);
        j++;
        n=((unsigned char)((s[i+1]<<4)>>2))+((unsigned char)(s[i+2]>>6));
        memcpy(decode+j, litters[n], 1);
        j++;
        n=((unsigned char)((s[i]<<2)>>2));
        memcpy(decode+j, litters[n], 1);
        j++;
        i++;
    };
    if (length%3==2){
        n=((unsigned char)(s[i] >> 2));
        memcpy(decode+j,litters[n], 1);
        j++;
        n=((unsigned char)((s[i]<<6)>>2))+((unsigned char)(s[i+1]>>4));
        memcpy(decode+j, litters[n], 1);
        j++;
        n=((unsigned char)((s[i+1]<<4)>>2));
        memcpy(decode+j, litters[n], 1);
        j++;
        decode[j]='=';
        decode[j+1]='\0';
    };
    if (length%3==1){
        n=((unsigned char)(s[i] >> 2));
        memcpy(decode+j,litters[n], 1);
        j++;
        n=((unsigned char)((s[i]<<6)>>2));
        memcpy(decode+j, litters[n], 1);
        j++;
        decode[j]='=';
        decode[j+1]='=';
        decode[j+2]='\0';
    };
    if (length%3==0){
        decode[j]='\0';
    }
    return decode;
}

char *base64_decode(const char *s) {
    char litters[][2]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                       'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                       'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                       'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                       'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                       'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                       'w', 'x', 'y', 'z', '0', '1', '2', '3',
                       '4', '5', '6', '7', '8', '9', '+', '/'};
    int i, length, j, ost;
    i=1;
    j=0;
    char* encode = new char[length];
    length=strlen(s);
    unsigned char n, k;
    if (s[length-2]=='='){
        ost=2;}
    if (s[length-1]=='='){
        ost=1;}
    while(i<=(length-ost)/4){
        for (int numb=0; s[i]!=litters[numb]; numb++);
        for (int numb1=0; s[i+1]!=litters[numb1]; numb1++);
        n=(numb<<2)+(numb1>>4);
        encode[j]=n;
        j++;
        for (int numb=0; s[i+1]!=litters[numb]; numb++);
        for (int numb1=0; s[i+2]!=litters[numb1]; numb1++);
        n=(numb<<4)+(numb1>>2);
        encode[j]=n;
        j++;
        for (int numb=0; s[i+2]!=litters[numb]; numb++);
        for (int numb1=0; s[i+3]!=litters[numb1]; numb1++);
        n=(numb<<6)+numb1;
        encode[j]=n;
        j++;
    };
    if (ost!=0){
        if (ost==1){
            for (int numb=0; s[i]!=litters[numb]; numb++);
            for (int numb1=0; s[i+1]!=litters[numb1]; numb1++);
            n=(numb<<2)+(numb1>>4);
            encode[j]=n;
            j++;
            for (int numb=0; s[i+1]!=litters[numb]; numb++);
            for (int numb1=0; s[i+2]!=litters[numb1]; numb1++);
            n=(numb<<4)+(numb1>>2);
            encode[j]=n;
            j++;
            encode[j]='\0';
        } else{
            for (int numb=0; s[i]!=litters[numb]; numb++);
            n=(numb<<2);
            encode[j]=n;
            j++;
            encode[j]='\0';
        };
    } else{
        encode[j]='\0';
    };
    return encode;
}