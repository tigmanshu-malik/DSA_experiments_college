#include<stdio.h>

int max = 30;
int top = -1;
int stack[30];

void push(char a){

    if(top == max - 1){

        printf("Stack overflow !!! \n");
        return;
    }

    top++;
    stack[top] = a;

}

void pop(){

    if(top == -1){

        printf("Stack underflow !!!\n");
        return;
    }

    if(stack[top] != '(')
        printf("%c", stack[top]);
    top--;
}

int count_ele(char string[30]){

    int count = 0;

    for(int i = 0; string[i] != '\0'; i++)
        count++;

    return count;    
}

int main(){

    char expression[30];
    printf("Enter a postfix expression :- \n");
    fgets(expression, 30, stdin);

    
}