//
//  David Zheng
//  October 05, 2018
//  CIS2107 Computer Systems and Low-Level Programming
//  Section 4
//  Lab 6
//  Manual.c
//  Objective: To design and implement functionsto process characters and strings.
//
//  Created by David Zheng on 10/05/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//build out prototypes
void upperLower(char *s);
void convertStrtoInt(char *str1, char *str2, char *str3, char *str4);
void convertStrtoFloat(char *str1, char *str2, char *str3, char *str4);
void compareStr(char *s1, char *s2);
void comparePartialStr(char *s1, char *s2, size_t numChar);
void randomize(void);
void tokenizeTelNum(char *phoneNum);
void reverse(char *s);
void countSubstr(char *s1, char *s2);
void countChar(char *s, char c);
void countAlpha(char *s);
void countWords(char *s);
void startsWithB(const char* arr[10][100]);
void endsWithed(char* arr[10][100]);

int main(int argc, const char * argv[]) {
    char test1[100]; // creates char array of size 100
    puts("Insert a line of text to be transformed to all uppercase and all lowercase.");
    scanf("%[^\n]s", test1);
    upperLower(test1); // runs test1
    // create 4 char arrays of size 100 each
    char test21[100];
    char test22[100];
    char test23[100];
    char test24[100];
    puts("Insert the four integers separated by spaces to be stored as strings.");
    scanf("%s %s %s %s", test21, test22, test23, test24); // scans in 4 values separated by spaces
    convertStrtoInt(test21, test22, test23, test24); // runs test2
    // create 4 char arrays of size 100 each
    char test31[100];
    char test32[100];
    char test33[100];
    char test34[100];
    puts("Insert the four doubles separated by spaces to be stored as strings.");
    scanf("%s %s %s %s", test31, test32, test33, test34); // scans in 4 values separated by spaces
    convertStrtoFloat(test31, test32, test33, test34); // runs test3
    // create 2 char arrays of size 100 each
    char s41[100];
    char s42[100];
    char temp; // temp char to clear
    puts("Input the first string to be compared.");
    scanf("%c", &temp); // clear scan
    scanf("%[^\n]", s41); //scans 1st string until new line
    puts("Input the second string to be compared.");
    scanf("%c", &temp); // clear scan
    scanf("%[^\n]", s42); // scans 2nd string until new line
    compareStr(s41, s42); // runs test4
    // create 2 char arrays of size 100 each
    char s51[100];
    char s52[100];
    size_t numChar5; // creates a size_t for index comparison
    puts("Input the first string to be compared by index.");
    scanf("%c", &temp); // clear scan
    scanf("%[^\n]", s51); // scans 1st string until new line
    puts("Input the second string to be compared by index.");
    scanf("%c", &temp); // clear scan
    scanf("%[^\n]", s52); // scans 2nd string until new line
    puts("Input the number of characters to be compared.");
    scanf("%c", &temp); // clear scan
    scanf("%lu", &numChar5); // scans index to be compared
    comparePartialStr(s51, s52, numChar5); // runs test5
    randomize(); // runs test6
    char phoneNum[15]; // creates char array to fit number in format
    puts("Insert a phone number in the format of (xxx) xxx-xxx to display just the number.");
    scanf("%c", &temp); // clear scan
    scanf("%[^\n]", phoneNum); // scans number until new line
    tokenizeTelNum(phoneNum); // runs test 7
    char s8[100]; // creates char array of size 100
    puts("Insert a line of text to reverse the sentence");
    scanf("%c", &temp); // clears scan
    scanf("%[^\n]s", s8); // scans string until new line
    reverse(s8); // runs test8
    // creates 2 char arrays of size 100
    char s91[100];
    char s92[100];
    puts("Insert multiple lines of text. Finish the input by pressing \"tab\" followed by \"enter\" to find how many times a substring appears within the string.");
    scanf("%c", &temp); // clear scan
    scanf("%[^\t]", s91); // scans until tab and new line
    puts("What substring do you want to search for?");
    scanf("%c\n", &temp); // clear scan
    scanf("%[^\n]", s92); // scan until new line
    countSubstr(s91, s92); // runs test9
    // creates 2 char arrays of size 100
    char s10[100];
    char c10;
    puts("Insert multiple lines of text. Finish the input by pressing \"tab\" followed by \"enter\" to find the number of times a letter appears in the string.");
    scanf("%[^\t]", s10); // scans until tab then new line
    puts("What character do you want to search for?");
    scanf(" %c", &c10); // scans char
    countChar(s10, c10); //runs test10
    char s11[100]; // create char array of size 100
    puts("\n\n");
    puts("Insert multiple lines of text. Finish the input by pressing \"tab\" followed by \"enter\" to see how many of each letters are in the strings.");
    scanf("%c", &temp); // clear scan
    scanf("%[^\t]", s11); // scans until tab then enter
    scanf("%c", &temp); //clear scan
    countAlpha(s11); // runs test 11
    char s12[100]; // creates char array of size 100
    puts("Insert a line of text to see how many words are in the string.");
    scanf("%c", &temp); // clear scan
    scanf("%[^\n]", s12); // scans until new line
    countWords(s12); // runs test12
    char* arr13[10][100]; // creates a char array of 10 strings of size 100 each
    puts("Insert 10 strings separated by new lines to see which ones begin with \"B\" or \"b\".");
    scanf("%c", &temp); // clears scan
    scanf("%[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]", arr13[0], arr13[1], arr13[2], arr13[3], arr13[4], arr13[5], arr13[6], arr13[7], arr13[8], arr13[9]); // scans 10 strings separated by new line
    startsWithB(arr13); // runs test13
    char* arr14[10][100]; // creatres a char array of 10 strings of size 100 each
    puts("Insert 10 strings separated by new lines to see which ones end with \"ed\".");
    scanf("%c", &temp); // clear scan
    scanf("%[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %[^\n]", arr14[0], arr14[1], arr14[2], arr14[3], arr14[4], arr14[5], arr14[6], arr14[7], arr14[8], arr14[9]); // scans 10 strings separated by new line
    endsWithed(arr14); // runs test14
}

