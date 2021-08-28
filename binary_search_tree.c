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

// For a BT to be a BST the left node value must be less than the root value and the right node
//  value must be greater than the root node value.

int isBST(struct node *n)
{
    if (n == NULL)
    {
        return 1;
    }

    if (n->left != NULL && n->left->data >= n->data)
    {
        return 0;
    }

    if (n->right != NULL && n->right->data <= n->data)
    {
        return 0;
    }

    if (!isBST(n->left) || !isBST(n->right))
    {
        return 0;
    }

    return 1;
}

struct node *search(struct node *n, int key)
{
    if (n == NULL)
    {
        return NULL;
    }
    if (n->data == key)
    {
        return n;
    }
    else if (n->data < key)
    {
        return search(n->right, key);
    }
    else if (n->data > key)
    {
        return search(n->left, key);
    }
}

struct node *iter_search(struct node *n, int key)
{
    while (n != NULL)
    {
        if (n->data == key)
        {
            return n;
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

    // for a binary search tree inorder traversal is in ascending order
    inorder(p);
    printf("\n");
    printf("The function for checking the binary search tree returns %d", isBST(p));
    printf("\n");

    // for recursive search in a binary search tree
    printf("Enter the key you want to search: ");
    printf("\n");
    scanf("%d", &key);

    struct node *n = search(p, key);
    if (n != NULL)
    {
        printf("found %d using recursion", n->data);
    }
    else
    {
        printf("not found");
    }
    printf("\n");

    // for iterative search in a binary search tree
    printf("Enter the key you want to search: ");
    printf("\n");
    scanf("%d", &key);

    struct node *a = iter_search(p, key);
    if (a != NULL)
    {
        printf("found %d using iteration", a->data);
    }
    else
    {
        printf("not found");
    }
    return 0;
}