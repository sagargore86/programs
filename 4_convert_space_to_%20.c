/*
Write a method to replace all spaces in a string with'%20'. You may assume that
the string has sufficient space at the end of the string to hold the additional
characters, and that you are given the "true" length of the string.
*/

#include <stdio.h>

char * do_logic(char *str) {
    char *new = (char *)malloc(strlen(str)+6);
    char *result = new;
    while(*str) {
        printf("%c \t", *str);
        if (*str== ' ') {
            *new++ = '%';
            *new++='2';
            *new='0';
        } else {
            *new = *str;
        }
        printf("%c \n", *new);
        str++;
        new++;
    }
    *new ='\0';
    printf("new %s\n", result);
    return result;
}

int main() {
char *str = "Mr John Smith";
char *result=do_logic(str);
printf("input %s, output %s\n", str, result);
free(result);
return 0;
}