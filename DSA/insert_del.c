#include <stdio.h>

int main()
{
    int n, i, pos, element, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: // INSERT
        printf("Enter position to insert (1 to %d): ", n + 1);
        scanf("%d", &pos);
        printf("Enter element to insert: ");
        scanf("%d", &element);

        for (i = n; i >= pos; i--)
            a[i] = a[i - 1];

        a[pos - 1] = element;
        n++;

        printf("Array after insertion:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        break;

    case 2: // DELETE
        printf("Enter position to delete (1 to %d): ", n);
        scanf("%d", &pos);

        for (i = pos - 1; i < n - 1; i++)
            a[i] = a[i + 1];

        n--;

        printf("Array after deletion:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        break;

    default:
        printf("Invalid choice!");
    }

    return 0;
}