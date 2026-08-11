#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning();
void insertEnd();
void insertPosition();
void deleteBeginning();
void deleteEnd();
void deletePosition();
void display();
void search();
int countNodes();

int main()
{
    int choice;

    while (1)
    {
        printf("\n------ Singly Linked List Menu ------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Search Element\n");
        printf("9. Count Nodes\n");
        printf("10. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            insertPosition();
            break;

        case 4:
            deleteBeginning();
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            deletePosition();
            break;

        case 7:
            display();
            break;

        case 8:
            search();
            break;

        case 9:
            printf("Total Nodes = %d\n", countNodes());
            break;

        case 10:
            printf("Program terminated.\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
void insertBeginning()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}
void insertEnd()
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}
void insertPosition()
{
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > countNodes() + 1)
    {
        printf("Invalid Position!\n");
        return;
    }

    if (pos == 1)
    {
        insertBeginning();
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    struct Node *temp = head;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}
void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    free(temp);

    printf("First node deleted.\n");
}
void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    printf("Last node deleted.\n");
}
void deletePosition()
{
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos < 1 || pos > countNodes())
    {
        printf("Invalid Position!\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    struct Node *temp = head, *del;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    del = temp->next;
    temp->next = del->next;

    free(del);

    printf("Node deleted successfully.\n");
}
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
void search()
{
    int key, pos = 1;
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element not found.\n");
}
int countNodes()
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}