//
//  David Zheng
//  October 05, 2018
//  CIS2107 Computer Systems and Low-Level Programming
//  Section 4
//  Lab 10
//  NimGame.c
//  Objective: Greate a 2-player Nim Game implementing functions for all actions
//
//  Created by David Zheng on 10/05/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

// defined constants
#define p1 6
#define p2 9
#define p3 7

// defined playerTurn and Piles
typedef enum {
    player1,
    player2
} playerTurn;

struct coinPiles {
    int A;
    int B;
    int C;
} Piles;

// names of players
char usr1[100];
char usr2[100];

// prototypes
void startGame(void);
struct coinPiles getTurn(struct coinPiles Piles);
void Winner(playerTurn Turn, struct coinPiles Piles);

int main(int argc, const char * argv[]) {
    // initialize game
    startGame();
    return 0;
}


// function to start game
void startGame(void) {
    // creates a playerTurn enum called Turn
    playerTurn Turn;
    // defines the values of each pile in struct Piles
    Piles.A = p1;
    Piles.B = p2;
    Piles.C = p3;
    printf("Let's play a game of Nim.\nThis is a 2-player game and you each take turns removing a number coins of your choosing from 1 pile at a time. The person who takes the last coin is the loser.\nThere are 3 piles of coins:\nA:\t%d\tB:\t%d\tC:\t%d\nLet's start!\n\n", p1, p2, p3);
    // gets names of players
    printf("%s", "Enter Player 1's name:\t");
    scanf(" %s", usr1);
    printf("%s", "Enter Player 2's name:\t");
    scanf(" %s", usr2);
    // start with player 1's turn
    Turn = player1;
    // while at least 1 pile has more than 1 coin left
    while(Piles.A + Piles.B + Piles.C > 1) {
        // switch between turns
        switch(Turn) {
                //if it's player 1's turn
            case player1:
                printf("\n%s's turn:\n", usr1);
                // uses turn
                Piles = getTurn(Piles);
                // switch players
                Turn = player2;
                break;
                // if it's player 2's turn
            case player2:
                printf("\n%s's turn:\n", usr2);
                // uses turn
                Piles = getTurn(Piles);
                // switch players
                Turn = player1;
                break;
        }
    }
    // declare winner if there is only 1 coin or if there are no coins left
    Winner(Turn, Piles);
    
}

// function for a turn which takes in and returns a struct of coinPiles
struct coinPiles getTurn(struct coinPiles Piles) {
    char temp;
    // define the char chosenPile
    char chosenPile;
    // define the unsigned int of coins taken
    int cTaken;
    printf("%s", "What pile would you like to take from (A, B, or C):\t");
    // takes in the pile that will be taken from
    scanf(" %c", &chosenPile);
    // changes to uppercase
    chosenPile = toupper(chosenPile);
    // if the chosen pile isn't one of the piles or if pile is empty
    while((chosenPile != 'A' && chosenPile != 'B' && chosenPile != 'C') || (chosenPile == 'A' && Piles.A == 0) || (chosenPile == 'B' && Piles.B == 0) || (chosenPile == 'C' && Piles.C == 0)) {
        printf("Sorry, you can only pick given piles that still have coins. Pick again:\t");
        // rescans the chosen pile
        scanf("%c", &temp);
        scanf(" %c", &chosenPile);
        // changes to uppercase
        chosenPile = toupper(chosenPile);
    }
    printf("How many coins do you want to take from Pile %c:\t", chosenPile);
    // takes in number of coins to be taken from pile
    scanf("%d", &cTaken);
    // if the chosen pile is A
    if(chosenPile == 'A') {
        // if the number of coins to take out is greater than the number of coins in the pile or is less than 1
        while(!(cTaken > 0 && cTaken <= Piles.A)) {
            printf("Sorry, you have to take more than 0 and no more than %d coins from Pile %c. How many coins do you want to take from Pile %c:\t", Piles.A ,chosenPile, chosenPile);
            // rescans the number of coins to take in
            scanf("%c", &temp);
            scanf("%d", &cTaken);
        }
        // modifies the pile
        Piles.A -= cTaken;
    }
    // if the chosen pile is B
    if(chosenPile == 'B') {
        // if the number of coins to take out is greater than the number of coins in the pile or is less than 1
        while(!(cTaken > 0 && cTaken <= Piles.B)) {
            printf("Sorry, you have to take more than 0 and no more than %d coins from Pile %c. How many coins do you want to take from Pile %c:\t", Piles.B ,chosenPile, chosenPile);
            // rescans the number of coins to take in
            scanf("%c", &temp);
            scanf("%d", &cTaken);
        }
        // modifies the pile
        Piles.B -= cTaken;
    }
    // if the chosen pile is C
    if(chosenPile == 'C') {
        // if the number of coins to take out is greater than the number of coins in the pile or is less than 1
        while(!(cTaken > 0 && cTaken <= Piles.C)) {
            printf("Sorry, you have to take more than 0 and no more than %d coins from Pile %c. How many coins do you want to take from Pile %c:\t", Piles.C ,chosenPile, chosenPile);
            // rescans the number of coins to take in
            scanf("%c", &temp);
            scanf("%d", &cTaken);
        }
        // modifies the pile
        Piles.C -= cTaken;
    }
    // prints the new values of each pile as a fancy display
    printf("%s", "\nA:\t");
    for(int i = 0; i < Piles.A; i++) {
        printf("%s", "*");
    }
    printf("%s", "\nB:\t");
    for(int i = 0; i < Piles.B; i++) {
        printf("%s", "*");
    }
    printf("%s", "\nC:\t");
    for(int i = 0; i < Piles.C; i++) {
        printf("%s", "*");
    }
    printf("%s", "\n");
    // returns the modified Piles
    return Piles;
}

// function to announce the winner
void Winner(playerTurn Turn, struct coinPiles Piles) {
    // if all the piles have 0 coins
    if(Piles.A + Piles.B + Piles.C == 0) {
        // depending on the turn
        switch (Turn) {
                // if player 2 made the last move
            case player1:
                printf("\n%s took the last coin.\n\n%s wins!\n", usr2, usr1);
                break;
                // if player 1 made the last move
            case player2:
                printf("\n%s took the last coin.\n\n%s wins!\n", usr1, usr2);
                break;
        }
    }
    // if there is only 1 coin left out of all the piles
    else if(Piles.A + Piles.B + Piles.C == 1) {
        printf("\nThere is only one coin left.\n");
        // depending on the turn
        switch (Turn) {
                // if player 2 made the last move and left only 1 coin
            case player1:
                printf("%s is forced to take the last coin.\n\n%s wins!\n", usr1, usr2);
                break;
                // if player 1 made the last move and left only 1 coin
            case player2:
                printf("%s is forced to take the last coin.\n\n%s wins!\n", usr2, usr1);
                break;
        }
    }
}
