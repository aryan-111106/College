#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\nMemory overflow! Insertion not possible.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nInserted->%d\n", value);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue Underflow! Deletion not possible.\n");
        return;
    }
    struct Node *temp = front;
    printf("\nDeleted->%d\n", temp->data);
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
}

void peek()
{
    if (front == NULL)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    else
    {
        printf("\nFront element->%d\n", front->data);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    else
    {
        struct Node *temp = front;
        printf("\nQueue elements: ");
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, value;
    do
    {
        printf("\n---QUEUE MENU---\n");
        printf("1.Enqueue(Insert)\n2.Dequeue(Delete)\n3.Peek(Front)\n4.Display\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Program terminated...");
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    } while (choice != 5);
    return 0;
}