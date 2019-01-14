//
//  str_zip.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns new string of all the characters interleaved
char *str_zip(char *s1, char *s2) {
    int len1 = 0; // initialize len with size of 0
    while(s1[len1] != '\0') { // while each char in s exists
        ++len1; // add to count of number of chars
    }
    int len2 = 0; // initialize len with size of 0
    while(s2[len2] != '\0') { // while each char in s exists
        ++len2; // add to count of number of chars
    }
    int len = len1 + len2 + 1;
    char str[len];
    int x = 0;
    int y = 0;
    int i = 0;
    if(len1 > len2) {
        while(i <= 2*len2) {
            if(i % 2 == 0) {
                str[i] = s1[x];
                x++;
                i++;
            }
            else {
                str[i] = s2[y];
                y++;
                i++;
            }
        }
        for(int j = 2*len2+1; j < len; ++j) {
            str[j] = s1[x++];
        }
    }
    
    else if(len1 < len2) {
        while(i <= 2*len1 - 1) {
            if(i % 2 == 0) {
                str[i] = s1[x];
                x++;
                i++;
            }
            else {
                str[i] = s2[y];
                y++;
                i++;
            }
        }
        for(int j = 2*len1; j < len; ++j) {
            str[j] = s2[y++];
        }
    }
    
    else {
        for(i = 0; i <= len; ++i) {
            if(i % 2 == 0) {
                str[i] = s1[x++];
            }
            else {
                str[i] = s2[y++];
            }
        }
        
    }
    str[len] = '\0';
    char *s = str;
    return s;
}

