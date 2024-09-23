#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX-1) {
        printf("Stack Overflow\n");
        printf("------------------------\n");
    } else {
        top++;
        stack[top] = value;
        printf("Given value successfully Pushed\n");
        printf("------------------------\n");
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        printf("------------------------\n");
    } else {
        top--;
        printf("Given value successfully Popped\n");
        printf("------------------------\n");
    }
}

void display() {
    if (top == -1) {
        printf("Stack is already empty\n");
    } else {
        printf("Stack elements as followed\n"); 
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
    printf("------------------------\n");
}

void main() {
    int inp, value;
    char ch = 'y';
    printf("This is STACK implementation\n");

    while (ch == 'y') {
        printf("Press 1 for PUSH \nPress 2 for POP \nPress 3 for PRINT\n");
        printf("Your choice: ");
        scanf("%d", &inp);
    
        switch(inp) {
            case 1:
                // PUSH operation
                printf("Enter which value you want to push in stack: ");
                scanf("%d", &value);
                push(value);
                break;
        
            case 2:
                // POP operation
                pop();
                break;
        
            case 3:
                // PRINT stack elements
                display();
                break;
       
            default:
                printf("Invalid input\n");
        }
        printf("Do you want to continue this process \n(Press y for YES & n for NO): ");
        scanf(" %c", &ch); // Added space before %c to avoid newline issues
        printf("\n");
    }
}