// prints input in all caps and all lowercase
void upperLower(char *s) {
    for(size_t i = 0; i < strlen(s); ++i) { // for every char in s
        s[i] = toupper(s[i]); // change char to uppercase
    }
    printf("Uppercase:\t%s\n", s);
    for(size_t j = 0; j < strlen(s); ++j) { // for every char in s
        s[j] = tolower(s[j]); // change char to lowercase
    }
    printf("Lowercase:\t%s\n\n", s);
}

// converts strings to int
void convertStrtoInt(char *str1, char *str2, char *str3, char *str4) {
    int sum = 0; // initialize sum
    // use strtol to change strings to int
    int int1 = (int) strtol(str1, (char**)NULL, 0);
    int int2 = (int) strtol(str2, (char**)NULL, 0);
    int int3 = (int) strtol(str3, (char**)NULL, 0);
    int int4 = (int) strtol(str4, (char**)NULL, 0);
    sum = int1 + int2 + int3 + int4; // sum of all ints
    printf("The sum of the four numbers: \t%d\n\n", sum);
}

// converts strings to float
void convertStrtoFloat(char *str1, char *str2, char *str3, char *str4) {
    char *strPtr; // string pointer
    float sum = 0; // initialize sum
    // use strtod to change string to float via string pointer
    float d1 = strtod(str1, &strPtr);
    float d2 = strtod(str2, &strPtr);
    float d3 = strtod(str3, &strPtr);
    float d4 = strtod(str4, &strPtr);
    sum = d1 + d2 + d3 + d4; // sum all floats
    printf("The sum of the four numbers: \t%.2f\n\n", sum);
}

