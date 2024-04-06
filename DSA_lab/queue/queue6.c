#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int stack1[MAX_SIZE];
int top1 = -1;

int stack2[MAX_SIZE];
int top2 = -1;

void push1(int x) {
    if (top1 == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    stack1[++top1] = x;
}

void transferStack1ToStack2() {
    while (top1 >= 0) {
        stack2[++top2] = stack1[top1--];
    }
}

void push2(int x) {
    if (top2 == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    stack2[++top2] = x;
}

int pop2() {
    if (top2 == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return stack2[top2--];
}

void enqueue(int x) {
    if (top2 != -1) {
        printf("Cannot enqueue. Queue is not empty!\n");
        return;
    }
    push1(x);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    if (top2 == -1) {
        transferStack1ToStack2();
    }
    return pop2();
}

void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    
    while(1){

        int choice;
        printf("What operation do you want to perform ?\n1. Enqueue\n2. Dequeue\n3. Display\n");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                int x;
                printf("Enter the element :-\n");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

        }
    }
}
