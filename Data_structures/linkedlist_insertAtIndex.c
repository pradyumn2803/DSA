#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *Insert_At_Index(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    int i = 0;
    while (i != index - 1)
    {
        i++;
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = first;

    first->data = 11;
    first->next = second;

    second->data = 45;
    second->next = third;

    third->data = 67;
    third->next = NULL;

    printf("before insertion:\n");
    traversal(head);

    printf("\nafter insertion:\n");
    head = Insert_At_Index(head, 3, 3);
    traversal(head);

    return 0;
}