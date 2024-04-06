#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;

void create(struct node **start) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) {
        printf("Could not allocate memory\n");
        exit(0);
    }
    printf("Enter an element: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if(*start == NULL)
        *start = temp;
    else {
        struct node *ptr = *start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }    
}

void merge(struct node *ptr1, struct node *ptr2) {
    while(ptr1->next != NULL && ptr2 != NULL) {
        if(ptr1->next->data < ptr2->data)
            ptr1 = ptr1->next;
        else {
            struct node *temp = ptr2->next;
            ptr2->next = ptr1->next;
            ptr1->next = ptr2;
            ptr2 = temp;
        }
    }
    if(ptr2 != NULL)
        ptr1->next = ptr2;
}

void display(struct node **start) {
    struct node *ptr = *start;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements in first linked list: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        create(&start1);
    printf("Enter the number of elements in second linked list: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        create(&start2);
    printf("Merging two linked lists...\n");
    merge(start1, start2); // Pass heads of both lists as arguments
    printf("Merged linked list: ");
    display(&start1);
    return 0;
}
