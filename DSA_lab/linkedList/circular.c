#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
};

struct node *start = NULL;

void create(){

    struct node *ptr, *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("Could not allocate memory");
        exit(0);
    }

    printf("Enter a value :- \n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(start == NULL)
        start = temp;

    else{

        ptr = start;

        while(ptr->next != start && ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->next  = start;   
    }

}

void display(){

    struct node *ptr;
    ptr = start;

    while(ptr->next != start){

        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("%d", ptr->data);

}

void insert_start(){

    struct node *ptr, *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){
        
        printf("could not allocate memory !\n");
        exit(0);
    }

    printf("Enter a value :- \n");
    scanf("%d", &temp->data);
    temp->next = NULL;

    ptr = start;

    while(ptr->next != start)
        ptr = ptr->next;

    ptr->next = temp;
    temp->next = start;
    start = temp;    
}

void insert_end(){

    struct node *ptr, *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("Could not allocate memory !");
        exit(0);
    }

    printf("Enter a value :- \n");
    scanf("%d", &temp->data);

    ptr = start;

    while(ptr->next != start)
        ptr = ptr->next;

    ptr->next = temp;
    temp->next = start;    

}

void insert_desired(){

    struct node *ptr, *temp;

    int count = 1, index;

    temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){

        printf("could not allocate memory ! \n ");
        exit(0);
    }

    printf("Enter desired index :-\n");
    scanf("%d", &index);

    ptr = start;

    if(index == 1){
        insert_start();
        return;
    }

    printf("Enter a value :-\n");
    scanf("%d", &temp->data);

    while(1){

        if(count == index - 1)
            break;

        count++;
        ptr = ptr->next;    
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

void del_begin(){

    struct node* ptr;

    ptr = start;

    while(ptr->next != start)
        ptr = ptr->next;

    ptr->next = ptr->next->next;
    free(start);

    start = ptr->next;      
}

void del_end(){

    struct node *ptr;

    ptr = start;

    while(ptr->next->next != start)
        ptr = ptr->next; 

    free(ptr->next);
    ptr->next = start;

}

void del_desired(){

    struct node *ptr, *temp, *flag;

    int count = 1, index;

    printf("Enter desired index :-\n");
    scanf("%d", &index);

    ptr = start;

    if(index == 1){
        del_begin();
        return;
    }

    while(1){

        if(count == index - 1)
            break;

        count++;
        ptr = ptr->next;    
    }

    flag = ptr->next->next;
    free(ptr->next);
    ptr->next = flag;
}

void search(){

    struct node* ptr;

    int key, count = 0;

    printf("Enter key :-\n");
    scanf("%d", &key);

    ptr = start;

    while(ptr->next!= start){

        count++;

        if(ptr->data == key){

            printf("Key found at %d position\n", count);
            return;
        }
        ptr = ptr->next;
    }

    count++;
    
    if(ptr->data == key){

            printf("Key found at %d position\n", count);
            return;
        }

    printf("Key not found ! \n");
    return;
}

int main(){
    
    int n, choice;

    printf("How many elements do you want ?");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        create();
    
    display();    

    while(1){

            printf("\nWhat task do you want to perform ? \n 1. Insert at beginning \n 2. Insert at end\n 3. Insert at desired position \n 4. Delete beginning \n 5. Delete end \n 6. Delete desired position \n7. Terminate program\n 8. Search\n 9. Reverse \n");
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

                case 7:
                    exit(0);
                
                case 8:
                    search();
                    display();
                    break;

                default:
                    printf("Invalid response !!! \n");        

            }
    }    
}