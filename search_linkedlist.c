#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next; 
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

int Find_node(struct Node* head,int element){
    struct Node* ptr = head;
    int i=0;

    while(ptr!=NULL){
        if(ptr->data==element){
            return i;
        }
        ptr=ptr->next;
        i++;
    }
    return -1;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    int a,element;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));


    head->data = 7;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 56;
    third->next = fourth;

    fourth->data = 78;
    fourth->next = NULL;

    linkedlist_traversal(head);

    printf("enter the number to be searched :");
    scanf("%d",&element);
    a=Find_node(head,element);
    if(a!=-1){
        printf("Present at index %d",a);
    }
    else{
        printf("Not Present");
    }
    return 0;
}