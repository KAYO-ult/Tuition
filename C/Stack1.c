#include<stdio.h>
#define MAX 10
int stack[MAX], top = -1;
void push(int x);
int pop();
void display();
int main() {
    int val, prompt;
    do {
        printf("\n Press <1> To PUSH data <2> To POP data <3> To Display data <0> To END = ");
        scanf("%d",&prompt);
        switch (prompt)
        {
        case 1:printf("\n Enter value to push = ");
               scanf("%d",&val);
               push (val);
            break;
        case 2:printf("\n Popped value = %d", pop());
            break;
        case 3:display();
            break;
        case 0:break;
        default:printf("\n Enter correct choice = ");
        }
    }
    while (prompt!=4);
}

void push (int x) {
    if (top == MAX -1)
    printf("\n!!! Stack Overflow !!!");
    else
    stack [++top] = x;
}

int pop() {
    if (top == -1)
    {
        printf("\n!!! Stack Underflow !!!");
        return 0;
    }   
    else
    return stack [top--];
}

void display() {
    if (top == -1) {
        printf("\n!!! Stack is empty !!!");
    } else {
        printf("\n Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
}