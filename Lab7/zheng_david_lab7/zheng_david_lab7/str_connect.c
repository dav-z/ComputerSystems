//
//  str_connect.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns string of first n strings in strs with c as separator
char *str_connect(char **strs, int n, char c) {
    char *str;
    int i, j, k;
    int len = 0;
    
    for(i = 0; i < n; ++i) {
        for(j=0; strs[i][j] != '\0'; j++) {
            ++len;
        }
    }
    str = (char*) malloc(sizeof(char)*(len+n+1));
    k = 0;
    for(i = 0; i < n; ++i) {
        for(j=0; strs[i][j] != '\0'; j++) {
            str[k] = strs[i][j];
            k++;
        }
        if(i < n - 1) {
            str[k] = c;
            k++;
        }
    }
    str[k] = '\0';
    printf("%s\n\n", str);
    return str;
}

