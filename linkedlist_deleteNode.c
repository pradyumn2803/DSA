#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *Delete_Node(struct Node *head, struct Node *ptr)
{
    struct Node *p = head;
    struct Node *q = ptr;

    while (p->next != q)
    {
        p = p->next;
    }

    p->next = q->next;
    free(q);
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

    first->data = 12;
    first->next = second;

    second->data = 21;
    second->next = third;

    third->data = 32;
    third->next = NULL;

    printf("Before deletion:\n");
    traverse(head);

    printf("After deletion:\n");
    head = Delete_Node(head, second);
    traverse(head);

    return 0;
}