/*Given an image represented by an NxN matrix, where each pixel in the image is
4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?
*/

#include <stdio.h>
#include "stdlib.h"

#define N 4

void print_matrix(int a[][N]) {
  int i, j;
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
}

void rotate_matrix(int arr[][N]) {
  int i, j;
  int temp = 0;
  printf("ROTATE\n");
  for(i=0; i<N; i++) {
    for(j=i; j<N; j++) {
      temp = arr[i][j];
      arr[i][j] = arr[j][i];
      arr[j][i] = temp;
    }
  }
}

int main() {
int arr[][N] =
{
{1,2,3,4,},
{5,6,7,8,},
{9,10,11,12,},
{13,14,15,16,},
};
  printf("sizeof %d %d\n", sizeof(arr), sizeof(*arr));
print_matrix(arr);
rotate_matrix(arr);
print_matrix(arr);
return 1;
}