#include<stdio.h>
#include<stdlib.h>

int main(){

    int r1, c1, r2, c2;

    printf("Enter number of rows and columns in first matrix :- \n");
    scanf("%d %d", &r1, &c1); 
    printf("Enter number of rows and columns in second matrix :- \n");
    scanf("%d %d", &r2, &c2); 

    if(c1 != r2){

        printf("Number of columns in first matrix should be equal to rows in second\n");
        exit(0);
    }

    int mat1[r1][c1], mat2[r2][c2];

    printf("Enter elements of first matrix :-\n");

    for(int i = 0; i < r1; i++){

        for(int j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);
    }

    printf("Enter elements of second matrix :-\n");

    for(int i = 0; i < r2; i++){

        for(int j = 0; j < c2; j++)
            scanf("%d", &mat2[i][j]);
    }

    int mat3[r1][c2];

    printf("\nThe multiplication is :- \n");

    for (int i = 0; i < r1; i++) {

        for (int j = 0; j < c2; j++) {

            mat3[i][j] = 0;

            for (int k = 0; k < r2; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }

            printf("%d ", mat3[i][j]);
        }

        printf("\n");
    }
}