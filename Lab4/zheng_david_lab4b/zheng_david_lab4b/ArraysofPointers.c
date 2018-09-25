//
//  ArraysofPointers.c
//  zheng_david_lab4
//
//  Created by David Zheng on 9/21/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int students, exams; // define students and exams

// create prototypes
void printArray(int grades[students][exams]);
void minimum(int grades[students][exams]);
void maximum(int grades[students][exams]);
void average(int grades[students][exams]);
void end(int grades[students][exams]);

int main(int argc, const char * argv[]) {
    puts("Let's make a 2D array of students and their exam grades.\nHow many students are there?");
    scanf("%d", &students); // takes in number of students
    while(students <= 0) { // checks that there is at least 1 student
        puts("You need to have at least 1 student.\nHow many students are there?");
        scanf("%d", &students);
    }
    puts("How many exams did each student take?");
    scanf("%d", &exams); // takes in number of exams
    while(exams <= 0) { // checks that there is at least 1 test
        puts("Each student should have taken at least 1 exam.\nHow many exams did each student take?");
        scanf("%d", &exams);
    }
    int studentGrades[students][exams]; // creates a 2d array of students and their test scores
    int grade; // defines variable int grade
    for(size_t s = 0; s < students; ++s) { // for every student
        for(size_t e = 0; e < exams; ++e) { // for every test each student has taken
            printf("Grade of Exam %zu for Student %zu:\t", e + 1, s + 1);
            scanf("%d", &grade); // takes in grade for each test
            while(grade < 0 || grade > 100) { // checks that grades are between 0 and 100
                printf("Grades are only between 0 and 100. Please try again.\nGrade of Exam %zu for Student %zu:\t", e + 1, s + 1);
                scanf("%d", &grade);
            }
            if(grade >= 0 && grade <= 100) {
                studentGrades[s][e] = grade; // puts the grade into the array
            }
        }
    }
    printf("\n");
    void (*f[5])(int studentGrades[students][exams]) = {printArray, minimum, maximum, average, end}; // initialize an array of 5 pointers to functions that take an int argument and returns void
    printf("Enter a choice:\n\t0\tPrint the array of grades\n\t1\tFind the minimum grade\n\t2\tFind the maximum grade\n\t3\tPrint the average on all tests for each student\n\t4\tEnd Program\nYour choice:\t");
    int choice; // define variable choice
    scanf("%d", &choice); // takes in user input for choice
    if(choice >=5 || choice < 0) { // checks that the choice is valid (between 0 and 5
        printf("Your choice was not an option.\nEnter a choice:\n\t0\tPrint the array of grades\n\t1\tFind the minimum grade\n\t2\tFind the maximum grade\n\t3\tPrint the average on all tests for each student\n\t4\tEnd Program\nYour choice:\t");
        scanf("%d", &choice);
    }
    while(choice >= 0 && choice < 5) { // if choice is valid
        printf("\n");
        (*f[choice])(studentGrades); // invoke function at location choice in array f and pass studentGrades as an argument
        printf("Enter a choice:\n\t0\tPrint the array of grades\n\t1\tFind the minimum grade\n\t2\tFind the maximum grade\n\t3\tPrint the average on all tests for each student\n\t4\tEnd Program\nYour choice:\t");
        scanf("%d", &choice); // asks for another choice after function is ran
    }
    
}

void printArray(int grades[students][exams]) {
    printf("Your Students' Grades:\n");
    for(size_t i = 0; i < students; ++i) { // for every student
        printf("\nstudent %zu grades:\t[", i + 1); // print student # with index 0 being student 1 and so on
        for(size_t j = 0; j < exams - 1; ++j) { // for every exam the current student has taken excluding last one
            printf("%d,\t", grades[i][j]); // print out the grade and comma separator
        }
        printf("%d]", grades[i][exams - 1]); // print out last grade with closing bracket
    }
    printf("\n\n");
}

void minimum(int grades[students][exams]) {
    int lowGrade = 100; // set the lowest grade value to maximum possible grade
    for(size_t i = 0; i < students; ++i) { // for every student
        for(size_t j = 0; j < exams; ++j) { // for every test they have taken
            if(grades[i][j] < lowGrade) { // if the current test is less than the lowGrade
                lowGrade = grades[i][j]; // change lowGrade to the current test grade
            }
        }
    }
    printf("Lowest grade:\t%d\n\n", lowGrade);
}

void maximum(int grades[students][exams]) {
    int highGrade = 0; // set the highest grade value to the lowest possible grade
    for(size_t i = 0; i < students; ++i) { // for every student
        for(size_t j = 0; j < exams; ++j) { // for every exam they have taken
            if(grades[i][j] > highGrade) { // if the current exam grade is greater than highGrade
                highGrade = grades[i][j]; // make the highGrade the current test grade
            }
        }
    }
    printf("Highest Grade:\t%d\n\n", highGrade);
}

void average(int grades[students][exams]) {
    for(size_t i = 0; i < students; ++i) { // for every student
        int total = 0; // set the sum of test grades to 0
        for(size_t j = 0; j < exams; ++j) { // for every test taken by current student
            total += grades[i][j]; // add the current test score to the sum of test grades
        }
        double avg = total / exams; // defines average as sum of grades divided by number of exams
        printf("The average grade for student %zu is %.2f.\n", i + 1, avg);
    }
    printf("\n");
}

void end(int grades[students][exams]) {
    printf("Goodbye.");
    exit(0); // exits the program
}
