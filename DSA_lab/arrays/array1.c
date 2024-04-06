#include<stdio.h>

int arr[20];

void display(int n){

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void insert(int n){

    int place;
    printf("Where do you want to insert ?");
    scanf("%d", &place);

    for(int i = n; i > place; i--){

        int temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
    }

    printf("Enter the element :-\n");
    scanf("%d", &arr[place]);
}

void delete(int n){

    int place;
    printf("Which element you want to delete ?\n");
    scanf("%d", &place);

    for(int i = place; i < n; i++){

        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void linear_search(int n){   

    int key;
    printf("Which element do you want ?\n");
    scanf("%d", &key);

    for(int i = 0; i < n; i++){

        if(arr[i] == key){

            printf("Element found at %dth index\n", i);
            return;
        }
    }

    printf("Element not in array ! \n");
}

void binary_search(int n){

    int key;
    printf("Which element do you want ?\n");
    scanf("%d", &key);

    int i = arr[0], l = arr[n - 1], mid = (i + l)/2;

    while(i <= l){

        if(key == arr[mid]){

            printf("Element found at %dth index\n", mid);
            return;
        }

        else if(mid < key)
            i = mid;

        else
            l = mid;

        mid = (i + l)/2;
    }
}

void bubble_sort(int n){

    for(int i = 0; i < n; i++){

        for(int j = i; j < n; j++){

            if(arr[i] > arr[j]){

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selection_sort(int n){

    for(int i = 0; i < n; i++){

        int small = i;

        for(int j = i; j < n; j++){

            if(arr[small] > arr[j])
                small = j;
        }

        int temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
        
    }
}

int main(){

    int n;
    printf("How many elements do you want to add ? (< 20)\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    display(n);

    while(1){

        int choice;
        printf("Which task do you want to perform ?\n1. Insert\n2. Delete\n3. Linear Search\n4. Binary Search\n5. Bubble Sort\n6. Selection Sort\n");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                insert(n);
                n++;
                display(n);
                break;

            case 2:
                delete(n);
                n--;
                display(n);  
                break;  

            case 3:
                linear_search(n);
                break;

            case 4:
                binary_search(n);    
                break;

            case 5:
                bubble_sort(n);
                display(n);
                break;    

            case 6:
                selection_sort(n);
                display(n);
                break;
        }
    }    
}