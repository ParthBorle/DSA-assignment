#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int val) {
	
	
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

void display() {
    struct node *tmp;
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        tmp = top;
        printf("Elements in the stack:\n");
        while (tmp != NULL) {
            printf("%d\n", tmp->data);
            tmp = tmp->next;
        }
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("The top of the Data is %d\n", top->data);
    }
}

void pop() {
    struct node *tmp;
    if (top == NULL) {
        printf("The stack is Empty\n");
    } else {
        tmp = top;
        printf("The popped element is %d\n", tmp->data);
        top = tmp->next;
        free(tmp);
    }
}

int main() {
    int option;
    do {
        printf("\n1. Push \n");
        printf("2. Display\n");
        printf("3. Peek \n");
        printf("4. Pop \n");
        printf("5. EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int val;
                printf("Enter the data: ");
                scanf("%d", &val);
                push(val);
                break;
            }
            case 2: {
                display();
                break;
            }
            case 3: {
                peek();
                break;
            }
            case 4: {
                pop();
                break;
            }
            case 5: {
                printf("GOODBYE\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while (option != 5);

    return 0;
}

