#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *newnode, *temp, *prev;
    head = NULL;
    int choice;
    
    do {
        printf("\n\n\n1. Enter for Creation of nodes\n");
        printf("2. Enter for Displaying nodes\n");
        printf("3. Enter to insert a node at beginning\n");
        printf("4. Enter to insert a node at the end\n");
        printf("5. Enter to insert a node at particular position\n");
        printf("6. Enter to insert a node after a particular data\n");
        printf("7. Enter to delete a node at beginning\n");
        printf("8. Enter to delete a node at end\n");
        printf("9. Enter to delete a node at any particular location\n");
        printf("10. Enter to delete a node of particular element\n");
        printf("11. EXIT \n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            {
                head = NULL;
                int count = 1;
                int data;
                do 
                {
                    newnode = (struct node*)malloc(sizeof(struct node));
                    printf("Enter the element you want to insert: ");
                    scanf("%d", &data);
                    newnode->data = data;
                    newnode->next = NULL;

                    if (head == NULL) 
                    {
                        head = newnode;
                        newnode->next = head; // Pointing back to itself for circularity
                    }
                    else
                    {
                        temp = head;
                        while (temp->next != head)
                            temp = temp->next;
                        temp->next = newnode;
                        newnode->next = head; // Pointing back to head for circularity
                    }

                    printf("Node %d contains Data = %d and Address = %p\n", count, newnode->data, newnode->next);
                    printf("Do you want to continue(1, 0): ");
                    scanf("%d", &choice);
                    count++;
                } 
                    while (choice == 1);
                break;
            }

            case 2: 
        {
                if (head == NULL)
                {
                    printf("NO NODE IS AVAILABLE\n");
                }
                else
                {
                    temp = head;
                    printf("Node contains: ");
                    do
                        {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                        while (temp != head);
                    printf("\n");
                }
                break;
            }

            case 3: {
                int num;
                printf("Enter the data: ");
                scanf("%d", &num);
                newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = num;
                newnode->next = head;
                temp = head;
                while (temp->next != head)
                    temp = temp->next;
                temp->next = newnode;
                head = newnode;
                break;
            }

            case 4: {
                int num;
                printf("Enter the data: ");
                scanf("%d", &num);
                newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = num;
                newnode->next = head;
                temp = head;
                while (temp->next != head)
                    temp = temp->next;
                temp->next = newnode;
                break;
            }

            case 5: {
                int pos, num;
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter the data: ");
                scanf("%d", &num);
                newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = num;
                temp = head;
                for (int i = 1; i < pos - 1; i++)
                    temp = temp->next;
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }

            case 6: {
                int value, element;
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                temp = head;
                do 
                {
                    if (temp->data == value)
                    {
                        newnode = (struct node*)malloc(sizeof(struct node));
                        newnode->data = element;
                        newnode->next = temp->next;
                        temp->next = newnode;
                        break;
                    }
                    temp = temp->next;
                } 
                while (temp != head);
                break;
            }

            case 7: {
                if (head == NULL) 
                {
                    printf("Underflow\n");
                }
                else if (head->next == head)
                {
                    free(head);
                    head = NULL;
                }
                else
                {
                    temp = head;
                    while (temp->next != head)
                        temp = temp->next;
                    temp->next = head->next;
                    free(head);
                    head = temp->next;
                }
                break;
            }

            case 8: {
                if (head == NULL) 
                {
                    printf("Underflow\n");
                }
                else if (head->next == head) 
                {
                    free(head);
                    head = NULL;
                }
                else
                {
                    temp = head;
                    prev = NULL;
                    while (temp->next != head)
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                    prev->next = head;
                    free(temp);
                }
                break;
            }

            case 9: {
                if (head == NULL) 
                {
                    printf("UNDERFLOW");
                }
                else
                {
                    int pos;
                    printf("Enter the position to delete: ");
                    scanf("%d", &pos);
                    if (pos < 1)
                    {
                        printf("Invalid position\n");
                    } 
                    else if (pos == 1) 
                    {
                        if (head->next == head) 
                        {
                            free(head);
                            head = NULL;
                        }
                        else {
                            temp = head;
                            while (temp->next != head)
                                temp = temp->next;
                            temp->next = head->next;
                            free(head);
                            head = temp->next;
                        }
                    }
                    else
                    {
                        temp = head;
                        prev = NULL;
                        int i = 1;
                        while (i < pos && temp->next != head)
                            {
                            prev = temp;
                            temp = temp->next;
                            i++;
                        }
                        if (temp == head)
                        {
                            printf("Position not found\n");
                        }
                        else
                        {
                            prev->next = temp->next;
                            free(temp);
                        }
                    }
                }
                break;
            }

            case 11: {
                printf("Exiting...\n");
                break;
            }

            default: {
                printf("Invalid choice\n");
                break;
            }
        }

    } while (choice != 11);

   
    return 0;
}

