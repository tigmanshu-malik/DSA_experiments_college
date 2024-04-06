#include<stdio.h>
#include<stdlib.h>

struct node{

    struct node *next;
    struct node *prev;
    int data;
};

struct node *start = NULL;

void insert(){

    struct node *ptr, *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("Could not allocate memory \n");
        exit(0);
    }

    printf("Enter an element :-");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = NULL;

    if(start == NULL)
        start = temp;

    else{

        ptr = start;

        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
        temp->prev = ptr;    
    }    
}

void display(){

    struct node *ptr = start;

    while(ptr->next != NULL){

        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("%d\n", ptr->data);
}

void display_reverse(){

    struct node *ptr = start;

    while(ptr->next != NULL)
        ptr = ptr->next;

    while(ptr->prev != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }

    printf("%d\n", ptr->data);
}

void insert_start(){

    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("Could not allocate memory \n");
        exit(0);
    }

    printf("Enter an element :-\n");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    
    temp->next = start;
    start->prev = temp;
    start = temp;

}

void insert_end(){

    struct node *ptr, *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){
        printf("Could not allocate memory");
        exit(0);
    }

    printf("Enter an element :-\n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    ptr = start;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;    
}

int count_ele(){

    struct node *ptr;

    ptr = start;

    int count = 1;

    while(ptr->next != NULL){
        count++;
        ptr= ptr->next;

    }
    return count;    
}

void insert_desired(){

    struct node *temp, *ptr;

    int count = 0, index;

    printf("Enter index :-");
    scanf("%d", &index);

    if(index == 1){
        insert_start();
        return;
    }

    else if(index == count_ele() + 1){
        insert_end();
        return;
    }

    else{

        temp = (struct node*)malloc(sizeof(struct node));

        printf("Enter desired element :-\n");
        scanf("%d", &temp->data);

        count = 1;

        ptr = start;

        while(count != index){
             ptr = ptr->next;
             count++;
        }

        ptr->prev->next = temp;
        temp->prev = ptr->prev;
        ptr->prev = temp;
        temp->next = ptr;    
    }

}

void delete_start(){

    struct node *ptr;

    ptr = start;
    start = ptr->next;
    start->prev = NULL;
    free(ptr);
}

void delete_end(){

    struct node *ptr;

    ptr = start;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->prev->next = NULL;
    free(ptr);    
}

void delete_desired(){

    struct node *ptr;

    int index, count = 1;

    printf("Enter index\n");
    scanf("%d", &index);

    if(index == 1){
        delete_start();
        return;
    }

    else if(index == count_ele()){
        delete_end();
        return;
    }

    else{

        ptr = start;

        while(index != count){

            count ++;
            ptr = ptr->next;
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }

    
}

int main(){

    int n, choice;
    printf("Enter number of elements :-");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        insert();

    display();    

    while(1){

        printf("What operation do you want to perform ? \n1. Display in reverse\n2. Insert at start \n3.Insert at end\n4. Insert at desired\n5. Delete at start\n 6. Delete at end\n7.Delete at desired\n");
        scanf("%d", &choice);

        switch(choice){

        case 1:
            display_reverse();
            break;

        case 2: 
            insert_start();
            display();
            break;

        case 3: 
            insert_end();
            display();
            break;      

        case 4:
            insert_desired();
            display();
            break;    

        case 5:
            delete_start();
            display();
            break;

        case 6:
            delete_end();
            display();
            break;

        case 7:
            delete_desired();
            display();
            break;    
    }
    }

}