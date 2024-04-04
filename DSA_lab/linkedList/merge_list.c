#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;

void create(struct node **start){

    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("Could not allocate memory\n");
        exit(0);
    }

    printf("Enter an element :-\n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(*start == NULL)
        *start = temp;

    else{

        struct node *ptr = *start;

        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
    }    


}

void merge(struct node *ptr1, struct node *ptr2){

        while(ptr1->next->data < ptr2->data && ptr1->next != NULL)
            ptr1 = ptr1->next;

            
    }


void display(struct node **start){

    struct node *ptr = *start;

    while(ptr->next != NULL){

        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("%d ", ptr->data);

}

int main(){

    int n;
    printf("Enter the number of elements in first linked list\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        create(&start1);

    printf("Enter the number of elements in second linked list\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        create(&start1);

    printf("Merging two linked list :-\n");

    merge();

    display(&start1);
}