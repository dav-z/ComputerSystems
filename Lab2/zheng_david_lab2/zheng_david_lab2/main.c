//
//  main.c
//  zheng_david_lab2
//
//  Created by David Zheng on 9/7/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int initialBal = 5000;
int deposits, withdrawal;

void viewBalance(void) {
    printf("Your current balance is %d.\n", initialBal);
}

void withdrawing(void) {
    printf("How much would you like to withdraw?\n");
    scanf("%d", &withdrawal);
    if(withdrawal < initialBal && withdrawal > 0) {
        if(withdrawal % 20 == 0) {
            if(withdrawal < 1000){
                initialBal = initialBal - withdrawal;
            }
            else {
                printf("Sorry, you can only withdraw up to $1000 a day.\n");
                withdrawing();
            }
        }
        else {
            if(withdrawal > 1000) {
                printf("Sorry, you can only withdraw values made up of $20 bills.\n");
                withdrawing();
            }
            else {
                printf("Sorry, you can only withdraw up to $1,000 a day, in values made up of $20 bills.\n");
                withdrawing();
            }
        }
    }
    else if(withdrawal < 0) {
        printf("Sorry, you can't withdraw less than $20.\n");
        withdrawing();
    }
    else {
        printf("Sorry, you can't withdraw more than what is in your account.\n");
        withdrawing();
    }
    printf("Thank you, your current balance is $ %d.\n", initialBal);
}

void depositing(void) {
    printf("How much would you like to deposit?\n");
    scanf("%d", &deposits);
    if(deposits < 10000 && deposits > 0) {
        initialBal = initialBal + deposits;
        printf("Thank you, your current balance is $ %d.\n", initialBal);
    }
    else if(deposits < 0) {
        printf("Sorry, you can't deposit less than $1.\n");
        withdrawing();
    }
    else{
        printf("Sorry, you can only deposit up to $10,000 a day.\n");
        depositing();
    }
}

void quit(int choices) {
    printf("Thanks for using this ATM, you made %d transactions.\n", choices);
    exit(0);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int realPin = 3014;
    int enteredPin;
    int pinCount = 0;

//    int menu(int menuOption, int bal, int withdraw, int deposit);
    printf("Welcome, Nana!\n Please enter your pin:\n");
    scanf("%d", &enteredPin);
    pinCount++;
    
    if(enteredPin != realPin) {
        while(pinCount < 3 && enteredPin != realPin) {
            int tries = 3 - pinCount;
            printf("The pin you have entered is incorrect. You have %d tries left.\n Please enter your pin:\n", tries);
            scanf("%d", &enteredPin);
            pinCount++;
            }
        if(pinCount <= 3) {
            printf("Too many failed attempts. Logging off.\n");
            exit(1);
        }
    }
    if (enteredPin == realPin){
        int choices = 0;
        int option = 0;
        
        printf("What would you like to do?\n 1. Balance\n 2. Cash Withdrawal\n 3. Cash Deposition\n 4. Quit\n" );
        scanf("%d", &option);
        
        while(option != 4) {
            if(option == 1) {
                viewBalance();
            }
            else if(option == 2) {
                withdrawing();
                choices++;
            }
            else if(option == 3) {
                depositing();
                choices++;
            }
            else {
                printf("Sorry, not an option. Try again.\n What would you like to do?\n 1. Balance\n 2. Cash Withdrawal\n 3. Cash Deposition\n 4. Quit\n");
                scanf("%d", &option);
                continue;
            }
            printf("Would you like to do anything else?\n 1. Balance\n 2. Cash Withdrawal\n 3. Cash Deposition\n 4. Quit\n");
            scanf("%d", &option);
        }
        if(option == 4) {
            quit(choices);
        }
    }
    
    return 0;
}
