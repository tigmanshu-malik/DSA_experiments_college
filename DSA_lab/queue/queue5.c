#include<stdio.h>

#define MAX_SIZE 5

int queue1[MAX_SIZE], queue2[MAX_SIZE];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

void enqueue1(int x) {
    if (rear1 == MAX_SIZE - 1) {
        printf("Stack overflow !!!\n");
        return;
    }
    if (front1 == -1) {
        front1 = 0;
    }
    queue1[++rear1] = x;
}

void enqueue2(int x) {
    if (rear2 == MAX_SIZE - 1) {
        printf("Stack overflow !!!\n");
        return;
    }
    if (front2 == -1) {
        front2 = 0;
    }
    queue2[++rear2] = x;
}

void dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Stack underflow !!!\n");
        return;
    }
    front1++;
    if (front1 > rear1) {
        front1 = rear1 = -1;
    }
}

void dequeue2() {
    if (front2 == -1 || front2 > rear2) {
        printf("Stack underflow !!!\n");
        return;
    }
    front2++;
    if (front2 > rear2) {
        front2 = rear2 = -1; 
    }
}

void push() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);

    enqueue1(x);
}

void pop() {
    if (front1 == -1 && rear1 == -1) {
        printf("Stack underflow\n");
        return;
    }

    while (front1 < rear1) {
        enqueue2(queue1[front1]);
        dequeue1();
    }

    printf("Popped: %d\n", queue1[rear1]);
    dequeue1(); 

    front1 = 0;
    rear1 = rear2 - front2;
    for (int i = 0; i <= rear1; i++) {
        queue1[i] = queue2[i + front2];
    }

    front2 = -1;
    rear2 = -1;
}


int main() {
    while (1) {
        int choice;
        printf("Enter your operation:\n1. Push\n2. Pop\n3. Display\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
