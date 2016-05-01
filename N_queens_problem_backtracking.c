#include <stdio.h>
#include <stdlib.h>

#define N 8

int Place(int row, int col, int *pos) {
    int queen = 0;

    for (queen = 0; queen < row; queen++) {
  //      printf("queen %d, pos[%d] = %d, col = %d, abs_row %d, abs_col %d \n" ,
    //        queen, queen,
      //      pos[queen], col, abs(pos[queen] - col), abs(queen - row));
        if (pos[queen] == col || (abs(pos[queen] - col) - abs(queen - row) == 0)) {
        //    printf("under_attack %d %d \n", row, col);
            return 1;
        }
    }
    return 0;
}

int solve_position(int row, int *Position) {
    int col = 0, ret = 0;
    int under_attack = 0;
    if (row == N) {
        return 0;
    }
//        printf("Pick position for Queen in row = %d\n", row);
        for (col = 0; col < N; col++) {
//            printf("col = %d\n", col);
            ret = Place(row, col, Position);
//            printf("(%d, %d) is under_attack %s \n", row, col, (ret==1)?"Yes":"No" );
            if (ret == 0) {
                Position[row] = col;
  //              printf("\t\t\t\t (%d, %d) Final\n", row, col);
                ret = solve_position(row+1, Position);                
                if (ret == 0) {
                    return 0;
                }
            } else if (col == N-1) {
                under_attack = 1;
                break;
            }
        }
//        if (under_attack == 1)     
//            printf("\t No position found for row %d Rollback \n", row, col);
        return 1;
}

int main() {
    int queen = 0;
    int Position[N] = {0};

    solve_position(0, Position);
    printf("Queen positions\n");
    for (queen = 0; queen < N; queen++)
        printf("(%d, %d) ", queen, Position[queen]);
    return 1;
}