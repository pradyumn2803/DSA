#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int is_empty(struct CircularQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int is_full(struct CircularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

int Queue_top(struct CircularQueue *q)
{
    return q->arr[q->f ];
}

int Queue_bottom(struct CircularQueue *q)
{
    return q->arr[q->r];
}

void enqueue(struct CircularQueue *q, int data)
{
    if (is_full(q))
    {
        printf("Queue Overflow %d\n",data);
    }
    else
    {
        q->r = (q->r + 1) % q->size;// circular queue increment
        q->arr[q->r] = data;
        printf("The element enqueued is %d\n",q->arr[q->r]);
    }
}

void dequeue(struct CircularQueue *q)
{
    int data = -1;
    if (is_empty(q))
    {
        printf("Queue underflow\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;// circular queue increment
        data = q->arr[q->f];
        printf("The element dequeued is %d\n", data);
    }
}

int main()
{
    struct CircularQueue *q = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    q->f = q->r = 0;
    q->size = 5;
    q->arr = (int *)malloc(q->size * (sizeof(int)));

    enqueue(q, 45);
    enqueue(q, 67);
    enqueue(q, 32);
    enqueue(q, 68);

    if (is_empty(q))
    {
        printf("It is empty\n");
    }

    if (is_full(q))
    {
        printf("it is full\n");
    }

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    if (is_empty(q))
    {
        printf("It is empty\n");
    }

    if (is_full(q))
    {
        printf("it is full\n");
    }

    enqueue(q, 65);
    enqueue(q, 46);
    enqueue(q, 72);
    enqueue(q, 72);

    // q->f=0;
    // printf("top: %d\n", Queue_top(q));
    // printf("bottom: %d\n", Queue_bottom(q));

    return 0;
}