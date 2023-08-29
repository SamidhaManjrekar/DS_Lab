
//ode to delete the first node

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head=NULL, *second, *third, *temp;
    head = (struct node *)malloc (sizeof (struct node));
    head ->data = 45;
    second = (struct node *)malloc (sizeof (struct node));
    second ->data = 95;
    third = (struct node *)malloc (sizeof (struct node));
    third ->data = 20;

    head ->link=second;
    second ->link=third;
    third ->link=NULL;

    printf("Before deletion: ");

    temp = head; 
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\nAfter deletion: ");

    head = head -> link;
    free (temp);

    temp = head; 
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    return 0;

}