// #include<stdio.h>
// #define MAX 10
// int stack[MAX], top = -1;
// void push(int x);
// int pop();
// void display();
// int main() {
//     int val, prompt;
//     do {
//         printf("\n Press <1> To PUSH data <2> To POP data <3> To Display data <0> To END = ");
//         scanf("%d",&prompt);
//         switch (prompt)
//         {
//         case 1:printf("\n Enter value to push = ");
//                scanf("%d",&val);
//                push (val);
//             break;
//         case 2:printf("\n Popped value = %d", pop());
//             break;
//         case 3:display();
//             break;
//         case 0:break;
//         default:printf("\n Enter correct choice = ");
//         }
//     }
//     while (prompt!=4);
// }

// void push (int x) {
//     if (top == MAX -1)
//     printf("\n!!! Stack Overflow !!!");
//     else
//     stack [++top] = x;
// }

// int pop() {
//     if (top == -1)
//     {
//         printf("\n!!! Stack Underflow !!!");
//         return 0;
//     }   
//     else
//     return stack [top--];
// }

// void display() {
//     if (top == -1) {
//         printf("\n!!! Stack is empty !!!");
//     } else {
//         printf("\n Stack elements are: ");
//         for (int i = top; i >= 0; i--) {
//             printf("%d ", stack[i]);
//         }
//     }
// }




#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
int stk[10];
int top=-1;

int main()
{
    int ch;
    while(1)
    {
        printf("\n 1 for push");
        printf("\n 2 for pop");
        printf("\n 3 for display");
        printf("\n Enter your choice = ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n Wrong choice");
        }
    }
}

void push()
{
    if(top==9)
    {
        printf("\n Stack overflow");
        return;
    }
    top++;
    printf("\n Enter data to push");
    scanf("%d",&stk[top]);
}

void pop()
{
    if(top == -1)
    {
        printf("\n Stack underflow");
        return;
    }
    printf("\n popped data=%d",stk[top]);
    top--;
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("\n Stack underflow");
        return;
    }
    printf("\n Stack elements are:\n");
    for(i = top; i>=0; i--)
        printf("\n %d",stk[i]);
}
