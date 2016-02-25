/*
Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string.
*/

#include <stdio.h>
#include <stdlib.h>

char * compress_string(char *str) {
    char temp, buf[10];
	char *original = str;
        char *result = (char *) malloc(strlen(original)+1);
	int count = 0, index = 0;

	result[index++] = temp = *str;
	result[index] = '1';
	while(*str != '\0') {
		printf("str %c temp %c index %d\n", *str, temp, index);
            	   if (index >= (strlen(original)-1))
    			return NULL;
		if (*str == temp) {
                   count++;
                   snprintf (buf, sizeof(buf), "%d",count);
                   printf("%c count %d\n", *buf, count);
		  result[index] = *buf;
		} else {
                   printf("index %d *str %c\n", index, *str);
                    index++;
            	   if (index >= (strlen(original)-1))
    			return NULL;
		   result[index] = *str;
                   index++;
            	   if (index >= (strlen(original)-1))
    			return original;

		   result[index] = '1';
		   count = 1;
		}
//                if (*str == 'd')
//                    break;
		temp = *str++;
	}
        index++;
        if (index > (strlen(original)))
    	    return NULL;

	result[index] = '\0';
    printf("result %s index %d strlen %d\n", result, index, strlen(original ));
    return result;
}

int main() {
char str[] = "abcd";
char *result=compress_string(str);
printf("input %s, output %s\n", str, result);
if (result)
    free(result);
return 0;
}