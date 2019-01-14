//
//  strcmp_ign_case.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

//returns positive number if s1 appears after s2 in dictionary and negative if it before after. returns 0 if theyre equal
int strcmp_ign_case(char *s1, char *s2) {
    int len = 0;
    int ret = 0;
    char c1;
    char c2;
    while(s1[len] != '\0' && s2[len] != '\0' && ret == 0) {
        c1 = s1[len];
        c2 = s2[len];
        if(s1[len] >= 'A' && s1[len] <= 'Z') {
            c1 = c1 + 32;
        }
        if(s2[len] >= 'A' && s2[len] <= 'Z') {
            c2 = c2 + 32;
        }
        if(c1 > c2) {
            ret = 1;
            printf("String 1 comes after String 2 and returns %d.\n\n", ret);
            break;
        }
        else if(c1 < c2) {
            ret = -1;
            printf("String 1 comes before String 2 and returns %d.\n\n", ret);
            break;
        }
        ++len;
    }
    if(ret == 0) {
        printf("String 1 and String 2 are equal and returns %d.\n\n", ret);
    }
    return ret;
}

