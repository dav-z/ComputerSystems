//
//  ArraysofPointers.c
//  zheng_david_lab4
//
//  Created by David Zheng on 9/21/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int students, exams;
void printArray(int grades[students][exams]);
void minimum(int grades[students][exams]);
void maximum(int grades[students][exams]);
void average(int grades[students][exams]);
void end(int grades[students][exams]);

int main(int argc, const char * argv[]) {
    puts("Let's make a 2D array of students and their exam grades.\nHow many students are there?");
    scanf("%d", &students);
    while(students <= 0) {
        puts("You need to have at least 1 student.\nHow many students are there?");
        scanf("%d", &students);
    }
    puts("How many exams did each student take?");
    scanf("%d", &exams);
    while(exams <= 0) {
        puts("Each student should have taken at least 1 exam.\nHow many exams did each student take?");
        scanf("%d", &exams);
    }
    int studentGrades[students][exams];
    int grade;
    for(size_t s = 0; s < students; ++s) {
        for(size_t e = 0; e < exams; ++e) {
            printf("Grade of Exam %zu for Student %zu:\t", e + 1, s + 1);
            scanf("%d", &grade);
            while(grade < 0 || grade > 100) {
                printf("Grades are only between 0 and 100. Please try again.\nGrade of Exam %zu for Student %zu:\t", e + 1, s + 1);
                scanf("%d", &grade);
            }
            if(grade >= 0 && grade <= 100) {
                studentGrades[s][e] = grade;
            }
        }
    }
    printf("\n");
    void (*f[5])(int studentGrades[students][exams]) = {printArray, minimum, maximum, average, end};
    printf("Enter a choice:\n\t0\tPrint the array of grades\n\t1\tFind the minimumgrade\n\t2\tFind the maximum grade\n\t3\tPrint the average on all tests for each student\n\t4\tEnd Program\nYour choice:\t");
    int choice;
    scanf("%d", &choice);
    if(choice >=5 || choice < 0) {
        printf("Your choice was not an option.\nEnter a choice:\n\t0\tPrint the array of grades\n\t1\tFind the minimumgrade\n\t2\tFind the maximum grade\n\t3\tPrint the average on all tests for each student\n\t4\tEnd Program\nYour choice:\t");
        scanf("%d", &choice);
    }
    while(choice >= 0 && choice < 5) {
        printf("\n");
        (*f[choice])(studentGrades);
        printf("Enter a choice:\n\t0\tPrint the array of grades\n\t1\tFind the minimumgrade\n\t2\tFind the maximum grade\n\t3\tPrint the average on all tests for each student\n\t4\tEnd Program\nYour choice:\t");
        scanf("%d", &choice);
    }
    
}

void printArray(int grades[students][exams]) {
    printf("Your Students' Grades:\n");
    for(size_t i = 0; i < students; ++i) {
        printf("\nstudent %zu grades:\t[", i + 1);
        for(size_t j = 0; j < exams - 1; ++j) {
            printf("%d,\t", grades[i][j]);
        }
        printf("%d]", grades[i][exams - 1]);
    }
    printf("\n\n");
}

void minimum(int grades[students][exams]) {
    int lowGrade = 100;
    for(size_t i = 0; i < students; ++i) {
        for(size_t j = 0; j < exams; ++j) {
            if(grades[i][j] < lowGrade) {
                lowGrade = grades[i][j];
            }
        }
    }
    printf("Lowest grade:\t%d\n\n", lowGrade);
}

void maximum(int grades[students][exams]) {
    int highGrade = 0;
    for(size_t i = 0; i < students; ++i) {
        for(size_t j = 0; j < exams; ++j) {
            if(grades[i][j] > highGrade) {
                highGrade = grades[i][j];
            }
        }
    }
    printf("Highest Grade:\t%d\n\n", highGrade);
}

void average(int grades[students][exams]) {
    for(size_t i = 0; i < students; ++i) {
        int total = 0;
        for(size_t j = 0; j < exams; ++j) {
            total += grades[i][j];
        }
        double avg = total / exams;
        printf("The average grade for student %zu is %.2f.\n", i + 1, avg);
    }
    printf("\n");
}

void end(int grades[students][exams]) {
    printf("Goodbye.");
    exit(0);
}
