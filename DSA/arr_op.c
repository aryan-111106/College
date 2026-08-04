#include <stdio.h>

int a[20];
int n, val, i, pos, found, choice;

void create();
void display();
void insert();
void delete();
void find();

int main()
{
    while (1)
    {
        printf("\n\n------MENU------\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. FIND\n");
        printf("6. EXIT\n");
        printf("\n ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete();
            break;
        case 5:
            find();
            break;
        case 6:
            return 0;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
    return 0;
}

void create()
{
    printf("\nEnter the size of the array (max 20): ");
    scanf("%d", &n);
    if (n > 20 || n <= 0)
    {
        printf("\nInvalid size. Max allowed is 20.\n");
        return;
    }

    printf("\nEnter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display()
{
    if (n == 0)
    {
        printf("\nArray is empty.\n");
        return;
    }

    printf("\nArray elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void insert()
{
    if (n >= 20)
    {
        printf("\nArray is full. Cannot insert.\n");
        return;
    }

    printf("\nEnter the position for the new element (0 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n)
    {
        printf("\nInvalid position.\n");
        return;
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &val);

    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }

    a[pos] = val;
    n = n + 1;
}

void delete()
{
    if (n == 0)
    {
        printf("\nArray is empty. Nothing to delete.\n");
        return;
    }

    printf("\nEnter the position of the element to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n)
    {
        printf("\nInvalid position.\n");
        return;
    }

    val = a[pos];
    for (i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    n = n - 1;
    printf("\nDeleted element is %d\n", val);
}

void find()
{
    if (n == 0)
    {
        printf("\nArray is empty. Nothing to find.\n");
        return;
    }
    printf("Enter element to find: ");
    scanf("%d", &val);
    found = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            printf("Element found at index %d\n", i);
            found = 1;
            return;
        }
    }
    if (found == 0)
    {
        printf("Element not found\n");
    }
}