#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define SIZE 50
char stack[SIZE];
int top = -1;
void push(char item){
    if (top >= SIZE - 1){
        printf("Stack Overflow\n");
    } else stack[++top] = item;
}
char pop(){
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    } else return stack[top--];
}
int precedence(char symbol) {
    switch (symbol){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}
int isOperator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^');
}
void reverse(char *exp) {
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}
void swapParentheses(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}
void infixTopostfix(char infix[], char postfix[]) {
    char ch, temp;
    int i = 0, j = 0;   
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((temp = pop()) != '(') {
                postfix[j++] = temp;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
void infixToprefix() {
    char infix[SIZE], prefix[SIZE], temp[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    reverse(infix);
    swapParentheses(infix);
    infixTopostfix(infix, temp);
    reverse(temp);
    strcpy(prefix, temp);
    printf("Prefix expression: %s\n", prefix);
}
void postfixEvaluation() {
    char postfix[SIZE];
    int stack[SIZE], top = -1, i = 0;
    char ch;
    int val1, val2, result; 
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch))  push(ch - '0');
        else {
            val1 = pop();
            val2 = pop();
            switch (ch) {
                case '+': result = val2 + val1; break;
                case '-': result = val2 - val1; break;
                case '*': result = val2 * val1; break;
                case '/': result = val2 / val1; break;
            }
            push(result);
        }
    }
    result = pop();
    printf("Result of postfix evaluation: %d\n", result);
}
void display() {
    printf("Stack contents: ");
    for (int i = 0; i <= top; i++) printf("%c ", stack[i]);
    printf("\n");
}
void main(){
    int ch;
    do {
        printf("1 for Infix to Postfix\n");
        printf("2 for Infix to Prefix\n");
        printf("3 for Postfix Evaluation\n");   
        printf("4 for Display Stack\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                char infix[SIZE], postfix[SIZE];
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixTopostfix(infix, postfix);
                printf("Postfix expression: %s\n", postfix);
                break;
            }
            case 2: infixToprefix();
                break;
            case 3: postfixEvaluation();
                break;
            case 4: display();
                break;
            case 0: printf("Exiting...\n");
                break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 0);
}