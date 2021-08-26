#include <stdio.h>
#include <stdlib.h>

//if we have 2 sorted arrays and we want to merge the 2 arrays and sort the resultant
// time complexity is O(nlogn)

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

void merge_sort(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0, k = 0;
    int *arr = (int *)malloc((n1 + n2) * sizeof(int));
    while (k < (n1 + n2))
    {
        if (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                arr[k++] = arr1[i++];
            }
            else
            {
                arr[k++] = arr2[j++];
            }
        }
        else if (i >= (n1))
        {
            arr[k++] = arr2[j++];
        }

        else if (j >= (n2))
        {
            arr[k++] = arr1[i++];
        }
    }

    printf("The sorted array is\n");
    Print_Array(arr, k);
}

int main()
{
    int n1, n2;

    printf("Enter size of the first array :");
    scanf("%d", &n1);

    printf("Enter size of the second array :");
    scanf("%d", &n2);

    int *arr1 = (int *)malloc(n1 * sizeof(int));
    int *arr2 = (int *)malloc(n2 * sizeof(int));

    Input(arr1, n1);
    Input(arr2, n2);
    merge_sort(arr1, n1, arr2, n2);

    // Print_Array(arr1, n1);
    // Print_Array(arr2, n2);

    return 0;
}