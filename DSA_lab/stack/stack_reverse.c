#include<stdio.h>

char stack[20];
int top = -1, max = 20;

void push(char ele){

    top++;
    stack[top] = ele;

}

void pop(){

    printf("%c", stack[top]);
    top--;
}

int count_ele(char string[20]){

    int count = 0;

    for(int i = 0; string[i] != '\0'; i++)
        count++;

    return count;    
}

int main(){

    char string[20];

    printf("Enter a string of max 20 characters\n");
    fgets(string, 20, stdin);

    int n = count_ele(string);

    for(int i = 0; i < n; i++)
        push(string[i]);

    printf("Reversed string :-\n");

    for(int i = 0; i < n; i++)
        pop();    

    printf("\n");    
}