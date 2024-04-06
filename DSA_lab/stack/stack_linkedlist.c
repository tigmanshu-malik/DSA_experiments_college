#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *top = NULL;

void push(){

    
    struct node *temp, *ptr;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter an element :- \n");
    scanf("%d", &temp->data);
    temp->next == NULL;

    if(start == NULL){
        start = temp;
    }

    else{

        ptr = start;

        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
        top = temp;    
    }
}

void peek(){

    struct node *ptr = start;

    if(top == NULL){

        printf("Stack underflow !!!\n");
        return;
    }

    while(ptr->next != top)
        ptr = ptr->next;

    printf("%d\n", ptr->next->data);    
}

void pop(){

    if(top == NULL){

        printf("Stack Underflow !!!\n");
        return;
    }

    if(start == top){

        free(top);
        start = NULL;
        top = NULL;
    }

    else{
    
    struct node *ptr = start;

    while(ptr->next != top)
        ptr = ptr->next;
    
    free(ptr->next);
    top = ptr;
    }

}

int main(){

    top = start;

    while(1){

        int choice;
        printf("\nWhat operation do you want to perform ?\n1.Push\n2.Peek\n3.Pop\n");
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
                printf("Invalid input\n");
                break;            
        }
    }
}