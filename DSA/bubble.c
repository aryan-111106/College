#include <stdio.h>

void enter_arr(int a[], int n)
{
    printf("Enter elements of array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void print_arr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble_sort_adaptive(int a[], int n)
{
    int temp, isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        // printf("Working on pass %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

void bubble_sort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        // printf("Working on pass %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int a[n];
    enter_arr(a, n);

    printf("Array before sorting: \n");
    print_arr(a, n);

    bubble_sort_adaptive(a, n);

    printf("Array after sorting: \n");
    print_arr(a, n);
}