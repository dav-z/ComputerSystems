//
//  shorten.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// shortens the string
void shorten(char *s, int new_len) {
    s[new_len] = '\0'; // makes the character at new_len the end of string
    printf("%s%s\n\n", "The new string is:\n", s);
}
