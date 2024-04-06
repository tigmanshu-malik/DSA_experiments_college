#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];
int size = 0;

void insert(int data) {

    if (size == 0) {
        tree[0] = data;
        size++;
        return;
    }

    int current = 0;
    while (1) {
        if (data < tree[current]) {
            if (2 * current + 1 < MAX_SIZE && tree[2 * current + 1] == 0) {
                tree[2 * current + 1] = data;
                size++;
                break;
            } else {
                current = 2 * current + 1;
            }
        }
        else {
            if (2 * current + 2 < MAX_SIZE && tree[2 * current + 2] == 0) {
                tree[2 * current + 2] = data;
                size++;
                break;
            } else {
                current = 2 * current + 2;
            }
        }
    }
}

void inorder(int index) {
    if (index < size && tree[index] != 0) {
        inorder(2 * index + 1);
        printf("%d ", tree[index]);
        inorder(2 * index + 2);
    }
}

int main() {

    insert(50);
    insert(30);
    insert(20);
    insert(40);
    insert(70);
    insert(60);
    insert(80);

    printf("Inorder traversal of the BST: ");
    inorder(0);
    printf("\n");

    return 0;
}
