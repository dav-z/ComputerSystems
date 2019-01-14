//
//  ptr_to.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// returns a pointer to the first occurence of n in the string h or NULL if it isnt found
char *ptr_to(char *h, char *n) {
    int i = 0;
    int j = 0;
    int index = 0;
    while((*(h + j) != '\0') && (*(n + i) != '\0')) {
        if(*(n + i) != *(h +j)) {
            j++;
            i=0;
            index = j;
        }
        else {
            i++;
            j++;
        }
    }
    if(*(n + i) == '\0') {
        printf("The return value is a pointer to index %d and returns the string:\n%s\n\n", index, (h + index));
        return (h + index);
    }
    else {
        printf("The substring is not found and returns NULL");
        return NULL;
    }
}
