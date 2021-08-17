#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next; // self referencing structure--> structure pointing to itself
};

void linkedlist_traversal(struct Node *head)
{
    struct Node *ptr = head;
    printf("\nElements are:\n");
    // printf("%d\n",ptr->data);
    // ptr=ptr->next;
    // while (ptr != head)
    // {
    //     printf("%d\n", ptr->data);
    //     ptr = ptr->next;
    // }

    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *Insert(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *p = (struct NOde *)malloc(sizeof(struct Node));
    p->data = data;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    // ptr is pointing the last node before the head node
    p->next = head;
    ptr->next = p;

    return p;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // allocate memory for nodes in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // linking first node to the second
    head->data = 7;
    head->next = second;
    // linking second node to the third
    second->data = 45;
    second->next = third;
    // linking third node to the fourth
    third->data = 56;
    third->next = fourth;
    // linking fourth node to the head node
    fourth->data = 78;
    fourth->next = head;

    printf("Circular linked list before insertion");
    linkedlist_traversal(head);
    printf("Circular linked list after insertion");
    head = Insert(head, 32);
    linkedlist_traversal(head);
    return 0;
}