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

const int finish = 70; // defines the finish spot
int tPos = 1; // sets the tortoise position at 1
int hPos = 1; // sets the hare position at 1
int winner = 0; // sets 0 winners
// building prototypes
int race(const int *tPtr, const int *hPtr, int *winPtr);
void tortoise(const int *percent, int *tPtr);
void hare(const int *percent, int *hPtr);

int main(int argc, const char * argv[]) {
    srand((unsigned int) (time(NULL))); // allows for random ints
    puts("BANG !!!!!\nAND THEY'RE OFF !!!!!");

    while(winner == 0) { // while there are no winners
        int percent = 1 + (rand() % 10); // sets percent as random number 1-10
        tortoise(&percent, &tPos); // moves tortoise, passes location of tPos and location of percent
        hare(&percent, &hPos); // moves hare, passes location of hPos and location of percent
        race(&tPos, &hPos, &winner); // prints location of race, passes location of tPos, hPos, and winner
        sleep(1); // pauses for 1 second every iteration
    }
    
    if(winner == 1) { // if there is one winner
        if(tPos > hPos) { // if tortoise position is greater than hare
            printf("%s", "TORTOISE WINS!!! YAY!!!\n");
        }
        else { // or if the hare position is greater than tortoise
            printf("%s", "Hare wins. Yuch.\n");
        }
    }
    else if(winner == 2) { // if there are two winners
        printf("%s", "It's a tie.\n");
    }
    
}

// function race that returns the int of how many winners there are and accepts 2 pointers to constant ints and 1 pointer to an int
int race(const int *tPtr, const int *hPtr, int *winPtr) {
    if(*tPtr == *hPtr) { // if the position of tortoise and hare are equal
        for(int i = 1; i < *tPtr; ++i) { // up to their location
            printf("%s", " "); // print the amount of spaces traveled
        }
        printf("OUCH!!!"); // print ouch at location
        for(int j = *tPtr + 1; j <= finish; ++j) { // from next location until finish line
            printf("%s", " "); // print remaining locations
        }
    }
    else if(*tPtr > *hPtr) { // if tortoise location is greater than hare location
        for(int i = 1; i < *hPtr; ++i) { // print spaces up until hare's location
            printf("%s", " ");
        }
        printf("%s", "H"); // print hare's location
        for(int j = *hPtr + 1; j < *tPtr; ++j) { // print remaining spaces until tortoise's location
            printf("%s", " ");
        }
        printf("%s", "T"); // print tortoise location
        for(int k = *tPtr + 1; k <= finish; ++k) { // print remaining spaces to finish line
            printf("%s", " ");
        }
    }
    else { // if location of hare is greater than location of tortoise
        for(int i = 1; i < *tPtr; ++i) { // print spaces up to tortoise location
            printf("%s", " ");
        }
        printf("%s", "T"); // print tortoise location
        for(int j = *tPtr + 1; j < *hPtr; ++j) { // print spaces up to hare location
            printf("%s", " ");
        }
        printf("%s", "H"); // print hare location
        for(int k = *hPtr + 1; k <= finish; ++k) { // print remaining spaces to finish line
            printf("%s", " ");
        }
    }
    printf("\n");
    if(*tPtr == finish) { // if tortoise location reaches finish line
        ++*winPtr; // add winner
    }
    if(*hPtr == finish) { // if hare location reaches finish line
        ++*winPtr; // add winner
    }
    return *winPtr; // return # of winners
}

// function returns void, takes 1 pointer to int and 1 pointer to a const int
void tortoise(const int *percent, int *tPtr) {
    if(*percent <= 5) { // if percent is from 1 to 5 inclusive
        *tPtr += 3; // move position 3 to the right
    }
    else if(*percent > 5 && *percent <= 7) { // if percent is 6 to 7
        *tPtr -= 6; // move to left 6
    }
    else if (*percent > 7) { // if percent greater than 7
        *tPtr += 1; // move position right 1
    }
    if(*tPtr < 1) { // if position is less than one
        *tPtr = 1; // move position to 1
    }
    else if(*tPtr >= finish) { // if position is finish line or more
        *tPtr = finish; // move position to finish line
    }
}

// function returns void, takes 1 pointer to int and 1 pointer to a const int
void hare(const int *percent, int *hPtr) {
    if(*percent <= 2) { // 1-2
        ;
    }
    else if(*percent > 2 && *percent <= 4) { // 3-4
        *hPtr += 9; // move position right 9
    }
    else if(*percent == 5) { // big slip @ 5
        *hPtr -= 12; // move left 12
    }
    else if(*percent > 5 && *percent <= 8) { // 6-8
        *hPtr += 1; // move right 1
    }
    else if(*percent > 8) { // greater than 8
        *hPtr -= 2; // move left 2
    }
    if(*hPtr < 1) { // if position is less than one
        *hPtr = 1; // move position to 1
    }
    else if(*hPtr >= finish) { // if position is finish line or more
        *hPtr = finish; // move position to finish line
    }
}
