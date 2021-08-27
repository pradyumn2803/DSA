#include <stdio.h>
#include <stdlib.h>

/*  
   Time Complexity- 
    best case- O(nlogn)----when the middle of the array is a pivot
    worst case-O(n^2)----when the middle is not a pivot .for n elements (n-1) 
    times the partition needs to be done.
    average case-O(nlogn).    
*/

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

int partition(int *arr, int low, int high)
{
    int pivot = arr[low], temp;
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int *arr, int low, int high) 
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(arr, low, high);
        quick_sort(arr, low, partitionindex - 1);
        quick_sort(arr, partitionindex + 1, high);
    }
}

int main()
{
    int n, low, high;

    printf("Enter size :");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    low = 0;
    high = n - 1;

    Input(arr, n);
    quick_sort(arr, low, high);
    printf("The sorted array is\n");
    Print_Array(arr, n);

    return 0;
}