//
//  main.c
//  zheng_david_lab11
//  Southie Accent
//  Created by David Zheng on 11/27/18.
//  Copyright © 2018 David Zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void dialogue(char *string);
void has_r(char *token);
char *ends_with_r(char *token, size_t end);
char *ends_with_a(char *token, size_t end);

FILE *to;

int main(int argc, const char * argv[]) {
    char *line = NULL;
    char *string, *end_string;
    FILE *from;
    size_t len = 0;
    ssize_t read;
    
    from = fopen("sherlock.txt", "r");
    if(from == NULL) {
        puts("No such file.");
        exit(0);
    }
    to = fopen("southie-sherlock.txt", "w");
    while((read = getline(&line, &len, from)) != EOF) {
        string = strtok_r(line, "\"", &end_string);
        int num = 1;
        while(string != NULL) {
            if(num % 2 != 0) {
                fprintf(to, "%s", string);
            }
            if(num % 2 == 0) {
                dialogue(string);
            }
            string = strtok_r(NULL, "\"", &end_string);
            num++;
        }
    }
}

void dialogue(char *string) {
    char *token = string;
    char *end_token;
    strtok_r(token, " ", &end_token);
    size_t size;
    fprintf(to, "\"");
    
    while(token != NULL) {
        size = strlen(token);
        size_t end = size - 1;
        while(!isalpha(token[end])) {
            end--;
        }
//        end++;
        int r_count = 0;
        for(int i = 1; i < size; i++) {
            if(token[i] == 'r') {
                r_count++;
            }
            
        }
        if(r_count > 0) {
            if((token[end] == 'r') && ((token[end - 1] == 'i') || (token[end - 1] == 'e' && token[end - 2] == 'e') || (token[end - 1] == 'o' && token[end - 2] == 'o'))) {
                has_r(ends_with_r(token, end));
            }
            else if(token[end] == 'a') {
                has_r(ends_with_a(token, end));
            }
            else {
                has_r(token);
            }
        }
        else if(token[end] == 'a' && size > 2 && r_count == 0) {
            fprintf(to, "%s", ends_with_a(token, end));
        }
        else {
            fprintf(to, "%s", token);
        }
        
        token = strtok_r(NULL, " ", &end_token);
        if(token) {
            fprintf(to, " ");
        }
    }
    fprintf(to, "\"");
}

char *ends_with_a(char *token, size_t end) {
//    size_t end = size - 1;
//    while(!isalpha(token[end])) {
//        end--;
//    }
    size_t size = strlen(token);
    size_t newsize = size + 1;
    char *temp = malloc(sizeof(char) * newsize);
    for(size_t i = 0; i < size; i++) {
        temp[i] = token[i];
    }
    temp[end] = token[end];
    temp[end + 1] = 'r';
    size_t x = end + 1;
    for(size_t j = end + 2; j < newsize; j++) {
        temp[j] = token[x++];
    }
    temp[newsize] = '\0';
    return temp;
}

char *ends_with_r(char *token, size_t end) {
    size_t size = strlen(token);
    size_t newsize = size + 2;
    char *temp = malloc(sizeof(char) * newsize);
    for(size_t i = 0; i < end; i++) {
        temp[i] = token[i];
    }
    if(token[end - 1] == 'e' || token[end - 1] == 'i') {
        temp[end + 2] = 'h';
        temp[end + 1] = 'a';
        temp[end] = 'y';
    }
    else {
        temp[end + 2] = 'h';
        temp[end + 1] = 'a';
        temp[end] = 'w';
    }
    size_t x = end + 1;
    for(size_t j = end + 3; j < newsize; j++) {
        temp[j] = token[x++];
    }
    temp[newsize] = '\0';
    return temp;
}

void has_r(char *token) {
    size_t size = strlen(token);
    size_t end = size - 1;
    while(!isalpha(token[end])) {
        end--;
    }
    char *temp = malloc(sizeof(char) * size);
    temp[0] = token[0];
    for(int i = 1; i < end; i++) {
        if(temp[i] == 'r') {
            if(temp[i - 1] == 'a' || temp[i - 1] == 'e' || temp[i - 1] == 'i' || temp[i - 1] == 'o' || temp[i - 1] == 'u') {
                temp[i] = 'h';
            }
            else {
                temp[i] = token[i];
            }
        }
        else {
            temp[i] = token[i];
        }
    }
    size_t x = end;
    for(size_t j = end; j < size; j++) {
        temp[j] = token[x++];
    }
    fprintf(to, "%s", temp);
}
