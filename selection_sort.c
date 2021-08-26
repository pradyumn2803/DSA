#include <stdio.h>
#include <stdlib.h>

/*  
   TIme Complexity- O(n^2) --*/

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

void Selection_sort(int *arr, int n) // n elements n-1 passes
{
    int index, i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }
        if (index != i)
        {
            temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }

        printf("Element after %d pass :\n", i + 1);
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
    Selection_sort(arr, n);
    printf("The sorted array is\n");
    Print_Array(arr, n);

    return 0;
}