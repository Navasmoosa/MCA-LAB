#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node* root) {
    if(root == NULL) {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}
 void postorder(struct Node* root) {
     if(root == NULL) {
         postorder(root->left);
         postorder(root->right);
         printf("%d", root->data);

     }
 }


struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    struct Node* result = search(root->left, key);

    if (result != NULL)
        return result;

    return search(root->right, key);
}

struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, n, data, i;

    do {
        printf("\n\n1. Create BST");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traverssal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Search");
        printf("\n6. Delete");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                for (i = 0; i < n; i++) {
                    printf("Enter data: ");
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal");
                postorder(root);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &data);

                if (search(root, data) != NULL)
                    printf("Element found!\n");
                else
                    printf("Element not found!\n");
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &data);

                if (search(root, data) != NULL) {
                    root = deleteNode(root, data);
                    printf("Element deleted successfully!\n");
                } else {
                    printf("Element not found!\n");
                }
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    freeTree(root);

    return 0;
}
