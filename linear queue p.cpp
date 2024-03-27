#include<stdio.h>

int main() {
    int MAX;
    printf("Enter the length of the queue: ");
    scanf("%d", &MAX);

    int Q[MAX], *front = NULL, *rear = NULL;
    int val, option;
   
    do {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERTION");
        printf("\n 2. DELETION");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option: ");
        scanf("%", option);

        switch(option) {
            case 1:
                if(rear == &Q[MAX - 1]) {
                    printf("Overflow\n");
                } else if (front == NULL) {
                    front = &Q[0];
                    rear = &Q[0];
                } else {
                    printf("Enter the element: ");
                    scanf("%d", &val);
                    *rear = val;
                    rear++;
                }
                break;

            case 2:
                if(front == NULL) {
                    printf("Underflow\n");
                } else if(front == rear) {
                    printf("Deleted element: %d\n", *front);
                    front = NULL;
                    rear = NULL;
                } else {
                    printf("Deleted element: %d\n", *front);
                    front++;
                }
                break;

            case 3:
                if(front == NULL) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue elements: ");
                    int *tmp = front;
                    while(tmp < rear) {
                        printf("%d ", *tmp);
                        tmp++;
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("GOOD BYE\n");
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    } while(option < 4);

    return 0;
}

