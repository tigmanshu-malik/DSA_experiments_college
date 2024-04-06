#include<stdio.h>

int max = 10;
int top = -1;
int stack[10];

void push(){

    if(top == max - 1){

        printf("Stack overflow !!! \n");
        return;
    }

    top++;
    int ele;
    printf("Enter the element :- \n");
    scanf("%d", &ele);

    stack[top] = ele;

}

void peek(){

    if(top == -1){
       
        printf("Stack is empty\n");
        return;
    }

    printf("%d\n", stack[top]);
}

void pop(){

    if(top == -1){

        printf("Stack underflow !!!\n");
        return;
    }

    top--;
}

int main(){

    while(1){

        int choice;
        printf("Which operation do you want to perform ?\n1.Push\n2.Peek\n3.Pop\n");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                push();
                break;

            case 2:
                peek();
                break;

            case 3:
                pop();
                break;

            default:
                printf("Invalid Input\n");

        }

    }
}