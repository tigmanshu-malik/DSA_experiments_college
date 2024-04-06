#include<stdio.h>

int main(){

    int rows, columns;

    printf("Enter number of rows :-\n");
    scanf("%d", &rows);

    printf("Enter number of columns :-\n");
    scanf("%d", &columns);

    int arr[rows][columns], sum = 0;

    for(int i = 0; i < rows; i++){

        for(int j = 0; j < columns; j++)
            scanf("%d", &arr[i][j]);
    }

    for(int i = 0; i < rows; i++){

        for(int j = 0; j < columns; j++)
            sum += arr[i][j];
    }

    printf("Total sum = %d\n", sum);
}