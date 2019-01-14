//
//  str_chop_all.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns array of string consisting of chars in s split into tokens based on delimeter c followed by NULL pointer
char **str_chop_all(char *s, char c) {
    int i = 0;
    int tok = 0;
    char **tokarr;
    char *t, *p, *r;
    t = s;
    while(*t != '\0') {
        if(*t == c) {
            ++tok;
        }
        ++t;
    }
    ++tok;
    if((tokarr = (char**)malloc((tok + 1) * sizeof(char*))) == '\0') {
        return NULL;
    }
    
    t = s;
    p = t;
    i = 1;
    tok = 0;
    
    while(*t != '\0') {
        if(*t == c) {
            tokarr[tok] = (char *)malloc(i + 1);
            r = tokarr[tok];
            while(p != t) {
                *r = *p;
                ++p;
                ++r;
            }
            *r = '\0';
            ++p;
            ++tok;
        }
        ++t;
        ++i;
    }
    
    tokarr[tok] = (char *)malloc(i + 1);
    r = tokarr[tok];
    while(p != t) {
        *r = *p;
        ++p;
        ++r;
    }
    *r = '\0';
    ++tok;
    tokarr[tok] = NULL;
    
    printf("%s", "The new string array is:\n{");
    for(int x = 0; x < tok; ++x) {
        printf("%s, ", tokarr[x]);
    }
    printf("%s}", tokarr[tok]);
    return tokarr;
}
