//
//  num_in_range.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns number of characters in s1 if it's between the range b and t
int num_in_range(char *s1, char b, char t) {
    int cCount = 0; // initialize count with size of 0
    int c = 0; // initialize c with size of 0
    while(s1[c] != '\0') { // while each char in s exists
        if(s1[c] >= b && s1[c] <= t){ // if the char at i is in range
            ++cCount; // add to count of number of c
        }
        ++c; // go to next char
    }
    return cCount;
}
