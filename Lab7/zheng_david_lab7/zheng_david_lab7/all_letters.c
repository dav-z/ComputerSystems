//
//  all_letters.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/24/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns 1 if string literal contains all letters upper and lowercase, otherwise returns 0
int all_letters(char *s) {
    int c = 0; // initialize c with size of 0
    int allLetters = 1; // set all letters to 1
    while(s[c] != '\0') { // while each char in s exists
        ++c; // add to count of number of chars
    }
    for(int i = 0; i < c ; ++i) { // for # char times
        if(!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')) { // if char at location i in s isn't a letter
            allLetters = 0; // all letters returns 0
        }
    }
    return allLetters;
}
