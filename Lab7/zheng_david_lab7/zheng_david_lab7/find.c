//
//  find.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

//returns the index of the first occurence of n in the string h, or -1 if not found
int find(char *h, char *n) {
    int i = 0;
    int j = 0;
    int index = 0;
    while((*(h + j) != '\0') && (*(n + i) != '\0')) {
        if(*(n + i) != *(h +j)) {
            ++j;
            i=0;
            index = j;
        }
        else {
            ++i;
            ++j;
        }
    }
    if(*(n + i) == '\0') {
        printf("The index where the substring starts is at index %d.\n\n", index);
        return index;
    }
    else {
        index = -1;
        printf("The substring is not found and returns %d.\n\n", index);
        return index;
    }
}

