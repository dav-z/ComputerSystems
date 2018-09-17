//
//  Arrays1DDemo.c
//
//  David Zheng
//  September 20, 2018
//  CIS 2107
//  Lab 3: Pricessing1DArrays
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int arr[];
int size; // initialize int size

// function to fill array with random ints
void fillArray() {
    int LOW, HIGH; // initialize ints LOW and HIGH
    printf("Let's create an array of random integers.\n");
    printf("What is the size of the Array?\t");
    scanf("%d", &size); // takes in the size value
    printf("What is the Lower bound?\t");
    scanf("%d", &LOW); // takes in LOW
    printf("What is the Upper bound?\t");
    scanf("%d", &HIGH); // takes in High
    if(size > 0 && HIGH > LOW) { // checks that array can't be size 0 and HIGH is greater than LOW
        int newArr[size]; // creates array with input size
        srand((unsigned int) time(NULL)); // seeds the random generator with time for more accurate generation
        printf("The array is:\n");
        for( int i = 0; i < size; i++) { // from 0 to size inclusive
            int randNum = rand() % (HIGH + 1 - LOW) + LOW; // creates random value in range LOW to HIGH inclusive
            newArr[i] = randNum; // assigns new new random number to the new array
            arr[i] = newArr[i]; // make the original array equal to the new one
            printf("%d\t", arr[i]);
        }
        printf("\n\n");
    }
    else { // if size, LOW, and HIGH aren't within bounds
        if(size == 0) {
            printf("The array can't have a size of 0.\n");
        }
        if(LOW > HIGH) {
            printf("The lower bound can't be greater than the higher bound.\n");
        }
        printf("Please try again.\n");
        fillArray(); // restarts the function
    }
}

// function to find the largest number in an array from indexes LOW to HIGH, inclusive
int findWithRange() {
    int LOW, HIGH; // init low and high variables
    printf("Let's find the maximum value between 2 indexes of the array.\n");
    printf("What is the Lower bound?\t");
    scanf("%d", &LOW); // takes in LOW
    printf("What is the Upper bound?\t");
    scanf("%d", &HIGH); // takes in High
    int largest = arr[LOW]; // sets the first element we are looking at as the largest
    if(LOW < HIGH && HIGH < size && LOW >=0) { // checks that HIGH, LOW, and size are within bounds
        for(int i = LOW + 1; i <= HIGH; i++) { // from the next element after LOW to the HIGH
            if(largest < arr[i]) { // if the largest element is less than the current element
                largest = arr[i]; // set the current element to be the new largest
            }
        }
        printf("The max value within the given range of the array is %d.\n\n", largest);
    }
    else { // if size, LOW, and HIGH aren't within bounds
        if(LOW < 0) {
            printf("The lower index can't be below 0.\n");
        }
        if(HIGH >= size) {
            printf("The higher index can't be greater than the size - 1.\n");
        }
        if(HIGH < LOW) {
            printf("The lower index can't be greater than the upper index.\n");
        }
        printf("Please try again.\n");
        findWithRange(); // restarts the function
    }
    return largest;
}

// function to reverse the order of the array
void reverseArray() {
    printf("We can reverse the array like this:\n");
    int newArr[size]; // creates a new array with size
    for(int i = 0; i < size; i ++) { // from 0 to size - 1
        newArr[i] = arr[size - i - 1]; // the ith term of the new array is equal to the size-ith term of the original array
        printf("%d\t", newArr[i]);
    }
    printf("\n\n");
}

// function to reverse the order of the array only from indexes LOW to HIGH
void reverseRange() {
    int LOW, HIGH;
    printf("We can also reverse only parts of the array between two indexes.\n");
    int newArr[size]; // creates a new array of size 40
    printf("What is your Lower index value?\t");
    scanf("%d", &LOW); // takes in the lower bound
    printf("What is your Upper index value?\t");
    scanf("%d", &HIGH); // takes in the upper bound
    if(HIGH > LOW && HIGH < size && LOW >= 0) { // if upper and lower bounds are within 0 and 39 and lower is less than upper
        printf("The array reversed within the range provided is:\n");
        for(int i = 0; i < LOW; i++) { // from 0 to the lower bound, non inclusive
            newArr[i] = arr[i]; // the element at these indexes of both arrays are the same
            printf("%d\t", newArr[i]);
        }
        for(int j = LOW; j <= HIGH; j++) { // from lower bound to upper bound
            newArr[j] = arr[HIGH - j + LOW]; // the elements from these indexes are reversed from the original array
            printf("%d\t", newArr[j]);
        }
        for(int k = HIGH + 1; k < size; k++) { // remainder of the array
            newArr[k] = arr[k]; // elements are the same in both arrays
            printf("%d\t", newArr[k]);
        }
        printf("\n\n");
    }
    else { // if LOW and HIGH are out of bounds or in wrong order
        if(LOW < 0) {
            printf("The lower index can't be less than 0.\n");
        }
        if(HIGH >= size) {
            printf("The upper index can't be greater than the size - 1.\n");
        }
        if(HIGH < LOW) {
            printf("The lower index can't be greater than the upper index.\n");
        }
        printf("Please try again.\n");
        reverseRange(); // runs the code again
    }
}

// function to find 2 numbers in sequence in an array
int findSequence(void) {
    int index = -1; // sets the index to -1 by default
    int num1, num2; // initializes 2 number variables
    printf("We can look for a sequence of 2 numbers in the array and return the index of the start of the sequence.\n");
    printf("Enter two numbers:\t");
    scanf("%d %d", &num1, &num2); // takes values for num1 and num 2
    for(int i = 0; i < size - 1; i++) { // from 0 to size -2
        if(arr[i] == num1 && arr[i+1] == num2) { // if values at i and i+1 equal values of num1 and num2, respectively
            index = i; // change the index to the index of the first number of the sequence
        }
    }
    if(index != -1) { // if the index is not -1 print out the index of the start of the sequence
        printf("\nThe sequence is found at index: %d\n\n", index);
    }
    else { // if index is -1
        printf("\nThe sequence does not exist, returned value: %d\n\n", index);
    }
    return index;
}

int main(int argc, const char * argv[]) {
    //call all functions in part 1 from main
    fillArray();
    findWithRange();
    reverseArray();
    reverseRange();
    findSequence();
    return 0;
}
