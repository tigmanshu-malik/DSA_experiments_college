#include<stdio.h>
#include<stdlib.h>

struct poly {
    int coeff;
    int expo;
    struct poly *next;
};

struct poly *start1 = NULL;
struct poly *start2 = NULL;
struct poly *start3 = NULL;

void create(struct poly **start, int i) { 

    struct poly *temp, *ptr = *start; 

    temp = (struct poly*)malloc(sizeof(struct poly));

    if (temp == NULL)
        exit(0);

    printf("Enter the coefficient of %d degree: ", i);
    scanf("%d", &temp->coeff);

    temp->expo = i;

    temp->next = NULL;

    if (*start == NULL)
        *start = temp; 
    else {

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
    }
}

void create_third(struct poly **start, int i){

    struct poly *temp, *ptr = *start; 

    temp = (struct poly*)malloc(sizeof(struct poly));

    if (temp == NULL)
        exit(0);

    temp->expo = i;    

    temp->next = NULL;

    if (*start == NULL)
        *start = temp; 
    else {

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
    }
}

void display(struct poly *start) {

    struct poly *ptr = start;

    while (ptr->next != NULL) {

        printf("%dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->next;
    }

    printf("%dx^%d", ptr->coeff, ptr->expo);
}

void addition(){

    struct poly *ptr1 = start1, *ptr2 = start2;

    while(ptr1->expo != ptr2->expo){

        printf("%dx%d + ", ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while(ptr1->expo != 0){

        printf("%dx^%d + ", ptr1->coeff  + ptr2->coeff, ptr1->expo);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }   

    printf("%dx^%d", ptr1->coeff  + ptr2->coeff, ptr1->expo);
}

void subtraction(){

    struct poly *ptr1 = start1, *ptr2 = start2;

    while(ptr1->expo != ptr2->expo){

        printf("%dx%d + ", ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while(ptr1->expo != 0){

        printf("%dx^%d + ", ptr1->coeff  - ptr2->coeff, ptr1->expo);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }   

    printf("%dx^%d", ptr1->coeff  - ptr2->coeff, ptr1->expo);
}

void multiplication(int degree1, int degree2){

    struct poly *ptr1 = start1, *ptr2, *ptr3;

    for(int i = 0; i <= degree1 + degree2; i++)
        create_third(&start3, i);

    for(int i = 0; i <= degree1; i++){

        ptr2 = start2;

        for(int j = 0; j<= degree2; j++){

            int exponent = ptr1->expo+ptr2->expo;
            int coefficient = ptr1->coeff*ptr2->coeff;

            ptr3 = start3;

            while(ptr3->expo != exponent)
                ptr3 = ptr3->next;

            ptr3->coeff += coefficient;  

            ptr2 = ptr2->next;  
        }

        ptr1 = ptr1->next;
    }

    display(start3);    
}

void degree_check(int degree1, int degree2, int flag){
    
    if(degree2 > degree1){

        struct poly *temp = start1;
        start1 = start2;
        start2 = temp;

        if(flag == 1)
            addition();

        else if(flag == -1)
            subtraction();        

        temp = start1;
        start1 = start2;
        start2 = temp;

    }

    else{
        if(flag == 1)
            addition();

        else if(flag == -1)
            subtraction();
    }

    
}

int main() {

    int degree1, degree2;

    printf("Enter degree of first polynomial:\n");
    scanf("%d", &degree1);

    for (int i = degree1; i >= 0; i--)
        create(&start1, i); 

    printf("Polynomial 1: ");
    display(start1);

    printf("\nEnter degree of second polynomial:\n");
    scanf("%d", &degree2);

    for (int i = degree2; i >= 0; i--)
        create(&start2, i);  

    printf("Polynomial 2: ");
    display(start2);

    while(1){
        int choice;
        printf("\nWhat operation do you want ? \n1.Addition\n2.Subtraction\n3.Multiplication\n");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                degree_check(degree1, degree2, 1);
                break;

            case 2:
                degree_check(degree1, degree2, -1);   
                break;

            case 3:
                multiplication(degree1, degree2);    
                break;

            default:
                printf("Invalid input \n");     
        }
    }
    
}