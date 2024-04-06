#include<stdio.h>

int sum(int n, int i,int add, int arr[]){

    if(i == n)
        return add;

    add += arr[i];

    sum(n, i + 1, add, arr);
}

int main(){

    int arr[20], n;  
    
    printf("How many elements do you want ?\n");
    scanf("%d", &n);

    for(int i = 0; i < n ; i++)
        scanf("%d", &arr[i]);

    printf("The sum is %d\n", sum(n, 0, 0, arr));

}