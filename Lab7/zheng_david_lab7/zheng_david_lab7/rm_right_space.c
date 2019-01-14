//
//  rm_right_space.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

//removes whitespace characters from the end of s
void rm_right_space(char *s) {
    int len = 0; // initialize len with size of 0
    while(s[len] != '\0') { // while each char in s exists
        ++len; // add to count of number of chars
    }
    while(s[--len] == ' ') {
        ;
    }
    s[len +1 ] = '\0';
    printf("%s%s\n\n", "The new new string without right white spaces is:\n", s);
}
