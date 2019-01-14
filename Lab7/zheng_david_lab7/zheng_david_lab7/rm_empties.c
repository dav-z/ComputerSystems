//
//  rm_empties.c
//  zheng_david_lab7
//
//  Created by David Zheng on 10/23/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include "main.h"

// words is array of string terminated with a NULL pointer. remove any empty strings
void rm_empties(char **words) {
    int i = 0;
    int j, k;
    int p = 0;
    while(words[i] != NULL) {
        int len = 0;
        for(j = 0; words[i][j] != '\0'; ++j) {
            ++len;
        }
        if(len == 0) {
            k = i;
            while(words[k+1] != NULL) {
                words[k] = words[k + 1];
                k++;
            }
            p++;
        }
        else {
            ++i;
        }
    }
    words[i-p] = NULL;
    printf("The resulting array is:\n{");
    for(int x = 0; x < i-p - 1; ++x) {
        printf("%s, ", words[x]);
    }
    printf("%s}\n\n", words[i - p - 1]);
}

