#include <stdio.h>



// Function to insert an element into the stack
void push(int stack[], int top, int max) {
    int data;
    if (top == max - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &data);
        top++;
        stack[top] = data;
    }
}

// Function to delete an element from the stack
void pop(int stack[], int top) {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Deleted element: %d\n", stack[top]);
        (top)--;
    }
}

// Function to traverse and display the elements of the stack
void display(int stack[], int top)
{
	int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Elements in the stack:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Function to peek at the top element of the stack
void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("The top of the stack is %d\n", stack[top]);
    }
}

int main() {
	int max;
	printf("enter the max size");
	scanf("%d",&max);
    int stack[max];
    int top = -1;
    int choice;

    do {
        printf("\n********MENU*******\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, top, max);
                break;
            case 2:
                pop(stack, top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                peek(stack, top);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

