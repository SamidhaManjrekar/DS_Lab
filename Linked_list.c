#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL, *temp, *newnode, *second, *third;
    int choice;

    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the first data: ");
    scanf("%d", &head->data);
    
    second = (struct node *)malloc(sizeof(struct node));
    printf("Enter the second data: ");
    scanf("%d", &second->data);

    third = (struct node *)malloc(sizeof(struct node));
    printf("Enter the third data: ");
    scanf("%d", &third->data);

    head->link = second;
    second->link = third;
    third->link = NULL;
   
   
    temp = third;
    printf("Do you want to add more data to the node?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node)); 
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->link = NULL;

        temp->link = newnode;
        temp = newnode;

        printf("\nDo you want to add more data to the node?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

         if (choice != 1 && choice != 2)
        {
            printf("\nInvalid choice!");
            printf("\nDo you want to add more data to the node?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
        }
    
    }

    printf("\nThe linked list is: ");

    temp = head; 
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    return 0;
}
