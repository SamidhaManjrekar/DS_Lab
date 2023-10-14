#include <stdio.h> 
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head = NULL;


void display_linked_list()
{
    struct node *temp;
    temp = head;
    while (temp!= NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

void create_linked_list(int i)
{
    struct node *newnode, *temp;
    printf("\nEnter the data: \n");
    for(int j=0; j<i; j++)
    {
    newnode = (struct node*) malloc (sizeof(struct node));
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else 
        {
            temp -> next = newnode;
            temp = newnode;
        }

    }
    printf("\nThe linked list created: ");
    display_linked_list();
    printf("\n");
}

void add_to_start()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;

    if(head==NULL)
    {
        head = newnode;
    }
    else 
    {
        newnode -> next = head;
        head = newnode;
    }
    printf("\nThe likned list after a new node is added to the beginning: ");
    display_linked_list();
    printf("\n");
}

void add_to_end()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf ("\nEnter the data: ");
    scanf ("%d", &newnode -> data);
    newnode -> next = NULL;

    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;
        temp = newnode;

    }
    printf("\nThe likned list after a new node is added to the end: ");
    display_linked_list();
    printf("\n");
}

void add_to_position()
{
    struct node *newnode, *temp;
    int pos, count=0, i=1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf ("\nEnter the data: ");
    scanf ("%d", &newnode -> data);
    newnode -> next = NULL;

    temp = head;
    while (temp != NULL)
    {
        temp = temp -> next;
        count ++;
    }

    printf ("\nEnter the position at which the node had to be added: ");
    scanf ("%d", &pos);

    temp = head;
    if (pos>count || pos<= 0)
    {
        printf ("Invalid input!!");
    }
    else 
    {
        while (i< pos-1)
        {
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
        printf("\nThe linked list after a new node is added to the give position: ");
        display_linked_list();
    }
    printf("\n");
}

void delete_from_start()
{
    struct node *temp;

    if (head == NULL)
    {
        printf ("\nList is empty!!");
    }
    else
    {
        temp = head;    
        head = head -> next;
        free (temp);
    }

    printf("\nThe linked list after deleting a node fron the start: ");
    display_linked_list();
    printf("\n");
}

void delete_from_end()
{
    struct node *temp, *tempprev;

    if (head == NULL)
    {
        printf("\nList is empty!!");
    }

    temp = head;
    tempprev = NULL;

    while (temp->next != NULL)
    {
        tempprev = temp;
        temp = temp->next;
    }

    if (tempprev == NULL) 
    {
        head = NULL;
    }
    else
    {
        tempprev->next = NULL;
    }

    free(temp);

    printf("\nThe linked list after deleting a node from the end: ");
    display_linked_list();
    printf("\n");
}


void delete_from_position()
{
    struct node *temp, *tempnext;
    int count = 0, pos, i=1;
    temp = head;
    while (temp != NULL)
    {
        temp = temp -> next;
        count ++;
    }

    printf ("\nEnter the position from which the node had to be deleted: ");
    scanf ("%d", &pos);

    temp = head;
    if (pos>count || pos<= 0)
    {
        printf ("Invalid input!!");
    }
    else 
    {
        while (i< pos-1)
        {
            temp = temp -> next;
            i++;
        }
        tempnext = temp -> next;
        temp -> next = tempnext -> next;
        free (tempnext);
    }

    printf("\nThe linked list after deleting a node fron a given position: ");
    display_linked_list();
    printf("\n");
}

void reverse_list()
{
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = NULL;
    currentnode = head;

    while (currentnode != NULL)
    {
        nextnode = currentnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;

    printf("\nThe linked list after reversing: ");
    display_linked_list();
    printf("\n");
}


void concatenate_linked_list()
{
    struct node *head2 = NULL, *temp, *newnode;
    int j;
    printf("\nEnter the number of nodes for the second linked list: \n");
    scanf("%d", &j);
    printf("\nEnter the data: \n");
    for (int k = 0; k < j; k++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head2 == NULL)
        {
            head2 = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    if (head == NULL)
    {
        head = head2;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
    }

    printf("\n\nThe linked list after concatenation: ");
    display_linked_list();
    printf("\n");
}


int main()
{ 
    int choice, i;
    printf("\n--------------------------------Welcome--------------------------------\n");
    printf("This is a program to perform various operations on a single linked list.\n");

    while (1) {
        printf("\nPress 1 to create a linked list.\n");
        printf("Press 2 to add a node to the beginning of the linked list.\n");
        printf("Press 3 to add a node to the end of the linked list.\n");
        printf("Press 4 to add a node to a position of your choice in the linked list.\n");
        printf("Press 5 to delete a node from the beginning of the linked list.\n");
        printf("Press 6 to delete a node from the end of the linked list.\n");
        printf("Press 7 to delete a node from a position of your choice in the linked list.\n");
        printf("Enter 8 to reverse the list.\n");
        printf("Enter 9 to concatenate two lists.\n");
        printf("Enter 10 to exit program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("\nTo create a linked list:\n");
            printf("Enter the number of nodes you want to add: ");
            scanf("%d",&i);
            create_linked_list(i);
            break;

            case 2:
            printf ("\nTo add a node to the beginning of the linked list :-\n");
            add_to_start();
            break;
            case 3:
            printf ("\nTo add a node to the end of the linked list :-\n");
            add_to_end();
            break;

            case 4:
            printf ("\nTo add a node to a position of your choice in the linked list :-\n");
            add_to_position();
            break;

            case 5:
            printf ("\nTo delete a node from the beginnning of the linked list :-\n");
            delete_from_start();
            break;

            case 6:
            printf ("\nTo delete a node from the end of the linked list :-\n");
            delete_from_end();
            break;

            case 7:
            printf ("\nTo delete a node from a position of your choice in the linked list :-\n");
            delete_from_position();
            break;

            case 8:
            printf("\nTo reverse the list:-");
            reverse_list();
            break;

            case 9:
            printf("To concatenate the list:-");
            concatenate_linked_list();
            break;
            
            case 10:
            printf("Exiting program...");
            exit (0);

            default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}
