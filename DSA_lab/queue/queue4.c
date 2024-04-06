#include<stdio.h>

int queue[5], max = 5, front = -1, rear = -1;

void insert(){

    int ele;
    printf("Enter the element :-\n");
    scanf("%d", &ele);

    if(front == -1 && rear == -1){

        front++;
        rear++;
    }

    else if(front == 0 && rear == max - 1 || front == rear + 1){

        printf("Circular queue overflow \n");
        return;
    }

    else if(rear == max - 1)
        rear = 0;

    else
        rear++;

    queue[rear] = ele;    
}


void delete(){

    if(front == -1){

        printf("Circular queue underflow !!!\n");
        return;
    }

    else if(front == max - 1){

        front = 0;
        return;
    }
    
    else if(front == rear){

        front = -1;
        rear = -1;
        return;
    }

    front++;
}

void display(){

    if(front == -1){

        printf("Circular queue is empty\n");
        return;
    }

    int temp = front;

    while(temp != rear){
        printf("%d ", queue[temp]);
        temp++;
    }

    printf("%d \n", queue[temp]);


}

int main(){

    while(1){
        
        int choice;
        printf("What operation do you want \n1. Insert\n2. Delete\n3. Display\n");
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