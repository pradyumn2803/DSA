#include <stdio.h>
#include <stdlib.h>

/*  
    best case-O(n)
    Worst case-O(n^2) --*/

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

void Insert_sort(int *arr, int n) // n elements n-1 passes
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("Element after %d pass :\n", i);
        Print_Array(arr, n);
    }
}

int main()
{
    int n;

    printf("Enter size :");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    Input(arr, n);
    Insert_sort(arr, n);
    printf("The sorted array is\n");
    Print_Array(arr, n);

    return 0;
}