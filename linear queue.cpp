#include<stdio.h>

int main() 
{
    int MAX;
    printf("Enter the length of the queue: ");
    scanf("%d", &MAX);

    int Q[MAX], front = -1, rear = -1;
    int val, option;
   
    do{
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERTION");
        printf("\n 2. DELETION");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
	{
            case 1:
                if(rear == MAX - 1) {
                    printf("Overflow\n");
                } 
		else if (front < 0) 
		{
                    front = 0;
                }
                else
		{
				
                 
                printf("Enter the element: ");
                scanf("%d", &val);
                rear = rear + 1;
                Q[rear] = val;
	}
		break;

            case 2:{
                int value;
                if(front < 0)
		{
                    printf("Underflow\n");
                }
		else if(front == rear) 
		{
                    value = Q[front];
                    front = rear = -1;
                }
		else
		{
                    value = Q[front];
                    front = front + 1;
                }
                printf("Deleted element: %d\n", value);
                break;
	    }

            case 3:
	{
                if(front < 0) 
		{
                    printf("Queue is empty\n");
                }
		else
		{
                    printf("Queue elements: ");
                    int tmp;
		    tmp=front; 
                    
                    while(tmp <= rear)
		{
                        printf("%d ", Q[tmp]);
                        tmp = tmp + 1;
        n       }
                    printf("\n");
                }
                break;
	}
            case 4:
	{
                printf("GOOD BYE\n");
                break;
	}
            default:
                printf("Invalid option\n");
                break;
        }
    } 
	    while(option != 4);

    return 0;
}

