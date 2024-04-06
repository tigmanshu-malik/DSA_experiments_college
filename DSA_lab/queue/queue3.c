#include<stdio.h>
#include<stdlib.h>

char queue[20];

int front = -1, rear = -1;

void insert(char c){

   queue[rear + 1] = c;

   rear++;

    if(front == -1)
        front++;
}

void isPallindrome(){

    while(front <= rear){

        if(queue[front] != queue[rear - 1]){

            printf("Not a pallindrome !!\n");
            return;
        }

        front++;
        rear--;
    }  

    printf("It is a pallindrome !!\n");
}

int main(){

    char expression[20];

    printf("Enter a string :- \n");
    fgets(expression, 20, stdin);

    for(int i = 0; expression[i] != '\0'; i++)
        insert(expression[i]);
        
    isPallindrome();      
}