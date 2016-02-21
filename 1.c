/*Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?*/
#include <stdio.h>

int check_unique(char*str) {
int alpha_check =0;
int i=0;
printf("input len %d\n", strlen(str));
for (i=0; i < strlen(str); i++) {
    if(alpha_check & (1 << str[i]-'a')) {
      return 0;
    }
    alpha_check |= (1 << str[i]-'a');
}
return 1;
}

int main() {
char in_str[] = "Hello World";
printf("input %s\n", in_str);
printf("result %s\n", check_unique(in_str)?"Unique":"Repeat chars");
return 1;
}