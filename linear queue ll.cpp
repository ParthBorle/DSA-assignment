#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int MAX;
    printf("Enter the length of the queue: ");
    scanf("%d", &MAX);

    struct Node* front = NULL;
    struct Node* rear = NULL;
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
                if(rear->next == NULL) {
                    printf("Overflow\n");
                } else {
                    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
                    if (newnode == NULL) {
                        printf("Memory allocation failed\n");
                        break;
                    }
                    printf("Enter the element: ");
                    scanf("%d", &val);
                    newnode->data = val;
                    newnode->next = NULL;
                    if (front == NULL) {
                        front = rear = newnode;
                    } else {
                        rear->next = newnode;
                        rear = newnode;
                    }
                }
                break;

            case 2:
                if(front == NULL) {
                    printf("Underflow\n");
                } else {
                    struct Node* tmp;
                    tmp=front;
                    tmp->data=val;
                    front = front->next;
                    free(tmp);
                    printf("Deleted element: %d\n", val);
                    
                }
                break;

            case 3:
                if(front == NULL) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue elements: ");
                    struct Node* tmp = front;
                    while(tmp != NULL) {
                        printf("%d ", tmp->data);
                        tmp = tmp->next;
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
    } while(option != 4);

    

    return 0;
}

