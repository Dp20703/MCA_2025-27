// 1. Write a program to create a binary search tree and perform all the operations discussed in the preceding sections.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *tree;
// functions
void create_tree(struct Node *);
struct Node *insertElement(struct Node *, int);
void preorderTraversal(struct Node *);
void inorderTraversal(struct Node *);
void postorderTraversal(struct Node *);
struct Node *findSmallestElement(struct Node *);
struct Node *findLargestElement(struct Node *);
struct Node *deleteElement(struct Node *, int);
struct Node *mirrorImage(struct Node *);
int totalNodes(struct Node *);
int totalExternalNodes(struct Node *);
int totalInternalNodes(struct Node *);
int height(struct Node *);
struct Node *deleteTree(struct Node *);

int main()
{
    int option, val;
    struct Node *ptr;
    create_tree(tree);
    do
    {
        printf("\n ******MAIN MENU******* \n");
        printf("\n1.Insert Element");
        printf("\n2.Preorder Traversal");
        printf("\n3.Inorder Traversal");
        printf("\n4.Postorder Traversal");
        printf("\n5.Find Smallest Element");
        printf("\n6.Find Largest Element");
        printf("\n7.Delete an Element");
        printf("\n8.Count the total number of nodes");
        printf("\n9.Count the total number of External nodes");
        printf("\n10.Count the total number of Internal nodes");
        printf("\n11.Determine the height of the tree");
        printf("\n12.Find the mirror image of the tree");
        printf("\n13.Delete the tree");
        printf("\n14.Exit");
        printf("\n \n Enter your option ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the value of the new node:-");
            scanf("%d", &val);
            tree = insertElement(tree, val);
            break;
        case 2:
            printf("\n The Elements of the tree are :\n");
            preorderTraversal(tree);
            break;
        case 3:
            printf("\n The Elements of the tree are :\n");
            inorderTraversal(tree);
            break;
        case 4:
            printf("\n The Elements of the tree are :\n");
            postorderTraversal(tree);
            break;
        case 5:
            ptr = findSmallestElement(tree);
            printf("\n The Smallest element of the tree is: %d ", ptr->data);
            break;
        case 6:
            ptr = findLargestElement(tree);
            printf("\n The Largest element of the tree is: %d ", ptr->data);
            break;
        case 7:
            printf("\n Enter the element to be deleted:-");
            scanf("%d", &val);
            tree = deleteElement(tree, val);
            break;
        case 8:
            printf("\n Total number of nodes are:%d ", totalNodes(tree));
            break;
        case 9:
            printf("\n Total number of External nodes are:%d ", totalExternalNodes(tree));
            break;
        case 10:
            printf("\n Total number of Internal nodes are:%d ", totalInternalNodes(tree));
            break;
        case 11:
            printf("\n The Height of the tree = %d ", height(tree));
            break;
        case 12:
            tree = mirrorImage(tree);
            break;
        case 13:
            tree = deleteTree(tree);
            break;
        case 14:
            printf("\n Exit...");
            break;
        default:
            printf("\n Invalid option!");
        }
    } while (option != 14);

    return 0;
}

// creat_tree
void create_tree(struct Node *tree)
{
    tree = NULL;
}

// insert element
struct Node *insertElement(struct Node *tree, int val)
{
    struct Node *ptr, *nodeptr, *parentptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    // struct Node *ptr = malloc(sizeof *ptr);
    if (ptr == NULL)
    {
        perror("malloc failed");
        return tree; // keep tree unchanged
    }

    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }
        if (val < parentptr->data)
        {
            parentptr->left = ptr;
        }
        else
        {
            parentptr->right = ptr;
        }
    }
    return tree;
}

// recursive aproarch
// struct Node *insertRec(struct Node *root, int val) {
//     if (root == NULL) {
//         struct Node *n = malloc(sizeof *n);
//         if (!n) { perror("malloc"); return NULL; }
//         n->data = val; n->left = n->right = NULL;
//         return n;
//     }
//     if (val < root->data) {
//         root->left = insertRec(root->left, val);
//     } else if (val > root->data) {
//         root->right = insertRec(root->right, val);
//     } // else duplicate: ignore
//     return root;
// }

