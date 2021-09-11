#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// struct Node* top= NULL; ------> if we declare it globally then we dont have to pass the address of 
// the top in the pop function as the changes are made globally.

void traversal(struct Node *ptr)
{
    printf("The elements are:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int Is_Empty(struct Node *top)
{
    if (top == NULL) // if the first element is NULL then return True which means it is empty
    {
        return 1;
    }
    return 0;
}

int Is_Full(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));// if the heap section of the ram is 
    //unable to allocate memory then the linked kist is full and it returns true. 
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *top, int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (Is_Full(top))
    {
        printf("Stack overflow!!");
    }
    else
    {
        n->data = data;
        n->next = top;
        top = n;
    }

    return top;
}

int pop(struct Node **top)// if we declare top locally then we have to pass the address since the 
   //changes made in push is not reflected
{
    if (Is_Empty((*top)))
    {
        printf("stack underflow!!");
    }
    else
    {
        struct Node *n = (*top);
        int number = n->data;
        (*top) = (*top)->next;
        free(n);
        return number;
    }
}

// int pop(struct Node* tp){ // if we declare top globally then we dont have to pass the 
// address as changes made is made in the global variable
//     if(Is_Empty(tp)){
//         printf("stack underflow!!");
//     }
//     else{
//         struct Node* n = tp;
//         int number = n->data;
//         top=tp->next;
//         free(n);
//         return number;
//     }
// }

int peek(struct Node *top, int index)
{
    struct Node *n = top;
    for (int i = 0; (i < index - 1 && n != NULL); i++)
    {
        n = n->next;
    }
    if (n != NULL)
    {
        return n->data;
    }
    else
    {
        return -1;
    }
}

int stack_top(struct Node *top)
{
    return top->data;
}

int stack_bottom(struct Node *top)
{
    struct Node *n = top;
    while (n->next != NULL)
    {
        n = n->next;
    }
    return n->data;
}

int main()
{
    // here top refers to head that we use in linked list.
    struct Node *top = NULL;
    int i = 0, n, number;
    printf("Enter the size ");
    scanf("%d", &n);

    while (i < n)
    {
        printf("Enter number %d",i+1);
        scanf("%d", &number);
        top = push(top, number);
        i++;
    }
    traversal(top);

    printf("\nnumber poped out is %d\n", pop(&top));// in case of pop we are passing the 
    // address of the structure pointer because the value returned by pop function will 
    // be the element to be deleted hence we wouldn't be able to update the structure pointer
    // .(for local declaration).
    // printf("\nnumber poped out is %d\n",pop(top)); // for global declaration
    traversal(top);

    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("postion %d is %d\n", i, peek(top, i));
    }

    printf("\nTop element is %d\n", stack_top(top));
    printf("Bottom element is %d\n", stack_bottom(top));
    return 0;
}