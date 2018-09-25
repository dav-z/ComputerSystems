//
//  Arrays2D.c
//  zheng_david_lab4
//
//  Created by David Zheng on 9/21/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>

int ROW, COL; // define ROW and COL

// create prototypes
void max(int arr[ROW][COL]);
void displayOutputs(int arr[ROW][COL]);
void rowSum(int arr[ROW][COL]);
void columnSum(int arr[ROW][COL]);
void isSquare(int ROW, int COL);

int main(int argc, const char * argv[]) {
    puts("Let's make a 2D array.\nHow many rows are in your array?");
    scanf("%d", &ROW); // take in value for ROW
    while(ROW <= 0) { // checks that there is at least 1 row
        puts("You need to have at least 1 row.\nHow many rows are in your array?");
        scanf("%d", &ROW);
    }
    puts("How many columns are in your array?");
    scanf("%d", &COL); // take in value for COL
    while(COL <= 0) { // checks that there is at least 1 column
        puts("You need to have at least 1 column.\nHow many columns are in your array?");
        scanf("%d", &COL);
    }
    int arr[ROW][COL]; // creates a 2d array with ROW rows and COL columns
    for(size_t r = 0; r < ROW; ++r) { // for every row
        for(size_t c = 0; c < COL; ++c) { // for every element in every row
            printf("enter\t[%zu][%zu]:\t", r, c);
            int value;
            scanf("%d", &value); // take in value
            arr[r][c] = value; // put value in array
        }
    }
    printf("\n");
    
    max(arr);
    rowSum(arr);
    columnSum(arr);
    isSquare(ROW, COL);
    displayOutputs(arr);
    
    return 0;
}

void max(int arr[ROW][COL]) {
    int max = arr[0][0]; // set the max value to first element in array
    for(size_t i = 0; i < ROW; ++i) {
        for(size_t j = 0; j < COL; ++j) { // for every element in array
            if(arr[i][j] > max) { // if the current element is greater than max
                max = arr[i][j]; // make the current element max
            }
        }
    }
    printf("Your maximum value of the 2D array is: %d\n\n", max);
}

void rowSum(int arr[ROW][COL]) {
    for(size_t i = 0; i < ROW; ++i) { // for every row
        int sum = 0; // sum starts at 0
        for(size_t j = 0; j < COL; ++j) { // for every element in current row
            sum += arr[i][j]; // add current element value to sum
        }
        size_t row = i + 1;
        printf("The sum of row %zu = %d.\n", row, sum);
    }
    printf("\n");
}

void columnSum(int arr[ROW][COL]) {
    for(size_t i = 0; i < COL; ++i) { // for every column
        int sum = 0; // sum starts at 0
        for(size_t j = 0; j < ROW; j++) { // for every element in current column
            sum += arr[j][i]; // add current element to sum
        }
        size_t col = i + 1;
        printf("The sum of column %zu = %d.\n", col, sum);
    }
    printf("\n");
}


void isSquare(int ROW, int COL) {
    if(ROW == COL) { // if there are as many rows as there are columns
        printf("The array is square because there are %d rows and %d columns.\n", ROW, COL);
    }
    else {
        printf("The array is not square because there are %d rows and %d columns.\n", ROW, COL);
    }
    printf("\n");
}

void displayOutputs(int arr[ROW][COL]) {
    puts("Your new array is:");
    for(size_t i = 0; i < ROW; ++i) { // for every row
        printf("["); // open bracket
        for(size_t j = 0; j < COL - 1; ++j) { // for every element in row excluding the last one
            printf("%d,\t", arr[i][j]); // print out element with a comma at the end
        }
        printf("%d", arr[i][COL - 1]); // print out last element
        printf("]\n"); // closing bracket
    }
    printf("\n");
}
