#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }

    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *search(Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
Node *minValueNode(Node *node) {
    Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node *deleteNode(Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void destroyTree(Node *root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

int main() {
    Node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    while(1){

        int choice;
        printf("What task do you want to perform ?\n1. Search\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Delete");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                int key;
                printf("Enter key :-\n");
                scanf("%d", &key);
                Node *result = search(root, key);
                if (result != NULL) {
                    printf("Element %d found in the BST\n", key);
                } else {
                    printf("Element %d not found in the BST\n", key);
                }

                break;

            case 2:
                inorder(root);
                break;

            case 3:        
                preorder(root);
                break;

            case 4:
                postorder(root);  
                break;

            case 5:
                printf("Enter key :-\n");
                scanf("%d", &key);

                root = deleteNode(root, key);
                
            }
    }
}
