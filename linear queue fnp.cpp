#include<stdio.h>

int insertion(int *Q, int val, int *front, int *rear, int MAX);
int deletion(int *Q, int *front, int *rear);
int display(int *Q, int front, int rear);

int main() {
    int MAX;
    printf("Enter the length of the queue: ");
    scanf("%d", &MAX);

    int Q[MAX], front = -1, rear = -1;
    int val, option;

    do {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERTION");
        printf("\n 2. DELETION");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &val);
                insertion(Q, val, &front, &rear, MAX);
                break;

            case 2:
                deletion(Q, &front, &rear);
                break;

            case 3:
                display(Q, front, rear);
                break;

            case 4:
                printf("GOOD BYE\n");
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    } while(option != 4);

    return 0;
}

int insertion(int *Q, int val, int *front, int *rear, int MAX) {
    if (*rear  == MAX - 1) {
        printf("Overflow\n");
        
    
    } else if (*front < 0) {
        *front = 0;
        *rear = 0;
    } else {
        (*rear)++;
    }

    Q[*rear] = val;
    
    return 0;
}

int deletion(int *Q, int *front, int *rear) {
    int val;
    if (*front == NULL) {
        printf("Underflow\n");
        
    }
    val = Q[*front];
    if (*front == *rear) {
        *front = NULL;
        *rear = NULL;
    } else {
        (*front)++;
    }
    
    printf("Deleted element: %d\n", val);
    
}

int display(int *Q, int front, int rear) {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
    return 0;
}

