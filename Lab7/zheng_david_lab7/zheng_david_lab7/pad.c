//
//  pad.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

//returns new string of all letters in s but with padding at the end, so total length is an even multiple of s. if length of s is already even multiple of d, return s. return NULL on failure or if s is NULL.
char *pad(char *s, int d) {
    int len = 0;
    while(s[len] != '\0') {
        ++len;
    }
    if(len <= d) {
        if((len % d == 0) && (len % 2 == 0)) {
            printf("The length of s is already an even multiple of %d. Returns:\n%s\n\n", d, s);
            return s;
        }
        else {
            int newlen = len;
            if(d % 2 == 0) {
                newlen = d;
            }
            else {
                newlen = d * 2;
            }
            char *str = s;
            for(int i = 0; i < len; ++i) {
                str[i] = s[i];
            }
            for(int j = len; j < newlen; ++j) {
                str[j] = ' ';
            }
            str[newlen] = '\0';
            printf("The new string with padding is:\n%s\n\n", str);
            return str;
        }
    }
    else {
        printf("The length of s is greater than %d. Returns NULL.\n\n", d);
        return NULL;
    }
}

