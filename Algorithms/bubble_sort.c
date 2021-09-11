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

void Bubble_sort(int *arr, int n, int pass)
{
    int swap = 0, temp, i;

    for (i = 0; i < pass; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap += 1;
            }
        }
        if (swap == 0)
        {
            printf("Array given is already sorted\n");
            break;
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
    int pass;

    printf("Enter the number of pass: ");
    scanf("%d", &pass);

    Input(arr, n);
    Bubble_sort(arr, n, pass);
    printf("The sorted array is\n");
    Print_Array(arr, n);

    return 0;
}