// compare string values
void compareStr(char *s1, char *s2) {
    if(strcmp(s1, s2) == 0) { // if strings are equal
        puts("These strings are eaqual.\n\n");
    }
    else if(strcmp(s1, s2) < 0) { // if string 1 is less than string 2
        puts("The first string is less than the second string.\n\n");
    }
    else if(strcmp(s1, s2) > 0) { // if string 1 is greater than string 2
        puts("The first string is greater than the second string.\n\n");
    }
    
}

// compare string up to index
void comparePartialStr(char *s1, char *s2, size_t numChar) {
    if(strncmp(s1, s2, numChar) == 0) { // if theyre equal up to numChar
        puts("These strings are eaqual.\n\n");
    }
    else if(strncmp(s1, s2, numChar) < 0) { // if s1 is less than s2 up to numChar
        puts("The first string is less than the second string.\n\n");
    }
    else if(strncmp(s1, s2, numChar) > 0) { // if s1 is greater than s2 up to numChar
        puts("The first string is greater than the second string.\n\n");
    }
}

// randomizes sentences
void randomize(void) {
    char sentence[100] = {0}; // create a char array for sentences
    srand((unsigned int) (time(NULL))); // randomize rand
    // define what parts of the sentences are
    char *article[] = {
        "the",
        "a",
        "one",
        "some",
        "any"
    };
    char *noun[] = {
        "boy",
        "girl",
        "dog",
        "town",
        "car"
    };
    char *verb[] = {
        "drove",
        "jumped",
        "ran",
        "walked",
        "skipped"
    };
    char *preposition[] = {
        "to",
        "from",
        "over",
        "under",
        "on"
    };
    printf("%s\n", "Here is a story:");
    for(int count = 0; count < 20; ++count) { // do 20 times
        for(int i = 0; i < 6; ++i) { // for 6 times
            int randNum = rand() % 5; // random in between 0 and 6
            char *space = " "; // space
            if(i == 0) { // 1st word
                strcat(sentence, article[randNum]); // add random article
                strcat(sentence, space); // add space
            }
            else if(i == 1) { // 2nd word
                strcat(sentence, noun[randNum]); // add random noun
                strcat(sentence, space); // add space
            }
            else if(i == 2) { // 3rd word
                strcat(sentence, verb[randNum]); // add random verb
                strcat(sentence, space); // add space
            }
            else if(i == 3) { // 4th word
                strcat(sentence, preposition[randNum]); // add random preposition
                strcat(sentence, space); // add space
            }
            else if(i == 4) {
                strcat(sentence, article[randNum]); // add random article
                strcat(sentence, space); // add space
            }
            else if(i == 5) {
                strcat(sentence, noun[randNum]); // add random noun
            }
        }
        sentence[0] = toupper(sentence[0]); // change first char of sentence to uppercase
        printf("%s. ", sentence); // print sentence ending in period
        memset(sentence, 0, 100); //clears what is in sentence
    }
    printf("\n\n\n");
}

// tokenizes phone number input
void tokenizeTelNum(char* phoneNum) {
    char aCode[4] = {0}; // initializes char array for area code
    char aNum[8] = {0}; // initializes char array for phone number
    char *numPtr; // creates a pointer char
    char *remainder;
    
    numPtr = strtok(phoneNum, " ( ) "); // tokenizes the area code
    
    printf("Phone Number: \t");
    strncpy(aCode, numPtr, sizeof(aCode) - 1); // puts token in aCode
    int area = (int) strtol(aCode, &remainder, 0); // makes area an int of aCode
    printf("%d", area); // prints area code
    
    numPtr = strtok(NULL, " - "); // tokenizes first set of digits after area codde
    strcat(aNum, numPtr); // adds token to aNum
    numPtr = strtok(NULL, " "); // tokenizes last digits of phone number
    strcat(aNum, numPtr); // adds to aNum
    long phone = strtol(aNum, &remainder, 0); // makes phone the long of aNum
    printf("%ld\n\n\n", phone); // prints rest of phone number
    
}

