//
//  diff.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns number of differences at all index in s1 and s2
int diff(char *s1, char *s2) {
    int difference = 0; // initialize difference at 0
    int len1 = 0; // initialize len1 with size of 0
    int len2 = 0; // initialize len2 with size of 0
    while(s1[len1] != '\0') { // while each char in s1 exists
        ++len1; // add to count of number of chars
    }
    while(s2[len2] != '\0') { // while each char in s2 exists
        ++len2; // add to count of number of chars
    }
    if(len1 >= len2) { // if string 1 is longer than or equal to string 2
        for(int i = 0; i < len2; ++i) { // for every character up to len2
            if(s1[i] != s2[i]) { // if theyre not equal
                ++difference; // add difference
            }
        }
        difference += len1 - len2; // add difference with remaining length
    }
    else { // string2 longer than string 1
        for(int i = 0; i < len1; ++i) { // for all characters up to len1
            if(s1[i] != s2[i]) { // if theyre not equal
                ++difference; // add difference
            }
        }
        difference += len2 - len1; // add difference with the remaining length
    }
    return difference;
}
