#include <stdio.h>
#include <stdlib.h>

// time complexity is O(n)
//best sorting algo as it sorts the array in linear time
//disadvantage is that it consumes extra space

void Print_Array(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void Input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void count_sort(int *arr, int n)
{
    int i, j, k, max;
    int *arr1 = (int *)malloc(n * sizeof(int));
    max = arr[0];
    for (i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i < (max + 1); i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[arr[i]] += 1;
    }

    k = 0;
    j = 0;
    while (j <= max)
    {
        if (count[j] > 0)
        {
            arr1[k++] = j;
            count[j]--;
        }
        else
        {
            j++;
        }
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = arr1[i];
    }
}

int main()
{
    int n;

    printf("Enter size :");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    Input(arr, n);
    count_sort(arr, n);
    printf("The sorted array is\n");
    Print_Array(arr, n);

    return 0;
}
