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
        printf("\n------ Circular Linked List Menu ------\n");
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

/* Insert at Beginning */
void insertBeginning()
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    /* If list is empty */
    if (head == NULL)
    {
        head = newNode;                      
        newNode->next = head;
    }
    else
    {
        temp = head;

        /* Find last node */
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("Node inserted at beginning.\n");
}

/* Insert at End */
void insertEnd()
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    /* If list is empty */
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        /* Find last node */
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}

/* Insert at Specific Position */
void insertPosition()
{
    int pos, i;
    struct Node *newNode;
    struct Node *temp;

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

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    temp = head;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}

/* Delete from Beginning */
void deleteBeginning()
{
    struct Node *temp;
    struct Node *last;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    /* Only one node */
    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("First node deleted.\n");
        return;
    }

    temp = head;
    last = head;

    /* Find last node */
    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    free(temp);

    printf("First node deleted.\n");
}

/* Delete from End */
void deleteEnd()
{
    struct Node *temp;
    struct Node *del;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    /* Only one node */
    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;

    /* Find second-last node */
    while (temp->next->next != head)
        temp = temp->next;

    del = temp->next;
    temp->next = head;

    free(del);

    printf("Last node deleted.\n");
}

/* Delete from Specific Position */
void deletePosition()
{
    int pos, i;
    struct Node *temp;
    struct Node *del;

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

    temp = head;

    for (i = 1; i < pos - 1; i++)
        temp = temp->next;

    del = temp->next;
    temp->next = del->next;

    free(del);

    printf("Node deleted successfully.\n");
}

/* Display List */
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD\n");
}

/* Search Element */
void search()
{
    int key, pos = 1;
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;

    do
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element not found.\n");
}

/* Count Nodes */
int countNodes()
{
    int count = 0;
    struct Node *temp;

    if (head == NULL)
        return 0;

    temp = head;

    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}