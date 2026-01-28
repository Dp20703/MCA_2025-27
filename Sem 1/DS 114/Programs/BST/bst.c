/* bst.c
   Recursive BST insert, search, and display.
*/

#include <stdio.h>
#include <stdlib.h>

// bst structure
struct Node
{
    int data;
    struct Node *left, *right;
};

// create a newNode
struct Node *newNode(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

/* Recursive insert into BST */
struct Node *insertBST(struct Node *root, int val)
{
    if (root == NULL)
    {
        return newNode(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }

    return root;
}

/* Recursive search: returns pointer to node or NULL */
struct Node *searchBST(struct Node *root, int val)
{

    if (root == NULL)
        return NULL;

    if (root->data == val)
    {
        return root;
    }

    if (val < root->data)
    {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}

/* Inorder (sorted output) */
void inorder(struct Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* Preorder */
void preorder(struct Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* Postorder */
void postorder(struct Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* Free tree */
void freeTree(struct Node *root)
{
    if (!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main()
{
    struct Node *root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    // find length
    int n = sizeof(values) / sizeof(values[0]);

    // insertion
    for (int i = 0; i < n; i++)
    {
        root = insertBST(root, values[i]);
    }
    /// Traversal
    printf("BST inorder (should be sorted): ");
    inorder(root);
    printf("\n");

    printf("BST preorder: ");
    preorder(root);
    printf("\n");

    printf("BST postorder: ");
    postorder(root);
    printf("\n\n");

    // Searching
    int x = 60;
    struct Node *found = searchBST(root, x);

    if (found)
        printf("Element %d found in BST.\n", x);
    else
        printf("Element %d NOT found in BST.\n", x);

    x = 25;
    found = searchBST(root, x);
    if (found)
        printf("Element %d found in BST.\n", x);
    else
        printf("Element %d NOT found in BST.\n", x);

    // freeTree
    freeTree(root);

    return 0;
}