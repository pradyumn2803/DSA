#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next; // self referencing structure--> structure pointing to itself
};

void linkedlist_traversal(struct Node *ptr)
{
    printf("Traversing the linked list......\nElements are:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
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
    // linking fourth node to the NULL(end of the list)
    fourth->data = 78;
    fourth->next = NULL;

    linkedlist_traversal(head);
    return 0;
}