// preorder traversal
void preorderTraversal(struct Node *tree)
{
    if (tree != NULL)
    {
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}
// inorder traversal
void inorderTraversal(struct Node *tree)
{
    if (tree != NULL)
    {
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}
// postorder traversal
void postorderTraversal(struct Node *tree)
{
    if (tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}

// findsmallestelement
struct Node *findSmallestElement(struct Node *tree)
{
    if ((tree == NULL) || (tree->left == NULL))
    {
        return tree;
    }
    else
    {
        return findSmallestElement(tree->left);
    }
}
// findLargestElement
struct Node *findLargestElement(struct Node *tree)
{
    if ((tree == NULL) || (tree->right == NULL))
    {
        return tree;
    }
    else
    {
        return findLargestElement(tree->right);
    }
}

// deleteElement
// struct Node *deleteElement(struct Node *tree, int val)
// {
//     struct Node *cur, *parent, *suc, *psuc, *ptr;
//     if (tree->left == NULL)
//     {
//         printf("\n Tree is empty ");
//         return tree;
//     }

//     parent = tree;
//     cur = tree->left;

//     while (cur != NULL && val != cur->data)
//     {
//         parent = cur;
//         cur = (val < cur->data) ? cur->left : cur->right;
//     }
//     if (cur == NULL)
//     {
//         printf("\n The value to be deleted is not present in the tree");
//         return (tree);
//     }
//     if (cur->left == NULL)
//     {
//         ptr = cur->right;
//     }
//     else if (cur->right == NULL)
//     {
//         ptr = cur->left;
//     }
//     else
//     {
//         psuc = cur;
//         cur = cur->left;
//         while (suc->left != NULL)
//         {
//             psuc = suc;
//             suc = suc->left;
//         }
//         if (cur == psuc)
//         {
//             suc->left = cur->right;
//         }
//         else
//         {
//             suc->left = cur->left;
//             psuc->left = suc->left;
//             suc->right = cur->right;
//         }
//         ptr = suc;
//     }
//     if (parent->left == cur)
//     {
//         parent->left = ptr;
//     }
//     else
//     {
//         parent->right = ptr;
//     }
//     free(cur);

//     return tree;
// }
// chatgpt version
/* Delete a value from BST (recursive and correct) */
struct Node *deleteElement(struct Node *root, int val)
{
    if (root == NULL)
    {
        printf("Value %d not found (tree empty or not present).\n", val);
        return NULL;
    }

    if (val < root->data)
    {
        root->left = deleteElement(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteElement(root->right, val);
    }
    else
    {
        // found node to delete
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            // two children case: find inorder successor
            struct Node *succ = findSmallestElement(root->right);
            root->data = succ->data;
            // delete successor from right subtree
            root->right = deleteElement(root->right, succ->data);
        }
    }
    return root;
}

// totalNodes
int totalNodes(struct Node *tree)
{
    if (tree == NULL)
        return 0;
    else
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}
// totalExternalNodes
int totalExternalNodes(struct Node *tree)
{
    if (tree == NULL)
        return 0;
    else if ((tree->left == NULL) && (tree->right == NULL))
    {
        return 1;
    }
    else
    {
        return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
    }
}
// totalInternalNodes
int totalInternalNodes(struct Node *tree)
{
    if ((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
    {
        return 0;
    }
    else
    {
        return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
    }
}
// height
int height(struct Node *tree)
{
    int leftHeight, rightHeight;
    if (tree == NULL)
        return 0;
    else
    {
        leftHeight = height(tree->left);
        rightHeight = height(tree->right);
        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}
// mirrorImage
struct Node *mirrorImage(struct Node *tree)
{
    struct Node *ptr;
    if (tree != NULL)
    {
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        ptr = tree->left;
        tree->left = tree->right;
        tree->right = ptr;
    }
    return tree;
};
// deleteTree
struct Node *deleteTree(struct Node *tree)
{
    if (tree != NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
    return tree;
}