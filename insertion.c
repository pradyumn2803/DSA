#include <stdio.h>
#include <stdlib.h>

void show_array(int ptr[100], int size)
{
    printf("new array=\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", ptr[i]); //traversing
    }
}
void insert_array(int n, int j, int ptr[100], int size)
{
    for (int i = size - 1; i >= j; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[j] = n;
    size++;
    show_array(ptr, size);
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
    printf("Enter the number to be inserted :");
    scanf("%d", &number);
    printf("Enter the index :");
    scanf("%d", &index);
    if (index > 99)
    {
        printf("size limit exceeded");
    }
    else
    {
        insert_array(number, index, ptr, u_size);
    }

    return 0;
}