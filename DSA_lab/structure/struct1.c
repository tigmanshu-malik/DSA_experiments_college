#include<stdio.h>

int main(){

    struct student{

        char name[20];
        int roll;
        int marks;
    };

    int n;
    printf("How many entries do you want to make ?\n");
    scanf("%d", &n);

    struct student arr[n];

    for(int i = 0; i < n; i++){

        printf("\n%dth student :- \n", i + 1);

        printf("Enter the name :-\n");
        getchar();
        fgets(arr[i].name, 20, stdin);

        printf("Enter the roll number :-\n");
        scanf("%d", &arr[i].roll);

        printf("Enter marks :-\n");
        scanf("%d", &arr[i].marks);
    }

    printf("Displaying records :-\n");

    for(int i = 0; i < n; i++){

        printf("%dth student\n", i + 1);
        printf("Name - %s\n", arr[i].name);
        printf("Roll - %d\n", arr[i].roll);
        printf("Marks - %d\n\n", arr[i].marks);
        
    }
}