#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insert_begin() {
    struct node *n = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &n->data);

    n->prev = NULL;
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
}

void insert_end() {
    struct node *n = malloc(sizeof(struct node)), *t = head;
    printf("Enter data: ");
    scanf("%d", &n->data);
    n->next = NULL;

    if (head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }

    while (t->next != NULL)
        t = t->next;

    t->next = n;
    n->prev = t;
}

void display() {
    struct node *t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
}

void delete_node() {
    struct node *t = head;
    int x;

    printf("Enter value: ");
    scanf("%d", &x);

    while (t != NULL && t->data != x)
        t = t->next;

    if (t == NULL) return;

    if (t->prev != NULL)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next != NULL)
        t->next->prev = t->prev;

    free(t);
}

void reverse() {
    struct node *t = head;

    if (t == NULL) return;

    while (t->next != NULL)
        t = t->next;

    while (t != NULL) {
        printf("%d ", t->data);
        t = t->prev;
    }
}

int main() {
    int ch;

    while (1) {
        printf("\n1.Insert Beginning\n2.Insert End");
        printf("\n3.Display Forward\n4.Delete Node");
        printf("\n5.Display Reverse\n6.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: display(); break;
            case 4: delete_node(); break;
            case 5: reverse(); break;
            case 6: return 0;
        }
    }
}