// reverses the string
void reverse(char *s) {
    int count = 1; // initialize count
    for(int x = 0; x < strlen(s); ++x) { // for every character in string
        if(s[x] == ' ') { // if there is a space
            ++count; // add to count
        }
    }
    char* arr[count]; // makes array of size count, which is word count
    char* tokenPtr = strtok(s, " "); // tokenizes the first word
    int i = 0; // initialize i to 0, a starting point
    while(tokenPtr != NULL) { // while token isn't null
        arr[i] = tokenPtr; // the ith element of array is the token
        tokenPtr = strtok(NULL, " "); // tokenizes the next word
        ++i; // increase i
    }
    puts("The tokens in reverse:");
    for(int i = count - 1; i >= 0; --i) { // for every element in the array going backwards
        printf("%s ", arr[i]); // print array element
    }
    printf("\n\n");
}

// counts how many times a substring is in a string
void countSubstr(char *s1, char *s2) {
    char *ss = s1; // pointer to the string
    int count = 0; // initialize count
    while((ss = strstr(ss, s2))) { // while s2 is found in ss
        ss += strlen(s2); // move pointer up by length of s2
        ++count; // add count
    }
    printf("The substring \"%s\" appears %d times in the string.\n\n\n", s2, count);
}

// counts how many times a letter appears in string
void countChar(char *s, char c) {
    char* temp = s; // makes temp pointer to s
    int count = 0; // initialize count at 0
    while(temp != NULL) { // while temp is not null
        temp = strchr(temp, c); // the temp is shortened to the next instance of c within s
        if(temp) { // if temp exists, aka if c is in s
            ++count; // add count
            ++temp; // move temp up one character
        }
    }
    printf("The character \"%c\" appears %d times in the string.\n", c, count);
}

// counts how many times each letter appears in s
void countAlpha(char *s) {
    for(size_t j = 0; j < strlen(s); ++j) { // for every char in s
        s[j] = tolower(s[j]); // change to lowercase
    }
    for(char ch = 'a'; ch <= 'z'; ++ch) { // from a to z
        countChar(s, ch); // runs countChar to see how many occurances of each letter is in s
    }
    printf("\n\n");
}

// counts how many words are in s
void countWords(char *s) {
    char* tokenPtr = strtok(s, " "); // tokenizes word up until space
    int i = 0; // initialize i
    while(tokenPtr != NULL) { // if token exists
        tokenPtr = strtok(NULL, " "); // tokenize up to next space
        ++i; // add count
    }
    char* tokenPtr2 = strtok(s, "\n"); // tokenize s again but this time up until new line
    i = i-1; // subtract 1 from count bc the enter value is also a count
    while(tokenPtr2 != NULL) { // while token exists
        tokenPtr2 = strtok(NULL, "\n"); // tokenizes until next line
        ++i; // add count
    }
    printf("Number of words in this string:\t%d\n\n\n", i);
}

// checks to see if strings begin with B or b
void startsWithB(const char* arr[10][100]) {
    puts("\nStrings that begin with \"b\" or \"B\":");
    int num = 0; // initialize num
    for(int i = 0; i < 10; ++i) { // for 10 times
        if(strncmp(arr[i], "B", 1) == 0 || strncmp(arr[i], "b", 1) == 0) { // if the string begins with b or B
            printf("%s\n", arr[i]); // print out string
            ++num; // add num
        }
    }
    if(num == 0) { // if num is 0
        printf("%s", "NONE AVAILABLE"); // there is none
    }
    printf("\n\n\n");
}

// if string ends with ed
void endsWithed(char* arr[10][100]) {
    puts("\nStrings that end in \"ed\":");
    int num = 0; // initialize num
    for(int i = 0; i < 10; ++i) { // for 10 times
        int end = sizeof(arr[i]); // the int end is the size of the char array
        char x[end]; // creates a char array s of that size
        strcpy(x, arr[i]); // add the char array to x
        if(memcmp(x + strlen(x) - 2, "ed", 2) == 0) { // if the last 2 letters are ed
            printf("%s\n", x); // print out the strings ending in ed
            ++num; // add num
        }
    }
    if(num == 0) { // if num is 0
        printf("%s", "NONE AVAILABLE"); // there is none
    }
}
