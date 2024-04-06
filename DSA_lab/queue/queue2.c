#include<stdio.h>
#include<stdlib.h>

struct queue{

    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void insert(){

    struct queue *ptr, *temp;

    temp = (struct queue*)malloc(sizeof(struct queue));

    if(temp == NULL){

        printf("Could not allocate memory !!\n");
        exit(0);
    }

    printf("Enter desired element :-\n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(front == NULL && rear == NULL){

        front = temp;
        rear = temp;
    }

    else{

        ptr = front;

        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
        rear = temp;    
    }

}

void delete(){

    if(front == NULL){

        printf("Queue Underflow !!!\n");
        return;
    } 

    if(front != rear){

        struct queue *ptr = front;
        front = ptr->next;
        free(ptr);
    }

    else{

        free(front);
        front = NULL;
        rear = NULL;
    }
}

void display(){

    if(front == NULL){

        printf("Queue underflow !!!\n");
        return;
    }

    struct queue *ptr = front;

    while(ptr != rear){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("%d\n", ptr->data);   
}

int main(){

    while(1){

        int choice;
        printf("1. Insert\n2. Delete\n3. Display\n");
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