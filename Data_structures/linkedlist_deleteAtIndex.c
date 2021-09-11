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

struct Node *Delete_At_Index(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *q = ptr->next;
    int i = 0;
    while (i != index - 1)
    {
        i++;
        ptr = ptr->next;
        q = q->next;
    }

    ptr->next = q->next;
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
    head = Delete_At_Index(head, 1);
    traverse(head);

    return 0;
}