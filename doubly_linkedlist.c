#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedlist_traversal(struct Node *head)
{
    struct Node *ptr = head;
    printf("Traversing the linked list......\nElements from left to right:\n");
    while (ptr->next != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);

    printf("\nElements from right to left:\n");
    while (ptr->prev != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }
    printf("%d\n", ptr->data);
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

    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 45;
    second->next = third;
    second->prev = head;

    third->data = 56;
    third->next = fourth;
    third->prev = second;

    fourth->data = 78;
    fourth->next = NULL;
    fourth->prev = third;

    linkedlist_traversal(head);
    return 0;
}