
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data; 
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;


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
    newnode -> prev = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else 
        {
            temp -> next = newnode;
            newnode -> prev = temp;
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
    newnode -> prev = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
    newnode -> next = head; 
    head -> prev = newnode;
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
    newnode -> prev = NULL;

    temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> prev = temp;

    printf("\nThe likned list after a new node is added to the end: ");
    display_linked_list();
    printf("\n");
}

void add_to_position()
{
    struct node *newnode, *temp;
    int pos, count = 0, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    printf("\nEnter the position at which the node had to be added: ");
    scanf("%d", &pos);

    temp = head;
    if (pos > count + 1 || pos <= 0)
    {
        printf("Invalid input!!");
    }
    else
    {
        if (pos == 1)
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else
        {
            while (i < pos - 1)
            {
                i++;
                temp = temp->next;
                
            }
            newnode->prev = temp;
            newnode->next = temp->next;
            
            if (temp->next != NULL)
            {
                temp->next->prev = newnode;
            }
            temp->next = newnode;
        }

        printf("\nThe linked list after a new node is added to the given position: ");
        display_linked_list();
    }
    printf("\n");
}


void delete_from_start()
{

    struct node * temp;
    if (head == NULL)
    {
        printf ("\nList is empty!!");
    }
    else
    {
        temp = head;    
        head = head -> next;
        head -> prev = NULL;
        free (temp);
    }

    printf("\nThe linked list after deleting a node fron the start: ");
    display_linked_list();
    printf("\n");
}

void delete_from_end()
{
    struct node *temp;

    if(head == NULL)
    {   
        printf("\n Empty list");

    }
    else
    {
        temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> prev -> next = NULL;
        free(temp);
    }
    printf("\nThe linked list after deleting a node fron the start: ");
    display_linked_list();
    printf("\n");
}

void delete_from_position()
{
    struct node *temp;
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
        while (i< pos)
        {
            temp = temp -> next;
            i++;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free (temp);

    }

    printf("\nThe linked list after deleting a node fron a given position: ");
    display_linked_list();
    printf("\n");
}

void reverse_list()
{
    struct node *currentnode, *nextnode, *tail = NULL;
    currentnode = head;
    
    while (currentnode != NULL)
    {
        nextnode = currentnode->next;
        currentnode->next = currentnode->prev;
        currentnode->prev = nextnode;
        tail = currentnode;
        currentnode = nextnode;
    }
    
    head = tail;

    printf("\nThe linked list after reversing: ");
    display_linked_list();
    printf("\n");
}


void concatenate_linked_list()
{
    struct node *temp, *newnode, *head2 = NULL;
    int j;
    printf("\nTo create the second linked list: ");
    printf("\nEnter the number of nodes for the second linked list: ");
    scanf("%d", &j);
    printf("Enter data: \n");
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
        temp = head2;
        while (temp != NULL) 
        {
            temp->prev = temp;
            temp = temp->next;
        }
    }

    printf("\nThe linked list after concatenation: ");
    display_linked_list();
    printf("\n");
}

int main()
{ 
    int choice, i;
    printf("\n--------------------------------Welcome--------------------------------\n");
    printf("This is a program to perform various operations on a single linked list.\n");

    while(1) {
        printf("\nPress 1 to create a linked list.\n");
        printf("Press 2 to add a node to the beginning of the linked list.\n");
        printf("Press 3 to add a node to the end of the linked list.\n");
        printf("Press 4 to add a node to a position of your choice in the linked list.\n");
        printf("Press 5 to delete a node from the beginning of the linked list.\n");
        printf("Press 6 to delete a node from the end of the linked list.\n");
        printf("Press 7 to delete a node from a position of your choice in the linked list.\n");
        printf("Press 8 to display the linked list.\n");
        printf("Press 9 to reverse the list.\n");
        printf("Press 10 to concatenate two lists.\n");
        printf("Press 11 to exit program.\n");
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
            printf ("\nTo display the linked list :-\n");
            display_linked_list();
            break;

            case 9:
            printf("\nTo reverse the list:-");
            reverse_list();
            break;

            case 10:
            printf("To concatenate the list:-");
            concatenate_linked_list();
            break;

            case 11:
            printf("Exiting program...");
            exit(0);

            default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}
