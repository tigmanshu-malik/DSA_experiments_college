#include<stdio.h>

int main(){

    struct employee{

        char name[20];
        char address[30];
        int age;
        int salary;
    };

    int n, sum = 0;

    printf("How many employees ?\n");
    scanf("%d", &n);

    struct employee arr[n];

    for(int i = 0; i < n; i++){

        printf("%d employee\n", i + 1);

        printf("Enter the name of employee :- ");
        getchar();
        fgets(arr[i].name, 20, stdin);

        printf("\nEnter the address :- ");
        getchar();
        fgets(arr[i].address, 30, stdin);

        printf("\nEnter age :-");
        scanf("%d", &arr[i].age);

        printf("\nEnter salary :-");
        scanf("%d", &arr[i].salary);

    }

    for(int i = 0; i < n; i++)
        sum += arr[i].salary;

    printf("\nThe average salary is %d\n", sum/n);    
}