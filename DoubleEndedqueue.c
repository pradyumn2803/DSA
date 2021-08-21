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

void enqueue_R(struct queue *q, int val)
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

void enqueue_F(struct queue *q, int val)
{
    if (is_full(q))
    {
        printf("Queue Overflow");
    }
    else
    {
        q->arr[q->f] = val;
        q->f--;
    }
}

int dequeue_R(struct queue *q)
{
    if (is_empty(q))
    {
        printf("stack underflow");
    }
    else
    {
        int val = q->arr[q->r];
        q->r--;
        return val;
    }
}

int dequeue_F(struct queue *q)
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

    enqueue_R(q, 25);
    enqueue_R(q, 65);
    enqueue_R(q, 305);
    
    traverse(q);

    printf("First value:%d\n", first_value(q));
    printf("Last Value:%d\n", last_value(q));


    // printf("The value dequeue is %d\n", dequeue_F(q));
    // printf("The value dequeue is %d\n", dequeue_F(q));
    printf("The value dequeue is %d\n", dequeue_F(q));
    enqueue_F(q, 5);
    enqueue_F(q, 75);
    enqueue_F(q, 175);
    traverse(q);
    // printf("The value dequeue is %d\n", dequeue_R(q));
    // printf("The value dequeue is %d\n", dequeue_R(q));
    printf("First value:%d\n", first_value(q));
    printf("Last Value:%d\n", last_value(q));
    printf("The value dequeue is %d\n", dequeue_R(q));
    
    traverse(q);

    printf("First value:%d\n", first_value(q));
    printf("Last Value:%d\n", last_value(q));


    return 0;
}