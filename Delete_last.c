
//code to delete last element
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head=NULL, *second, *third, *fourth, *temp, *temp2; //two pointer one pointing to previous and other for current
    head = (struct node *)malloc (sizeof (struct node));
    head ->data = 45;
    second = (struct node *)malloc (sizeof (struct node));
    second ->data = 95;
    third = (struct node *)malloc (sizeof (struct node));
    third ->data = 20;
    fourth = (struct node *)malloc (sizeof (struct node));
    fourth ->data = 67;

    head ->link=second;
    second ->link=third;
    third ->link=fourth;
    fourth->link=NULL;

    printf("\nBefore deletion: ");

    temp = head; 
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\nAfter deletion: ");

    temp = head; 
    while (temp->link != NULL)
    {
        temp2=temp;
        temp = temp->link;
    }
    temp2->link=NULL;
    free(temp);

    temp = head; 
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }


    return 0;

}