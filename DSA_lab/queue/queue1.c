#include<stdio.h>

int queue[10];

int front = -1, rear = -1;

void insert(){

    if(rear == 11){
        printf("queue overflow !!!\n");
        return;
    }

    printf("Enter the desired element :- \n");
    scanf("%d", &queue[rear + 1]);

    rear++;

    if(front == -1)
        front++;
}

void delete(){

    if(rear != -1){

        for(int i = 1; i <= rear; i++)
            queue[i - 1] = queue[i];

        rear--;    
    }

    else{

        printf("Queue underflow !!!\n");
        return;
    }
}

void display(){

    for(int i = 0; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main(){

    while(1){

        int choice;
        printf("What task do you want to perform ?\n1. Insert\n2. Delete\n 3. Display\n");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;


        }

    }
}