#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int is_empty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}
int is_full(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *sp, char ch)
{
    if (is_full(sp))
    {
        printf("stack overflow!!");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = ch;
    }
}
char pop(struct stack *sp)
{
    char ch;
    if (is_empty(sp))
    {
        printf("stack underflow!!");
    }
    else
    {
        ch = sp->arr[sp->top];
        sp->top--;
    }
    return ch;
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }

    if (a == '{' && b == '}')
    {
        return 1;
    }

    if (a == '[' && b == ']')
    {
        return 1;
    }

    return 0;
}

int check_parenthesis(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (is_empty(sp))
            {
                return 0;
            }
            else
            {
                ch = pop(sp);
                if (match(ch, exp[i]) == 0)
                {
                    return 0;
                }
            }
        }
    }
    if (is_empty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{
    // char *c = "((8)*(9))";
    char *c = "({[3]*(4)})]";
    if (check_parenthesis(c))
    {
        printf("Expression is balanced");
    }
    else
    {
        printf("Expression is not balanced");
    }
    return 0;
}
