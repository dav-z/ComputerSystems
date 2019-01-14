//
//  len_diff.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns the length of s1 minus length of length 2
int len_diff(char *s1, char *s2) {
    int difference;
    int len1 = 0; // initialize len1 with size of 0
    int len2 = 0; // initialize len2 with size of 0
    while(s1[len1] != '\0') { // while each char in s1 exists
        ++len1; // add to count of number of chars
    }
    while(s2[len2] != '\0') { // while each char in s2 exists
        ++len2; // add to count of number of chars
    }
    difference = len1 - len2; // difference is s1 length - s2 length
    return difference;
}
