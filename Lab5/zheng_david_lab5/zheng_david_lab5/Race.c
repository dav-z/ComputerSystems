//
//  David Zheng
//  September 28, 2018
//  CIS2107 Computer Systems and Low-Level Programming
//  Section 4
//  Lab 5
//  Race.c
//  Objective: To design and implement functions to process pointers.
//
//  Created by David Zheng on 9/28/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int finish = 70;
int tPos = 1;
int hPos = 1;
int winner = 0;
int race(const int *tPtr, const int *hPtr, int *winPtr);
void tortoise(int percent, int *tPtr);
void hare(int percent, int *hPtr);

int main(int argc, const char * argv[]) {
    srand((unsigned int) (time(NULL)));

    while(winner == 0) {
        int percent = 1 + (rand() % 10);
        tortoise(percent, &tPos);
        hare(percent, &hPos);
        race(&tPos, &hPos, &winner);
        sleep(1);
    }
    
    if(winner == 1) {
        if(tPos > hPos) {
            printf("%s", "TORTOISE WINS!!! YAY!!!\n");
        }
        else {
            printf("%s", "Hare wins. Yuch.\n");
        }
    }
    else if(winner == 2) {
        printf("%s", "It's a tie.\n");
    }
    
}

int race(const int *tPtr, const int *hPtr, int *winPtr) {
    if(*tPtr == *hPtr) {
        for(int i = 1; i < *tPtr; ++i) {
            printf("%s", " ");
        }
        printf("OUCH!!!");
        for(int j = *tPtr + 1; j <= finish; ++j) {
            printf("%s", " ");
        }
    }
    else if(*tPtr > *hPtr) {
        for(int i = 1; i < *hPtr; ++i) {
            printf("%s", " ");
        }
        printf("%s", "H");
        for(int j = *hPtr + 1; j < *tPtr; ++j) {
            printf("%s", " ");
        }
        printf("%s", "T");
        for(int k = *tPtr + 1; k <= finish; ++k) {
            printf("%s", " ");
        }
    }
    else {
        for(int i = 1; i < *tPtr; ++i) {
            printf("%s", " ");
        }
        printf("%s", "T");
        for(int j = *tPtr + 1; j < *hPtr; ++j) {
            printf("%s", " ");
        }
        printf("%s", "H");
        for(int k = *hPtr + 1; k <= finish; ++k) {
            printf("%s", " ");
        }
    }
    printf("\n");
    if(*tPtr == finish) {
        ++*winPtr;
    }
    if(*hPtr == finish) {
        ++*winPtr;
    }
    return *winPtr;
}

void tortoise(int percent, int *tPtr) {
    if(percent <= 5) { // if percent is from 1 to 5 inclusive
        *tPtr += 3;
    }
    else if(percent > 5 && percent <= 7) {
        *tPtr -= 6;
    }
    else if (percent > 7) {
        *tPtr += 1;
    }
    if(*tPtr < 1) {
        *tPtr = 1;
    }
    else if(*tPtr >= finish) {
        *tPtr = finish;
    }
}

void hare(int percent, int *hPtr) {
    if(percent <= 2) { // sleep
        ;
    }
    else if(percent > 2 && percent <= 4) { // big hop
        *hPtr += 9;
    }
    else if(percent == 5) { // big slip
        *hPtr -= 12;
    }
    else if(percent > 5 && percent <= 8) { // small hop
        *hPtr += 1;
    }
    else if(percent > 8) { // small slip
        *hPtr -= 2;
    }
    if(*hPtr < 1) {
        *hPtr = 1;
    }
    else if(*hPtr >= finish) {
        *hPtr = finish;
    }
}
