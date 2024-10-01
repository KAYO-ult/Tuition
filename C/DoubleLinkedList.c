#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} Node;

Node *start = NULL;

void addBeg() {
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->prev = NULL;

    if (start == NULL) {
        temp->next = NULL;
    } else {
        temp->next = start;
        start->prev = temp;
    }
    start = temp;
}

void addEnd() {
    Node *temp, *last;
    temp = (Node*)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;  // Since it will be the last node, next should be NULL.

    if (start == NULL) {
        temp->prev = NULL;  // If list is empty, the new node becomes the start node.
        start = temp;
    } else {
        last = start;

        // Traverse to the last node
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = temp;  // Set the new node as the last node
        temp->prev = last;  // Update the previous pointer of the new node
    }
}

void display() {
    Node *temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addAfter() {
    Node *temp, *q;
    int pos, i;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Add after node at position: ");
    scanf("%d", &pos);
    q = start;
    for (i = 1; i < pos; i++) {
        q = q->next;
        if (q == NULL) {
            printf("Position out of range\n");
            return;
        }
    }
    temp = (Node*)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);

    temp->next = q->next;
    temp->prev = q;

    if (q->next != NULL) {  // Handle if q is the last node
        q->next->prev = temp;
    }

    q->next = temp;
}

void deleteNode() {
    Node *q, *temp;
    int pos, i;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);
    q = start;

    // Deleting the first node
    if (pos == 1) {
        temp = start;
        start = start->next;
        if (start != NULL) {
            start->prev = NULL;
        }
        free(temp);
        return;
    }

    for (i = 1; i < pos - 1; i++) {
        q = q->next;
        if (q == NULL || q->next == NULL) {
            printf("Position out of range\n");
            return;
        }
    }

    temp = q->next;
    q->next = temp->next;

    if (temp->next != NULL) {  // Handle if temp is not the last node
        temp->next->prev = q;
    }

    free(temp);
}

int main() {
    int choice;
    while (1) {
        printf("1. Add at beginning\n");
        printf("2. Add at end\n");
        printf("3. Add after\n");
        printf("4. Delete node\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBeg();
                break;
            case 2:
                addEnd();
                break;
            case 3:
                addAfter();
                break;
            case 4:
                deleteNode();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
