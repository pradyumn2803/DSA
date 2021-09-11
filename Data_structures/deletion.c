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

void delete_number(int ptr[100], int s, int j)
{
    for (int i = j; i < s; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    s--;
    show_array(ptr, s);
}

void find_index(int ptr[100], int size, int n)
{
    int index=-1;
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == n)
        {
            index = i;
        }
    }
    if(index==-1){
        printf("element not found ");
    }
    else{
        delete_number(ptr, size, index);
    }
}
int main()
{
    int u_size, number;
    scanf("%d", &u_size);
    int *ptr = (int *)malloc(100 * sizeof(int));
    for (int i = 0; i < u_size; i++)
    {
        printf("enter element %d :", i);
        scanf("%d", &ptr[i]);
    }
    printf("Enter the number to be deleted :");
    scanf("%d", &number);
    find_index(ptr, u_size, number);
    return 0;
}