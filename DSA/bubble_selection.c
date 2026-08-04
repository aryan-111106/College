#include <stdio.h>

int main()
{
    int n, i, j, ch, temp, min, a[100];
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("1. For bubble sort\n");
    printf("2. For selection sort\n");
    printf("Enter choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - i -1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        printf("Sorted array: \n");
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        break;
    case 2:
        for (i = 0; i < n -1; i++)
        {
            min = i;
            for (j = i + 1; j < n; j++)
            {
                if (a[j] < a[min])
                {
                    min = j;
                }
            }
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        printf("Sorted array: \n");
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        break;
    default:
        printf("Invalid choice!");
        break;
    }
    return 0;
}