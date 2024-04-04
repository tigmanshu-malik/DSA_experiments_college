#include<stdio.h>

int main(){

    struct student{

        char fname[20];
        char lname[20];
        int roll;
    };

    struct student arr[5];

    for(int i = 0; i < 5; i++){

        printf("Enter first name \n");
        getchar();
        fgets(arr[i].fname, 20, stdin);

        printf("Enter last name \n");
        getchar();
        fgets(arr[i].lname, 20, stdin);

        printf("Enter roll no :-\n");
        scanf("%d", &arr[i].roll);
    }

    for(int i = 4; i >= 0; i--){

        for(int j = 0; j < i; j++){

            if(arr[j].roll > arr[j + 1].roll){

                struct student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Displaying accounts :-\n");
    for(int i = 0; i < 5; i++){

        printf("Roll - %d\n", arr[i].roll);
        printf("Name - %s %s\n\n", arr[i].fname, arr[i].lname);
    }
}