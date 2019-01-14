//
//  dedup.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns a new string based on s, but without duplicate characters
char *dedup(char *s){
//    int len = 0;
//    while(s[len] != '\0') {
//        ++len;
//    }
//
//    char *str = s;
//
//    int i, j, k;
//
//    for(i = 0; i < len; ++i) {
//        for(j = i + 1; str[j] != '\0'; ++j) {
//            if(str[j] == str[i]) {
//                for(k = j; str[k] != '\0'; ++k) {
//                    str[k] = str[k + 1];
//                }
//            }
//        }
//    }
    
    char *t = s;
    char *x, *y, *z;
    int i;
    int c = 0;
    while(*t != '\0') {
        ++c;
        ++t;
    }
    x = (char*)malloc(c+1);
    z = x;
    for(i = 0; i < c; ++i, ++z) {
        *z = '\0';
        ++z;
    }
    
    t = s;
    y = x;
    while(*t != '\0') {
        z = x;
        while(*z != *t && *z != '\0') {
            ++z;
        }
        if(*z == '\0') {
            *y = *t;
            ++y;
            ++t;
        }
        else {
            ++t;
        }
    }
    *y = '\0';
    return x;
}

