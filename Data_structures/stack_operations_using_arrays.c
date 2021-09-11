#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int is_empty(struct stack *s) // time complexity is O(1)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int is_full(struct stack *s) // time complexity is O(1)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, int number) // time complexity is O(1)
{
    if (is_full(s))
    {
        printf("stack overflow!!!Cannot push %d into the stack\n", number);
    }
    else
    {
        s->top++;
        s->arr[s->top] = number;
        printf("pushed %d successfully\n", number);
    }
}

int pop(struct stack *s) // time complexity is O(1)
{
    if (is_empty(s))
    {
        printf("stack underflow!!!Cannot pop into the stack\n");
        exit(0);
    }
    else
    {
        int number = s->arr[s->top];
        s->top--;
        return number;
    }
}

int peek(struct stack *s, int index) // time complexity is O(1)
{
    int array_index = s->top - index + 1;
    if (array_index < 0)
    {
        printf("Index value less than 0\n");
    }
    else
    {
        return s->arr[array_index];
    }
}

int stack_top(struct stack *s)  // time complexity is O(1)
{ 
    return s->arr[s->top];
}

int stack_bottom(struct stack *s)  // time complexity is O(1)
{ 
    return s->arr[0];
}

int main()
{
    // struct stack s;
    // s.top=-1;
    // s.size=6;
    // s.arr=(int *)malloc(s.size*sizeof(int));

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 6;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Before Push\n");
    printf("\n");
    if (is_empty(s))
    {
        printf("It is Empty\n");
    }
    else
    {
        printf("It is not empty\n");
    }

    if (is_full(s))
    {
        printf("It is Full\n");
    }
    else
    {
        printf("It is not full\n");
    }

    push(s, 56);
    push(s, 46);
    push(s, 5);
    push(s, 6);
    push(s, 12);
    push(s, 15); //----> last element to be pushed and first element to be poped
    push(s, 79); //-----> stack overflow!!

    printf("\nAfter Push\n");
    if (is_empty(s))
    {
        printf("It is Empty\n");
    }
    else
    {
        printf("It is not empty\n");
    }

    if (is_full(s))
    {
        printf("It is full\n");
    }
    else
    {
        printf("It is not full\n");
    }

    printf("\n");
    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("element at position %d is %d\n", i, peek(s, i));
    }

    printf("\n%d is the top value\n", stack_top(s));
    printf("%d is the bottom value\n", stack_bottom(s));

    printf("poped %d successfully\n", pop(s)); //------> last in first out
    printf("poped %d successfully\n", pop(s));
    printf("poped %d successfully\n", pop(s));
    printf("poped %d successfully\n", pop(s));
    printf("poped %d successfully\n", pop(s));
    printf("poped %d successfully\n", pop(s));
    printf("poped %d successfully\n", pop(s)); //-->stack underflow!!

    return 0;
}