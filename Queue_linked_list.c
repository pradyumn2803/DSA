#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void traversal(struct Node *ptr)
{
    printf("\nElements are:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *enqueue(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue overflow\n");
    }
    else
    {
        n->data = data;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
        return r;
    }
}

int dequeue()
{
    struct Node *n = f;
    if (f==NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        f = f->next;
        int data = n->data;
        free(n);
        return data;
    }
}
int main()
{

    enqueue(34);
    enqueue(3);
    enqueue(4);
    enqueue(84);

    traversal(f);

    printf("dequeued: %d\n", dequeue());
    printf("dequeued: %d\n", dequeue());
    traversal(f);

    return 0;
}