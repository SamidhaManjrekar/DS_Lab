#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node* create_node(int a)
{
    struct node *newnode = (struct node*) malloc (sizeof(struct node));
    newnode->data = a;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert_node(struct node *root, int value)
{
    if (root == NULL)
    {
        return create_node(value);
    }
    else 
    {
        if (value < root->data)
        {
            root->left = insert_node(root->left, value);
        }
        else
        {
            root->right = insert_node(root->right, value);
        }
    }
    return root;
}

void display_preorder_BST(struct node *root)
{
    if (root == NULL)
        return;
    
    printf("%d ", root->data);
    display_preorder_BST(root->left);  
    display_preorder_BST(root->right); 
}

void display_inorder_BST(struct node *root)
{
    if (root == NULL)
        return;
    
    display_inorder_BST(root->left);  
    printf("%d ", root->data);  
    display_inorder_BST(root->right); 
}

void display_postorder_BST(struct node *root)
{
    if (root == NULL)
        return;
    
    display_postorder_BST(root->left);   
    display_postorder_BST(root->right); 
    printf("%d ", root->data); 
}



int main()
{
    int n, val;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter data for node %d: ", i + 1);
        scanf("%d", &val);
        root = insert_node(root, val);
    }
    
    printf("\nBinary Search Tree Preorder Traversal: ");
    display_preorder_BST(root);
    
    printf("\nBinary Search Tree Inorder Traversal: ");
    display_inorder_BST(root);
    
    printf("\nBinary Search Tree Postorder Traversal: ");
    display_postorder_BST(root);
    return 0;
}
