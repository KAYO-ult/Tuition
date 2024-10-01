#include<stdio.h>
#include<stdlib.h>

typedef struct node {                                    //Using typedef
    int data;
    struct node *prev,*next;
} Node;

Node *start = NULL;

void addBeg() {                                          //
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

void display() {
    Node *temp = start;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while(1) {
        printf("1. Add at beginning\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addBeg();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}