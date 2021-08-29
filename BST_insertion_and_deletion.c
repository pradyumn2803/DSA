#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void inorder(struct node *n)
{
    if (n != NULL)
    {
        inorder(n->left);
        printf("%d ", n->data);
        inorder(n->right);
    }
}

void insert(struct node *n, int key)
{
    struct node *prev = NULL;
    while (n != NULL)
    {
        prev = n;
        if (n->data == key)
        {
            printf("cannot insert %d, it is already present", key);
            return;
        }
        else if (n->data < key)
        {
            n = n->right;
        }
        else
        {
            n = n->left;
        }
    }
    struct node *new = create_node(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct node *inorderpredecessor(struct node *n)
{
    n = n->left;
    while (n->right != NULL)
    {
        n = n->right;
    }
    return n;
}

struct node *delete_node(struct node *n, int key)
{
    struct node *ipre = NULL;
    if (n == NULL)
    {
        return NULL;
    }
    if ((n->data == key) && (n->left == NULL) && (n->right == NULL))
    {
        free(n);
        return NULL;
    }

    //search for the value
    if (key < n->data)
    {
        n->left = delete_node(n->left, key);
    }

    else if (key > n->data)
    {
        n->right = delete_node(n->right, key);
    }

    //deletion stratrgy
    else
    {
        ipre = inorderpredecessor(n);
        n->data = ipre->data;
        n->left = delete_node(n->left, ipre->data);
    }
    return n;
}

int main()
{
    int key;
    struct node *p = create_node(5);
    struct node *p1 = create_node(3);
    struct node *p2 = create_node(6);
    struct node *p3 = create_node(1);
    struct node *p4 = create_node(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    printf("\n");
    // printf("Enter the number you want to insert: ");
    // scanf("%d", &key);

    insert(p, 8);
    inorder(p);
    printf("\n");


    delete_node(p, 5);

    inorder(p);
    printf("\n");
    return 0;
}


