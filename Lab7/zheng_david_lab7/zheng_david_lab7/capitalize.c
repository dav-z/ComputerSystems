//
//  capitalize.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// makes every first letter uppercase and all else lowercase
void capitalize(char *s) {
    if(s[0] >= 'a' && s[0] <= 'z') {
        s[0] = s[0] - 32;
    }
    int len = 1;
    while(s[len] != '\0') {
        if(s[len - 1] == ' ' && s[len] >= 'a' && s[len] <= 'z') {
            s[len] = s[len] - 32;
        }
        else if(s[len - 1] != ' ' && s[len] >= 'A' && s[len] <= 'Z') {
            s[len] = s[len] + 32;
        }
        ++len;
    }
    printf("The new string with Capitalized first letters is:\n%s\n\n", s);
}

