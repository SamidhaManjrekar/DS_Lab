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
        root = create_node(value);
        return root;
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
        return root;
    }
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

struct node* search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    
    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

struct node* find_min_node(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node* delete_node(struct node *root, int del)
{
    if (root == NULL)
    {
        return root;
    }

    if (del < root->data)
    {
        root->left = delete_node(root->left, del);
    }
    else if (del > root->data)
    {
        root->right = delete_node(root->right, del);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = find_min_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

int main()
{
    int n, val, key, choice, del;

    printf("Binary search tree operations:\n");
    while (1)
    {
        printf("\n1. Create\n");
        printf("2. Display Pre Order\n");
        printf("3. Display In Order\n");
        printf("4. Display Post Order\n");
        printf("5. Delete an element\n");
        printf("6. Search for an element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
    
                for (int i = 0; i < n; i++)
                {
                    printf("\nEnter data for node %d: ", i + 1);
                    scanf("%d", &val);
                    root = insert_node(root, val);
                }
                break;

            case 2:
                printf("\nBinary Search Tree Pre order Traversal: ");
                display_preorder_BST(root);
                printf("\n");
                break;

            case 3:
                printf("\nBinary Search Tree In order Traversal: ");
                display_inorder_BST(root);
                printf("\n");
                break;

            case 4:
                printf("\nBinary Search Tree Postorder Traversal: ");
                display_postorder_BST(root);
                printf("\n");
                break;

            case 5:
                printf("Enter the element to be deleted: ");
                scanf("%d", &del);
                struct node *del_val = search(root, del);

                if (del_val == NULL)
                {
                    printf("The element is not present in the tree.\n");
                }
                else
                {
                    root = delete_node(root, del); 
                }
                break;

            case 6:
                printf("Enter the element to be found: ");
                scanf("%d", &key);
                struct node *result = search(root, key);

                if (result != NULL)
                {
                    printf("The element %d is found.\n", key);
                }
                else
                {
                    printf("The element %d is not found.\n", key);
                }
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
