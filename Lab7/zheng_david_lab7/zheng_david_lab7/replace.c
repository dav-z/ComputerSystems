//
//  replace.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns copy of s with each instance of pat replaced with rep
char *replace(char *s, char *pat, char *rep){
    int len1 = 0;
    while(s[len1] != '\0') {
        ++len1;
    }
    int len2 = 0;
    while(pat[len2] != '\0') {
        ++len2;
    }
    int len3 = 0;
    while(rep[len3] != '\0') {
        ++len3;
    }
    char *news = (char*)malloc(sizeof(char) * (len1 + 200));
    int i, j, k;
    int start = -1;
    for(k = 0, i = 0; i < len1; i++) {
        if((len1 - i >= len2) && (*(s + i) == *(pat))) {
            start = i;
            for(j = 1; j < len2; j++) {
                if(*(s + i + j) != *(pat + j)) {
                    start = -1;
                    break;
                }
            }
            if(start != -1) {
                for(j = 0; j < len3; j++, k++) {
                    *(news + k) = *(rep + j);
                }
                i = i + len2 - 1;
            }
            else {
                *(news + k) = *(s + i);
                k++;
            }
        }
        else {
            *(news + k) = *(s + i);
            k++;
        }
    }
    *(news + k) = '\0';
    printf("The new string with replaced substring is:\n%s\n\n", news);
    return news;
}

