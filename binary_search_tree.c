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

int main()
{
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
    return 0;
}