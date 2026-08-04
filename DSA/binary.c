#include <stdio.h>
//Binary search
int main()
{
    int n, search, low, mid, high;
    
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    
    int a[n];

    printf("Enter %d sorted integers: \n", n);

    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter a no. to search: ");
    scanf("%d", &search);

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        
        if (a[mid] < search)
        {
            low = mid + 1;
        }
        else if (a[mid] > search)
        {
            high = mid - 1;
        }
        else
        {
            printf("%d is present at index %d", search, mid);
            break;
        }
    }
    if (low > high)
    {
        printf("%d is not present in the array", search);
    }
    return 0;
}