#include <stdio.h>
#include <stdlib.h>
int binary_search(int ptr[100], int u_size, int number, int high, int low)
{
    int mid;

    mid = (low + high) / 2;
    if (low >= high)
    {
        return -1;
    }
    if (ptr[mid] == number)
    {
        return mid;
    }
    if (ptr[mid] > number)
    {
        return binary_search(ptr, u_size, number, mid - 1, low);
    }
    if (ptr[mid] < number)
    {
        return binary_search(ptr, u_size, number, high, mid + 1);
    }
    return 0;
}

int main()
{
    int u_size, number, index, low, high;
    scanf("%d", &u_size);
    int *ptr = (int *)malloc(100 * sizeof(int));
    for (int i = 0; i < u_size; i++)
    {
        printf("enter element %d :", i);
        scanf("%d", &ptr[i]);
    }
    printf("Enter the number to be found :");
    scanf("%d", &number);
    low = 0;
    high = u_size - 1;
    index = binary_search(ptr, u_size, number, high, low);
    if (index == -1)
    {
        printf("not found");
    }
    else
    {
        printf("number founded at index %d", index);
    }
    return 0;
}