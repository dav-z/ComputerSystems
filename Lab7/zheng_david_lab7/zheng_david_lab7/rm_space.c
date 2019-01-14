//
//  rm_space.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// removes whitespace characters from beginning and the ending of s
void rm_space(char *s) {
    int len = 0; // initialize len with size of 0
    while(s[len] != '\0') { // while each char in s exists
        ++len; // add to count of number of chars
    }
    while(s[--len] == ' ') {
        ;
    }
    s[len + 1] = '\0';
    int index = 0; // initialize len with size of 0
    while(s[index] == ' ') { // while each char in s exists
        ++index; // add to count of number of chars
    }
    s += index;
    printf("%s%s\n\n", "The new new string without left and right white spaces is:\n", s);
}
