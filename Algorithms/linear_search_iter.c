#include <stdio.h>
#include <stdlib.h>
int linear_search(int ptr[100], int u_size, int number)
{
    for (int i = 0; i < u_size; i++)
    {
        if (ptr[i] == number)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int u_size, number, index;
    scanf("%d", &u_size);
    int *ptr = (int *)malloc(100 * sizeof(int));
    for (int i = 0; i < u_size; i++)
    {
        printf("enter element %d :", i);
        scanf("%d", &ptr[i]);
    }
    printf("Enter the number to be found :");
    scanf("%d", &number);
    index = linear_search(ptr, u_size, number);
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