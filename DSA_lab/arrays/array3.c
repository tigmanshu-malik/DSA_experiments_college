#include<stdio.h>

int main(){

    char string[20];

    printf("Enter a uppercase string :-\n");
    fgets(string, 20, stdin);

    for(int i = 0; string[i] != '\0'; i++)
        string[i] += 32;

    for(int i = 0; string[i] != '\0'; i++)
        printf("%c", string[i]);    
}