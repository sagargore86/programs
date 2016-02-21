/*Given two strings, write a method to decide if one is a permutation of the other.*/

#include <stdio.h>

int check_permutation(char* str1, char *str2)  {
  unsigned int char_map1[26], char_map2[26];
  int i = 0, rc = 1;
  if (strlen(str1) != strlen(str2))
    return 0;

    memset(char_map1, 0, 26*4);
    memset(char_map2, 0, 26*4);

    i = 0;

  while(i < strlen(str1)) {
    if (!((str1[i] >= 'A' && str1[i] <= 'Z') ||
        (str1[i] >= 'a' && str1[i] <= 'z'))){
        i++; 
       continue;
    }
    if (str1[i] >= 'A' && str1[i] <= 'Z')
        str1[i] += 'a' -'A';
    char_map1[str1[i]-'a']++;
    printf("%d: str1[%d]=%c,  char_map1 %d\n", char_map1[str1[i]-'a'], i, str1[i], str1[i]-'a');
    i++;
    }
  i =0;
  while(i < strlen(str2)) {
    if (!((str2[i] >= 'A' && str2[i] <= 'Z') ||
        (str2[i] >= 'a' && str2[i] <= 'z'))) {
        i++;
        continue;
    }
    if (str2[i] >= 'A' && str2[i] <= 'Z')
        str2[i] += 'a' -'A';
    char_map2[str2[i]-'a']++;
    printf("%d: str2[%d]=%c,  char_map2 %d\n", char_map2[str2[i]-'a'], i, str2[i], str2[i]-'a');
    i++;
    }
    i = 0;
    while (i<26) {
        printf("%c: char_maps %x : %x\n", 'a' + i, char_map1[i], char_map2[i]);
        if (char_map1[i] == char_map2[i]) {
            i++;
            continue;
        } else {
            rc = 0;    
            break;
        }
    }
    return rc;
}

int main() {
char in_str1[] = "Hello woRld";
char in_str2[] = "heLlo Dlrow";

printf("input %s vs %s\n", in_str1, in_str2);
printf("result %s\n", check_permutation(in_str1, in_str2)?"Yes permutative":"No different strings");
return 1;
}