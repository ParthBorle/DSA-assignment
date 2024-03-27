#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int top = -1;
int stack[MAX];
int data;

// Function to push an element onto the stack
int push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
       
    } else {
        top++;
        stack[top] = value;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Underflow\n");
        exit(1);
       
    } else {
        data = stack[top];
        top--;
        return data;
    }
}

// Function to evaluate the prefix expression
int evaluate(char expr[]) {
    int len = strlen(expr);
    int i, op1, op2, result;

    // Start from the end of the expression and iterate backwards
    for (i = len - 1; i >= 0; --i) {
        if (expr[i] >= '0' && expr[i] <= '9') {
            push(expr[i] - '0');
        } else {
            op1 = pop();
            op2 = pop();
            switch (expr[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                default:
                    printf("Invalid operator\n");
                    
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char expr[100];

    printf("Enter prefix expression: ");
    scanf("%s", expr);

    int result = evaluate(expr);
    printf("Result: %d\n", result);

    return 0;
}

