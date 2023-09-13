#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void create_BST()
{
    struct node *newnode;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d" , &n);
    printf("\nEnter the data: ");
    for(int i=0; i<n; i++)
    {
        newnode = (struct node*) malloc (sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->left = NULL;
        newnode->right = NULL;

        if (root == NULL)
        {
            root = newnode;
        }
        else 
        {
            struct node *temp = root;
            for (int j = 0; j < n; j++)
            {
                if (newnode->data < temp->data)
                {
                    if (temp->left == NULL)
                    { 
                        temp->left = newnode; 
                        break; 
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    { 
                        temp->right = newnode; 
                        break; 
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
}

void display_preorder_BST(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        display_preorder_BST(root->left);  
        display_preorder_BST(root->right);  
    }
}

void display_inorder_BST(struct node *root)
{
    if (root != NULL)
    {
        display_inorder_BST(root->left);  
        printf("%d ", root->data);  
        display_inorder_BST(root->right);  
    }
}

void display_postorder_BST(struct node *root)
{
    if (root != NULL)
    {
        display_postorder_BST(root->left);   
        display_postorder_BST(root->right); 
        printf("%d ", root->data); 
    }
}

int main()
{
    create_BST();
    
    printf("\nBinary Search Tree Preorder Traversal: ");
    display_preorder_BST(root);
    
    printf("\nBinary Search Tree Inorder Traversal: ");
    display_inorder_BST(root);
    
    printf("\nBinary Search Tree Postorder Traversal: ");
    display_postorder_BST(root);

    return 0;
}
