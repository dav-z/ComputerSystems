//
//  take_last.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// change s to only contain last n characters if n is greater than or equal to the length of s, nothing changes
void take_last(char *s, int n){
    int len = 0;
    while(s[len] != '\0') {
        ++len;
    }
    if(n >= len) {
        printf("The length of s is less than or equal to %d, so nothing changes and s is:\n%s\n\n", n, s);
    }
    else {
        char str[n + 1];
        int i = 0;
        while(i < n) {
            str[i] = s[len-n+i];
            i++;
        }
        str[n] = '\0';
        *s = *str;
        printf("The last %d characters of s are:\n%s\n\n", n, str);
    }
}

