/*Assume you have a method isSubstring which checks if one word is a
substring of another. Given two strings, si and s2, write code to check if s2 is
a rotation of si using only one call to isSubstring (e.g.,"waterbottle"is a rotation
of "erbottlewat").
*/

#include <stdio.h>
#include "stdlib.h"

int isSubString(char *str1, char *str2) {
  char *temp = str2;
  int i =0, j =0, len;

  if (strlen(str1) != strlen(str2))
    return 0;
  len = strlen(temp);

  while(*str2 != NULL && *str1 !=*str2) {
    str2++; j++;
  }
  printf("j %d\n", j);
  while (i < len) {
    if (str1[i++] != str2[j++ % len]) {
        printf("str1[%d]= %c, str2[%d]= %c\n", i, str1[i], j%len, str2[j%len]);
        return 0;
    }
    printf("str1[%d]= %s, str2[%d]= %s\n", i, str1, j%len, str2);
  }
  return 1;
}

int main() {
char arr1[]="waterbottle";
char arr2[]="erbottlewat";

printf("%s : %s is subString %d", arr1, arr2, isSubString(arr1, arr2));

return 1;
}