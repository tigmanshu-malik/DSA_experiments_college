#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
};

struct node *start = NULL;

void create(){

    struct node *temp, *ptr;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("Cannot allocate memory \n");
        exit(0);
    }

    printf("Please enter a number : \n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(start == NULL)
        start = temp;

    else{
        
        ptr = start;

        while(ptr->next != NULL){

            ptr = ptr->next;
        }

        ptr->next = temp;

    }    
}

void display(){

    struct node *ptr;

    ptr = start;

    while(ptr->next != NULL){

        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("%d ", ptr->data);    
}

void insert_start(){

    struct node *ptr, *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("Could not allocate memory \n");
        exit(0);
    }

    printf("Enter desired number :- \n");
    scanf("%d", &temp->data);
    
    temp->next = start;

    start = temp;

}

void insert_end(){

    struct node *ptr, *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("Could not allocate memory ");
        exit(0);
    }

    printf("Enter desired number :- \n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    ptr = start;

    while(ptr->next != NULL){

        ptr = ptr->next;
    }

    ptr->next = temp;

}

int count_ele(){

    struct node *ptr;
    int count = 1;

    ptr = start;

    while(ptr->next != NULL){

        count++;
        ptr = ptr->next;
    }

    return count;

    
}

void insert_desired(){

    struct node *ptr, *temp;
    int pos, count = 1;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("Could not allocate memory");
        exit(0);
    }


    printf("Enter desired postion :- \n");
    scanf("%d", &pos);

    if(pos == 1)
        insert_start();

    else if(pos == count_ele())
        insert_end();

    else{

        printf("Enter the desired number :- \n");
        scanf("%d", &temp->data);

        ptr = start;

        while(count < pos - 1){

            ptr = ptr->next;
            count++;
        }

        temp->next = ptr->next;

        ptr->next = temp;

    }        
}

void del_begin(){

    struct node* ptr;

    ptr = start;

    start = start->next;

    free(ptr);
}

void del_end(){

    struct node *ptr;

    ptr = start;

    while(ptr->next->next != NULL)
        ptr = ptr->next;

    free(ptr->next);
    ptr->next = NULL;    
}

void del_desired(){

    struct node *ptr;
    int pos, count = 1;

    ptr = start;

    printf("Enter desired position : \n");
    scanf("%d", &pos);

    if(pos == 1)
        del_begin();

    else if(pos == count_ele())
        del_end();

    else{

        while(count < pos - 1){

            ptr = ptr->next;
            count++;
        }

        struct node *temp = ptr->next->next;

        free(ptr->next);

        ptr->next = temp;
    }        


}

void search(){

    struct node *ptr, *temp;

    int ele, count = 1;

    printf("what element do you want to search : \n");
    scanf("%d", &ele);

    ptr = start;

    while(ptr->next != NULL){

        if(ptr->data == ele){

        printf("The desired element is at %d position", count);
        return;

        }

        else{

            count++;
            ptr= ptr->next;
            

        }
    }

    if(ptr->data == ele){

        printf("The desired element is at %d position", count);
        return;

        } 
}

void reverse(){

    struct node *pre, *forward, *current;

    current = start;
    pre = NULL;
    forward = start;

    while(current->next != NULL){

        forward = current->next;
        current->next = pre;
        pre = current;
        current = forward;
    }
    current->next = pre;

    start = current;
 
}

void  detect_loop(){

    struct node *ptr, *slow, *fast;

    ptr = start;
    slow = start;
    fast = start;

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = start->next;

    while(slow->next != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            printf("Loop detected\n");
            return;
        }
            
    }

    printf("No loop found !\n");

}

int main(){

    int n, choice;

    printf("Enter number of elements :- \n");
    scanf("%d", &n);

    for(int i = 0; i < n ; i++)
        create();

    display();

    while(1){

        printf("\nWhat task do you want to perform ? \n 1. Insert at beginning \n 2. Insert at end\n 3. Insert at desired position \n 4. Delete beginning \n 5. Delete end \n 6. Delete desired position \n7. Terminate program\n 8. Search\n 9. Reverse \n10.Detect loop\n");

        scanf("%d", &choice);

        switch(choice){

            case 1: 
                insert_start();
                display();
                break;

            case 2: 
                insert_end();
                display();
                break;

            case 3:
                insert_desired();
                display();
                break; 

            case 4:
                del_begin();
                display();
                break;

            case 5:
                del_end();
                display();
                break;

            case 6:
                del_desired();
                display();
                break;

            case 7: exit(0);

            case 8:
                search();
                display();
                break;

            case 9:
                reverse();
                }
                
                }

    }
              