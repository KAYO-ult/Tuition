#include<stdio.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;
void store(int x);
int retrieve();
void main() {
    int val, prompt;
    do {
        printf("\n Press <1> To Store <2> To Retrieve <0> To End = ");
        scanf("%d", &prompt);
        switch (prompt)
        {
        case 1:
            printf("Enter value to store = ");
            scanf("%d", &val);
            store(val);
            break;
        case 2:
            printf("\n Retrieve value = %d", retrieve());
        case 0:
            break;
        }
    }
    while (prompt != 0);
}
void store(int x) {
    if (rear == MAX -1)
    {
        printf("\n Quere overflow");
        //return 0;
    }
    if (rear == -1)
    {
        ++front;
        queue [++rear] = x;
    }
}
int retrieve() {
    int val;
    if (front == -1) {
        printf("\n Queue underflow");
        return 0;
    }
    val = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        ++front;
        return val;
    }
}
