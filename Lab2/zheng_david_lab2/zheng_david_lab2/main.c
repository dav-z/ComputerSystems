//
//  main.c
//  zheng_david_lab2
//
//  Created by David Zheng on 9/7/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// declaring the ints used in code
int initialBal = 5000; // setting the initial balance to $5000 at the beginning of transaction
int deposits, withdrawal;

// define function for view balance
void viewBalance(void) {
    printf("Your current balance is %d.\n", initialBal); // prints what the balance is on the account
}

// define function for withdrawing money
void withdrawing(void) {
    printf("How much would you like to withdraw?\n");
    scanf("%d", &withdrawal); // takes input of withdrawal amount
    if(withdrawal < initialBal && withdrawal > 0) { // if amount is less than total balance and is also greater than 0
        if(withdrawal % 20 == 0) { // sets it to accept only values divisible by 20
            if(withdrawal < 1000){ // if withdrawal is under the daily max of $1000
                initialBal = initialBal - withdrawal; // takes out the withdrawal from what is in the account
            }
            else { // if withdrawal is greater than the daily max of $1000
                printf("Sorry, you can only withdraw up to $1000 a day.\n");
                withdrawing(); // re asks how much to withdraw
            }
        }
        else { // if withdrawal value is not divisible by 20
            if(withdrawal < 1000) { // if value is less than the daily max and is not divisible by 20
                printf("Sorry, you can only withdraw values made up of $20 bills.\n");
                withdrawing();
            }
            else { // if value is more than the dialy max and is not divisible by 20
                printf("Sorry, you can only withdraw up to $1,000 a day, in values made up of $20 bills.\n");
                withdrawing();
            }
        }
    }
    else if(withdrawal < 20) { // if withdrawal amount is under $20. prevents negative withdrawals
        printf("Sorry, you can't withdraw less than $20.\n");
        withdrawing();
    }
    else if(withdrawal > initialBal) { // if withdrawal is greater than what's in the account. prevents account from going negative
        printf("Sorry, you can't withdraw more than what is in your account.\n");
        withdrawing();
    }
    printf("Thank you, your current balance is $ %d.\n", initialBal); // prints out the balance after withdrawal
}

//define function for depositing money
void depositing(void) {
    printf("How much would you like to deposit?\n");
    scanf("%d", &deposits); // takes input of deposit amount
    if(deposits < 10000 && deposits > 0) { // if deposit amount is less than the daily max of $10000 and is not a negative number
        initialBal = initialBal + deposits; // adds the deposit amount to the balance
        printf("Thank you, your current balance is $ %d.\n", initialBal); // prints out the new balance
    }
    else if(deposits < 0) { // if the deposit is less than 0
        printf("Sorry, you can't deposit less than $1.\n");
        withdrawing();
    }
    else if (deposits > 10000){ // if the amount is greater than the daily maximum
        printf("Sorry, you can only deposit up to $10,000 a day.\n");
        depositing();
    }
}

// define function for leaving the atm
void quit(int transactions) {
    printf("Thanks for using this ATM, you've made %d transactions.\n", transactions);
    exit(0); // exits the app
}


int main(int argc, const char * argv[]) {

    int realPin = 3014; // pin number
    int enteredPin; // defines the number entered for pin
    int pinCount = 0; // defines how many attempts at logging in with pin

    printf("Welcome, Nana!\n Please enter your pin:\n");
    scanf("%d", &enteredPin); // asks for pin
    pinCount++; // adds to attempts of logging in by 1
    
    if(enteredPin != realPin) { // if the entered pin is not the same value as the real pin
        while(pinCount < 3 && enteredPin != realPin) { // while the attempts made is less than 3
            int tries = 3 - pinCount; // remaining attempts
            printf("The pin you have entered is incorrect. You have %d tries left.\n Please enter your pin:\n", tries);
            scanf("%d", &enteredPin); // asks for pin again
            pinCount++; // increases # of attempts
            }
        if(pinCount <= 3) { // if attempts is 3 or more
            printf("Too many failed attempts. Logging off.\n");
            exit(1); // logs out
        }
    }
    if (enteredPin == realPin){ // if pin entered is the same value as the real pin
        int trans = 0; // the number of transactions
        int option = 0; // the menu option
        
        printf("What would you like to do?\n 1. Balance\n 2. Cash Withdrawal\n 3. Cash Deposition\n 4. Quit\n" );
        scanf("%d", &option); // takes input for menu option
        
        while(option != 4) { // as long as the user doesn't quit
            if(option == 1) { // if option 1
                viewBalance(); // view balance
            }
            else if(option == 2) { // if option 2
                withdrawing(); // withdraw menu
                trans++; // add to number of transactions
            }
            else if(option == 3) { // if option 3
                depositing(); // deposit menu
                trans++; // add to the number of transactions
            }
            else { // if it is not a number 1,2, or 3
                printf("Sorry, that is not an option. Try again.\n What would you like to do?\n 1. Balance\n 2. Cash Withdrawal\n 3. Cash Deposition\n 4. Quit\n");
                scanf("%d", &option); // asks again for input
                continue;
            }
            printf("Would you like to do anything else?\n 1. Balance\n 2. Cash Withdrawal\n 3. Cash Deposition\n 4. Quit\n"); // asks if there are more transactions
            scanf("%d", &option); // takes menu input
        }
        if(option == 4) { // if option is 4
            quit(trans); // quit the app (atm)
        }
    }
    
    return 0;
}
