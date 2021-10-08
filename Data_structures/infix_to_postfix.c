#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }

    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    return 0;
}

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
        printf("Stack overflow!!");
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
        printf("Stack underflow!!");
    }
    else
    {
        ch = sp->arr[sp->top];
        sp->top--;
    }
    return ch;
}

char stack_Top(struct stack *sp)
{
    return sp->arr[sp->top];
}

char *infix_to_postfix(char *ch)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(ch) + 1;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char)); // for push and pop
    char *postfix = (char *)malloc(sp->size * sizeof(char));

    int i = 0; // variable to traverse for infix array
    int j = 0; // variable to traverse for postfix array

    while (ch[i] != '\0')
    {
        if (isdigit(ch[i]) || isalpha(ch[i]))
        {
            postfix[j] = ch[i];
            i++;
            j++;
        }
        else
        {
            if (ch[i] == '(')
            {
                push(sp, ch[i]);
                i++;
            }
            else if (ch[i] == ')')
            {
                while (stack_Top(sp) != '(')
                {
                    postfix[j++] = pop(sp);
                }
                pop(sp);
                i++;
            }
            else if (precedence(ch[i]) > precedence(stack_Top(sp)))
            {
                push(sp, ch[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!(is_empty(sp)))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *c = (char *)malloc(1000 * sizeof(char));
    char *p = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]%*c", c);
    p = infix_to_postfix(c);
    printf("%s", p);
    return 0;
}
