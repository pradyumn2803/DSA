#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

void traverse(struct queue *q)
{
    printf("The array is:\n");
    // while(q->f<q->r){
    //     printf("%d\n",q->arr[(q->f)+1]);
    //     q->f++;
    // }
    // q->f = -1;

    for (int i = q->f; i < q->r; i++)
    {
        printf("%d\n", q->arr[(i) + 1]);
    }
}

int first_value(struct queue *q)
{
    return q->arr[q->f + 1];
}

int last_value(struct queue *q)
{
    return q->arr[q->r];
}

int peek(struct queue *q, int pos)
{
    return q->arr[q->f + pos];
}

int is_empty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int is_full(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (is_full(q))
    {
        printf("Queue Overflow");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    if (is_empty(q))
    {
        printf("stack underflow");
    }
    else
    {
        q->f++;
        int val = q->arr[q->f];
        return val;
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue)); // NOTE: we are using a
                                                                    //structure pointer so we are passing
                                                                    //the pointer directly in to the function
                                                                    //if we are using an object then we
                                                                    //need to pass the address of the object
    q->size = 10;
    q->r = q->f = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    int index;

    enqueue(q, 45);
    enqueue(q, 67);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 22);
    enqueue(q, 34);
    traverse(q);

    printf("First value:%d\n", first_value(q));
    printf("Last Value:%d\n", last_value(q));
    // printf("Enter the position(>0):");
    // scanf("%d",&index);
    // while(index<=0 || index >q->r){//since we are enqueueing 6 values
    //     printf("Enter the position(>0):");
    //     scanf("%d",&index);
    // }
    // printf("position %d:%d\n",index,peek(q,index));
    for (int i = 0; i < (q->r) + 1; i++)
    {
        printf("position %d:%d\n", i + 1, peek(q, i + 1));
    }

    printf("The value dequeue is %d\n", dequeue(q));
    printf("The value dequeue is %d\n", dequeue(q));
    printf("The value dequeue is %d\n", dequeue(q));
    traverse(q);

    // printf("Enter the position(>0):");
    // scanf("%d",&index);
    // while(index<=0 || index>(q->r-q->f)){// since we are dequeueing 3 values
    //     printf("Enter the position(>0):");
    //     scanf("%d",&index);
    // }
    // printf("position %d:%d\n\n",index,peek(q,index));

    for (int i = 0; i < (q->r - q->f); i++)
    {
        printf("position %d:%d\n", i + 1, peek(q, i + 1));
    }
    printf("First value:%d\n", first_value(q));
    printf("Last Value:%d\n", last_value(q));

    return 0;
}