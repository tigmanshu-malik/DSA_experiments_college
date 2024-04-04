//Write a program to read the name, address, and salary of 5 employees using array of structure. 
//Display information of each employee in alphabetical order of their name.

#include<stdio.h>
#include<string.h>

int main(){

    struct employee{

        char name[20];
        char address[30];
        int salary;
    };

    struct employee arr[5];

    for(int i = 0; i < 5; i++){

        printf("%d employee\n", i + 1);

        printf("Enter the name of employee :- ");
        getchar();
        fgets(arr[i].name, 20, stdin);

        printf("\nEnter the address :- ");
        getchar();
        fgets(arr[i].address, 30, stdin);

        printf("\nEnter salary :-");
        scanf("%d", &arr[i].salary);
    }

    for(int i = 4; i >= 0 ; i--){

        for(int j = 0; j < i; j++){

            if(strcmp(arr[j].name, arr[j + 1].name) > 0){

                struct employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < 5; i++){

        printf("\nEmployee - %d\n", i);
        printf("Name - %s\n", arr[i].name);
        printf("Address - %s\n", arr[i].address);
        printf("Salary - %d\n", arr[i].salary);
    }
}