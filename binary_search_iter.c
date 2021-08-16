#include <stdio.h>
#include <stdlib.h>
int binary_search(int ptr[100], int u_size, int number)
{
    int low = 0, high = u_size - 1, mid;

    for (int i = low; i < high; i++)
    {
        mid=(low+high)/2;
        if(ptr[mid]==number){
            return mid;
        }
        else if (ptr[mid]>number)
        {
            high=mid-1;
        }
        else if (ptr[mid]<number)
        {
            low=mid+1;
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
    index = binary_search(ptr, u_size, number);
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