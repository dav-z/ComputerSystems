//
//  is_empty.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns 1 if s is NULL, consists of only the null character or only whitespaces. otherwise return 0
int is_empty(char *s) {
    int ret = 1;
    int len = 0; // initialize len with size of 0
    while(s[len] != '\0') { // while each char in s exists
        ++len; // add to count of number of chars
    }
    if(len == 0) {
        ret = 1;
    }
    else {
        for(size_t i = 0; i < len; ++i) {
            if(s[i] != ' ') {
                ret = 0;
            }
        }
    }
    if(ret == 1) {
        printf("The string is NULL and returns %d.\n\n", ret);
    }
    else {
        printf("The string has characters that aren't white spaces and returns %d.\n\n", ret);
    }
    return ret;
}

