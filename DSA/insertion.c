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

void insertion_sort(int a[], int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        // printf("Working on pass %d\n", i + 1);
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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

    insertion_sort(a, n);

    printf("Array after sorting: \n");
    print_arr(a, n);
}