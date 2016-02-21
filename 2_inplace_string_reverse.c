/*Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated
string.*/
#include <stdio.h>

void reverse(char* str)  {
    char* end = str;
    char temp;

    while(*end){
        end++;
    }
    end--;

    while(str < end) {
        temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
}

int main() {
char in_str[] = "Hello World";
printf("input %s\n", in_str);
reverse(in_str);
printf("result %s\n", in_str);
return 1;
}