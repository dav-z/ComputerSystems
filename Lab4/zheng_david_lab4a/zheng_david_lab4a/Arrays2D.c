//
//  Arrays2D.c
//  zheng_david_lab4
//
//  Created by David Zheng on 9/21/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>

int ROW, COL;

// creates prototypes of functions
void max(int arr[ROW][COL]);
void displayOutputs(int arr[ROW][COL]);
void rowSum(int arr[ROW][COL]);
void columnSum(int arr[ROW][COL]);
void isSquare(int ROW, int COL);

int main(int argc, const char * argv[]) {
    puts("Let's make a 2D array.\nHow many rows are in your array?");
    scanf("%d", &ROW);
    while(ROW <= 0) {
        puts("You need to have at least 1 row.\nHow many rows are in your array?");
        scanf("%d", &ROW);
    }
    puts("How many columns are in your array?");
    scanf("%d", &COL);
    while(COL <= 0) {
        puts("You need to have at least 1 column.\nHow many columns are in your array?");
        scanf("%d", &COL);
    }
    int arr[ROW][COL];
    for(size_t r = 0; r < ROW; ++r) {
        for(size_t c = 0; c < COL; ++c) {
            printf("enter\t[%zu][%zu]:\t", r, c);
            int value;
            scanf("%d", &value);
            arr[r][c] = value;
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
    int max = -1;
    for(size_t i = 0; i < ROW; ++i) {
        for(size_t j = 0; j < COL; ++j) {
            if(arr[i][j] > max || max == -1) {
                max = arr[i][j];
            }
        }
    }
    printf("Your maximum value of the 2D array is: %d\n\n", max);
}

void rowSum(int arr[ROW][COL]) {
    for(size_t i = 0; i < ROW; ++i) {
        int sum = 0;
        for(size_t j = 0; j < COL; ++j) {
            sum += arr[i][j];
        }
        size_t row = i + 1;
        printf("The sum of row %zu = %d.\n", row, sum);
    }
    printf("\n");
}

void columnSum(int arr[ROW][COL]) {
    for(size_t i = 0; i < COL; ++i) {
        int sum = 0;
        for(size_t j = 0; j < ROW; j++) {
            sum += arr[j][i];
        }
        size_t col = i + 1;
        printf("The sum of column %zu = %d.\n", col, sum);
    }
    printf("\n");
}


void isSquare(int ROW, int COL) {
    if(ROW == COL) {
        printf("The array is square because there are %d rows and %d columns.\n", ROW, COL);
    }
    else {
        printf("The array is not square because there are %d rows and %d columns.\n", ROW, COL);
    }
    printf("\n");
}

void displayOutputs(int arr[ROW][COL]) {
    puts("Your new array is:");
    for(size_t i = 0; i < ROW; ++i) {
        printf("[");
        for(size_t j = 0; j < COL - 1; ++j) {
            printf("%d,\t", arr[i][j]);
        }
        printf("%d", arr[i][COL - 1]);
        printf("]\n");
    }
    printf("\n");
}
