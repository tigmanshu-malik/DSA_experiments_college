#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;

void create() {
    struct node *ptr, *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL) {
        printf("Could not allocate memory\n");
        exit(0);
    }

    printf("Enter a value: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if(start == NULL) {
        start = temp;
        temp->next = start;
        temp->prev = start;
    } else {
        ptr = start;

        while(ptr->next != start) {
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->prev = ptr;
        temp->next = start;
        start->prev = temp;
    }
}

void display() {
    struct node *ptr;
    ptr = start;

    if(ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != start);

    printf("\n");
}

void insert_start() {
    struct node *temp, *last;
    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL) {
        printf("Could not allocate memory\n");
        exit(0);
    }

    printf("Enter a value: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    last = start->prev;

    temp->next = start;
    temp->prev = last;
    start->prev = temp;
    last->next = temp;
    start = temp;
}

void insert_end() {
    struct node *temp, *last;
    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL) {
        printf("Could not allocate memory\n");
        exit(0);
    }

    printf("Enter a value: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    last = start->prev;

    temp->next = start;
    temp->prev = last;
    start->prev = temp;
    last->next = temp;
}

void insert_desired() {
    struct node *temp, *ptr;
    int pos, i;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL) {
        printf("Could not allocate memory\n");
        exit(0);
    }

    printf("Enter position to insert: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    ptr = start;

    for(i = 1; i < pos - 1; i++) {
        ptr = ptr->next;
        if(ptr == start) {
            printf("Invalid position\n");
            return;
        }
    }

    temp->next = ptr->next;
    ptr->next->prev = temp;
    ptr->next = temp;
    temp->prev = ptr;
}

void delete_begin() {
    struct node *temp;

    if(start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start;

    start = start->next;
    start->prev = temp->prev;
    temp->prev->next = start;
    free(temp);
}

void delete_end() {
    struct node *temp;

    if(start == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = start->prev;

    temp->prev->next = start;
    start->prev = temp->prev;
    free(temp);
}

void delete_desired() {
    struct node *temp, *ptr;
    int pos, i;

    if(start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if(pos == 1) {
        delete_begin();
        return;
    }

    ptr = start;

    for(i = 1; i < pos - 1; i++) {
        ptr = ptr->next;
        if(ptr == start) {
            printf("Invalid position\n");
            return;
        }
    }

    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
}

void search() {
    struct node *ptr;
    int key, pos = 0;
    int flag = 0;

    if(start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    ptr = start;
    do {
        pos++;
        if(ptr->data == key) {
            printf("Value %d found at position %d\n", key, pos);
            flag = 1;
        }
        ptr = ptr->next;
    } while(ptr != start);

    if(flag == 0)
        printf("Value %d not found in the list\n", key);
}

int main() {
    int choice;
    do {
        printf("\n1. Create a node\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at desired position\n");
        printf("5. Delete from beginning\n");
        printf("6. Delete from end\n");
        printf("7. Delete from desired position\n");
        printf("8. Search\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create();
                break;
            case 2:
                insert_start();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_desired();
                break;
            case 5:
                delete_begin();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_desired();
                break;
            case 8:
                search();
                break;
            case 9:
                display();
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 10);

    return 0;
}

