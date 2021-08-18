#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int is_empty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int is_full(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack* s,int number){
    if(is_full(s)){
        printf("stack overflow!!!Cannot push %d into the stack\n",number);
    }
    else{
        s->top++;
        s->arr[s->top]=number;
        printf("pushed %d successfully\n",number);
    }
}

int pop(struct stack* s){
    if(is_empty(s)){
        printf("stack underflow!!!Cannot pop into the stack\n");
        exit(0);
    }
    else{
        int number=s->arr[s->top];
        s->top--;
        return number;
    }
}

int main()
{
    // struct stack s;
    // s.top=-1;
    // s.size=6;
    // s.arr=(int *)malloc(s.size*sizeof(int));

    struct stack *s;
    s->top = -1;
    s->size = 6;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Before Push\n");
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

    push(s,56);
    push(s,46);
    push(s,5);
    push(s,6);
    push(s,12);
    push(s,15);//----> last element to be pushed and first element to be poped
    push(s,79);//-----> stack overflow!!
    
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

    printf("poped %d successfully\n ",pop(s));
    printf("poped %d successfully\n ",pop(s));
    printf("poped %d successfully\n ",pop(s));
    printf("poped %d successfully\n ",pop(s));
    printf("poped %d successfully\n ",pop(s));
    printf("poped %d successfully\n ",pop(s));
    printf("poped %d successfully\n ",pop(s));//-->stack underflow!!
    


    return 0;
}