#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a circular linked list
void createList(struct node *head) {
    struct node *newnode, *tmp;
    int data;
    char ch;

    do {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the element you want to insert: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            newnode->next = head; // Pointing back to itself 
        } else {
            tmp = head;
            while (tmp->next != head)
                tmp = tmp->next;
            tmp->next = newnode;
            newnode->next = head; // Pointing back to head 
        }

        printf("Do you want to continue (1/0)? ");
        scanf(" %d", &ch);
    } while (ch == '1');
}

// Function to display the circular linked list
void displayList(struct node *head) {
    struct node *tmp;
    if (head == NULL) {
        printf("List is empty\n");
        
    }
    tmp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while (tmp != head);
    printf("\n");
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct node *head) {
    struct node *newnode, *tmp;
    int data;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = head;

    tmp = head;
    while (tmp->next != head)
        tmp = tmp->next;
    tmp->next = newnode;
    head = newnode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct node *head) {
    struct node *newnode, *tmp;
    int data;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = head;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        tmp = head;
        while (tmp->next != head)
            tmp = tmp->next;
        tmp->next = newnode;
    }
}

// Function to insert a node at a particular position in the circular linked list
void insertAtPosition(struct node *head) {
    struct node *newnode, *tmp,*prev;
    int data, pos, i = 1;

    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("Enter the data: ");
    scanf("%d", &data);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (pos == 1) {
        newnode->next = head;
        tmp = head;
        while (tmp->next != head)
            tmp = tmp->next;
        tmp->next = newnode;
        head = newnode;
    } else {
        tmp = head;
        struct node *prev = NULL;
        tmp = head;
        while (tmp->next != head && i < pos) {
            prev = tmp;
            tmp = tmp->next;
            i++;
        }
        if (i != pos) {
            printf("Invalid position\n");
            return;
        }
        newnode->next = tmp;
        prev->next = newnode;
    }
}

// Function to insert a node after a particular data value in the circular linked list
void insertAfterValue(struct node *head) {
    struct node *newnode, *tmp;
    int value, data;

    printf("Enter the value after which the node has to be inserted: ");
    scanf("%d", &value);
    printf("Enter the data of the new node: ");
    scanf("%d", &data);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    tmp = head;
    do {
        if (tmp->data == value) {
            newnode->next = tmp->next;
            tmp->next = newnode;
            return;
        }
        tmp = tmp->next;
    } while (tmp != head);

    printf("Value not found in the list\n");
}

// Function to delete a node from the beginning of the circular linked list
void deleteFromBeginning(struct node *head) {
    struct node *tmp, *last;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    tmp = head;
    last = head;
    while (last->next != head)
        last = last->next;

    if (tmp->next == head) {
        free(tmp);
        head = NULL;
    } else {
        last->next = tmp->next;
        free(tmp);
        head = last->next;
    }

    printf("Node deleted from the beginning successfully\n");
}

// Function to delete a node from the end of the circular linked list
void deleteFromEnd(struct node *head) {
    struct node *tmp, *last, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    tmp = head;
    last = head;
    prev = NULL;
    while (last->next != head) {
        prev = last;
        last = last->next;
    }

    if (tmp->next == head) {
        free(tmp);
        head = NULL;
    } else {
        prev->next = head;
        free(last);
    }

    printf("Node deleted from the end successfully\n");
}

// Function to delete a node from a particular position in the circular linked list
void deleteFromPosition(struct node *head) {
    struct node *tmp, *prev;
    int pos, i = 1;

    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    tmp = head;
    prev = NULL;
    while (tmp->next != head && i < pos) {
        prev = tmp;
        tmp = tmp->next;
        i++;
    }

    if (i != pos) {
        printf("Invalid position\n");
        return;
    }

    if (tmp == head) {
        while (tmp->next != head)
            tmp = tmp->next;
        head = (head)->next;
        tmp->next = head;
        free(tmp);
    } else {
        prev->next = tmp->next;
        free(tmp);
    }

    printf("Node deleted from position %d successfully\n", pos);
}

// Function to delete a node by a particular data value from the circular linked list
void deleteByValue(struct node *head) {
    struct node *tmp, *prev;
    int value;
    int found = 0;

    printf("Enter the value to delete: ");
    scanf("%d", &value);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    tmp = head;
    prev = NULL;
    do {
        if (tmp->data == value) {
            found = 1;
            if (tmp == head) {
                while (tmp->next != head)
                    tmp = tmp->next;
                head = head->next;
                tmp->next = head;
                free(tmp);
            } else {
                prev->next = tmp->next;
                free(tmp);
            }
            printf("Node with value %d deleted successfully\n", value);
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    } while (tmp != head);

}


int main() {
    struct node *head = NULL;
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
                createList(head);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                insertAtBeginning(head);
                break;

            case 4:
                insertAtEnd(head);
                break;

            case 5:
                insertAtPosition(head);
                break;

            case 6:
                insertAfterValue(head);
                break;

            case 7:
                deleteFromBeginning(head);
                break;

            case 8:
                deleteFromEnd(head);
                break;

            case 9:
                deleteFromPosition(head);
                break;

            case 10:
                deleteByValue(head);
                break;

            case 11:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
                break;
        }

    } while (choice != 11);

    return 0;
}


