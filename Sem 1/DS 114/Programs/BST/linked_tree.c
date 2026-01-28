/* linked_tree.c
   Binary tree using pointers. Includes:
   - manual construction of left-skewed, right-skewed, complete
   - recursive traversals: pre-order, in-order, post-order
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node *left, *right;
};

struct Node *newNode(int val)
{
   struct Node *n = (struct Node *)malloc(sizeof(struct Node));
   n->data = val;
   n->left = n->right = NULL;
   return n;
}

/* Traversals */
void preorder(struct Node *root)
{
   if (!root)
      return;
   printf("%d ", root->data);
   preorder(root->left);
   preorder(root->right);
}
void inorder(struct Node *root)
{
   if (!root)
      return;
   inorder(root->left);
   printf("%d ", root->data);
   inorder(root->right);
}
void postorder(struct Node *root)
{
   if (!root)
      return;
   postorder(root->left);
   postorder(root->right);
   printf("%d ", root->data);
}

/* Helper to free tree */
void freeTree(struct Node *root)
{
   if (!root)
      return;
   freeTree(root->left);
   freeTree(root->right);
   free(root);
}

/* Build examples */
struct Node *build_left_skewed()
{ // 1 -> 2 -> 3 -> 4 (each node is left child)
   struct Node *root = newNode(1);
   root->left = newNode(2);
   root->left->left = newNode(3);
   root->left->left->left = newNode(4);
   return root;
}
struct Node *build_right_skewed()
{ // 10 -> 20 -> 30 (right children)
   struct Node *root = newNode(10);
   root->right = newNode(20);
   root->right->right = newNode(30);
   return root;
}
struct Node *build_complete()
{ // 1..7 as a perfect tree
   struct Node *n1 = newNode(1);
   n1->left = newNode(2);
   n1->right = newNode(3);
   n1->left->left = newNode(4);
   n1->left->right = newNode(5);
   n1->right->left = newNode(6);
   n1->right->right = newNode(7);
   return n1;
}

int main()
{
   struct Node *root;

   printf("Linked-list representation + traversals\n\n");

   root = build_left_skewed();
   printf("Left-skewed tree preorder: ");
   preorder(root);
   printf("\n");
   printf("Left-skewed tree inorder: ");
   inorder(root);
   printf("\n");
   printf("Left-skewed tree postorder: ");
   postorder(root);
   printf("\n\n");
   freeTree(root);

   root = build_right_skewed();
   printf("Right-skewed tree preorder: ");
   preorder(root);
   printf("\n");
   printf("Right-skewed tree inorder: ");
   inorder(root);
   printf("\n");
   printf("Right-skewed tree postorder: ");
   postorder(root);
   printf("\n\n");
   freeTree(root);

   root = build_complete();
   printf("Complete tree preorder: ");
   preorder(root);
   printf("\n");
   printf("Complete tree inorder: ");
   inorder(root);
   printf("\n");
   printf("Complete tree postorder: ");
   postorder(root);
   printf("\n");
   freeTree(root);

   return 0;
}
