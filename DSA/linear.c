#include <stdio.h>
//Linear search
int main()
{
    int n, i, search;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    
    int a[n];

    printf("Enter %d integers: \n", n);
    for (i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter no. to search: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            printf("%d is present at index %d", search, i);
            break;
        }
    }

    if (i == n)
    {
        printf("%d is not present in the array", search);
    }
    return 0;
}