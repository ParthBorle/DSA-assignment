#include <stdio.h>

int main() 
{
    int max;
    int tmp = 0;
    printf("Enter the size of stack: ");
    scanf("%d", &max);

    int stack[max];
    int top = -1;
    int data;
    int option;

    do {
        printf("\n___MENU___\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) 
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                if (top == max - 1) {
                    printf("Stack overflow\n");
                } 
                else
                {
                    top++;
                    stack[top] = data;
                }
                break;

            case 2:
                if (top == -1) {
                    printf("Underflow\n");
                }
                else 
                {
                    data = stack[top];
                    top--;
                    printf("\nDeleted element is %d\n", data);
                }
                break;

            case 3:
                if (top == -1) {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("\nElements in array are:\n");
                    tmp = 0; // Reset tmp to traverse from the beginning
                    while (tmp <= top)
                        {
                        printf("%d\n", stack[tmp]);
                        tmp++;
                    }
                }
                break;

            case 4:
                printf("GOODBYE\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (option <= 4);

    return 0;
}

