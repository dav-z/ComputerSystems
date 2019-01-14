//
//  repeat.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns string s, x times, with sep in between
char *repeat(char *s, int x, char sep) {
    int len = 0;
    while(s[len] != '\0') {
        ++len;
    }
    int newlen = x * (len + 1);
    char str[newlen];
    for(int i = 0; i < newlen - 1; ++i) {
        int n = 0;
        while(n < len) {
            str[i] = s[n];
            i++;
            n++;
        }
        str[i] = sep;
        n = 0;
    }
    str[newlen - 1] = '\0';
    char *s1 = str;
    printf("The new string repeated is:\n%s\n\n", s1);
    return s1;
}

