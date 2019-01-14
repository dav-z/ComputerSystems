//
//  ends_with_ignore_case.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns 1 if suff is a suffix of s ignoriing case or 0 otherwise
int ends_with_ignore_case(char *s, char *suff) {
    int len1 = 0;
    int ret = 1;
    while(s[len1] != '\0') {
        ++len1;
    }
    int len2 = 0;
    while(suff[len2] != '\0') {
        ++len2;
    }
    int j = 0;
    for(int i = len1 - len2; i < len1; ++i) {
        if(s[i] == suff[j]) {
            ++j;
        }
        else {
            ret = 0;
        }
    }
    
    if(ret == 1) {
        printf("The string does end in the given suffix. Returns %d\n\n", ret);
    }
    else {
        printf("The string does not end in the given suffix. Returns %d\n\n", ret);
    }
    return ret;
}

