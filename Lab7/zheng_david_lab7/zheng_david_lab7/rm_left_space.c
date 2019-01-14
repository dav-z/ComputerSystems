//
//  rm_left_space.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

//removes whitespace characters from the beginning of s
void rm_left_space(char *s) {
    int len = 0; // initialize len with size of 0
    while(s[len] == ' ') { // while each char in s exists
        ++len; // add to count of number of chars
    }
    s += len;
    printf("%s%s\n\n", "The new new string without left white spaces is:\n", s);
}
