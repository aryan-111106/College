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

void selection_sort(int a[], int n)
{
    int indexofmin;
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        //printf("Working on pass %d\n", i + 1);
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofmin])
            {
                indexofmin = j;
            }
        }
        temp = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = temp;
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

    selection_sort(a, n);

    printf("Array after sorting: \n");
    print_arr(a, n);
}