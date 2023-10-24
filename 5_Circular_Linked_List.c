#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void display_linked_list() {
    struct node *temp;
    temp = head;
    if (head == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void create_linked_list(int i) {
    struct node *newnode, *temp;
    printf("\nEnter the data:\n");
    for (int j = 0; j < i; j++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = head;

        if (head == NULL) {
            head = newnode;
            newnode->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }
    display_linked_list();
}

void insert_at_beginning() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
    display_linked_list();
}

void insert_at_last() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    display_linked_list();
}

void insert_at_location(int pos) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == head) {
                printf("Invalid position!\n");
                return;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    display_linked_list();
}

void delete_from_beginning() {
    if (head == NULL) {
        printf("Circular Linked List is empty!\n");
        return;
    }
    struct node *temp;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        temp = head;
        head = head->next;
        free(temp);
    }
    display_linked_list();
}

void delete_from_last() {
    if (head == NULL) {
        printf("Circular Linked List is empty!\n");
        return;
    }
    struct node *temp, *prev;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    display_linked_list();
}

void delete_from_location(int pos) {
    if (head == NULL) {
        printf("Circular Linked List is empty!\n");
        return;
    }
    struct node *temp, *prev;
    temp = head;
    prev = NULL;
    int count = 1;
    do {
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != head && count < pos);
    if (temp == head || count < pos) {
        printf("Invalid position!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    display_linked_list();
}

void reverse_list() {
    if (head == NULL) {
        printf("Circular Linked List is empty!\n");
        return;
    }
    struct node *prev, *current, *next;
    prev = NULL;
    current = head;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    head->next = prev;
    head = prev;
    display_linked_list();
}

void concatenate_linked_lists() {
    struct node *head2 = NULL, *temp;
    int j;
    printf("\nEnter the number of nodes for the second circular linked list: \n");
    scanf("%d", &j);
    printf("\nEnter the data: \n");
    for (int k = 0; k < j; k++) 
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head2 == NULL) {
            head2 = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    if (head == NULL) {
        head = head2;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head2;
    }

    temp = head2;
    while (temp->next != head2) {
        temp = temp->next;
    }
    temp->next = head;

    display_linked_list();
}



int main() {
    int choice, i, pos;
    printf("\n--------------------------------Welcome--------------------------------\n");
    printf("This is a program to perform various operations on a circular linked list.\n");

    while (1) {
        printf("\nPress 1 to create a circular linked list.\n");
        printf("Press 2 to add a node to the beginning of the circular linked list.\n");
        printf("Press 3 to add a node to the end of the circular linked list.\n");
        printf("Press 4 to add a node to a specified location in the circular linked list.\n");
        printf("Press 5 to delete a node from the beginning of the circular linked list.\n");
        printf("Press 6 to delete a node from the end of the circular linked list.\n");
        printf("Press 7 to delete a node from a specified location in the circular linked list.\n");
        printf("Press 8 to reverse the circular linked list.\n");
        printf("Press 9 to concatenate two circular linked lists.\n");
        printf("Press 10 to exit program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nTo create a circular linked list:\n");
                printf("Enter the number of nodes you want to add: ");
                scanf("%d", &i);
                create_linked_list(i);
                break;

            case 2:
                printf("\nTo add a node to the beginning of the circular linked list:\n");
                insert_at_beginning();
                break;

            case 3:
                printf("\nTo add a node to the end of the circular linked list:\n");
                insert_at_last();
                break;

            case 4:
                printf("\nTo add a node to a specified location in the circular linked list:\n");
                printf("Enter the position where you want to insert: ");
                scanf("%d", &pos);
                insert_at_location(pos);
                break;

            case 5:
                printf("\nTo delete a node from the beginning of the circular linked list:\n");
                delete_from_beginning();
                break;

            case 6:
                printf("\nTo delete a node from the end of the circular linked list:\n");
                delete_from_last();
                break;

            case 7:
                printf("\nTo delete a node from a specified location in the circular linked list:\n");
                printf("Enter the position where you want to delete: ");
                scanf("%d", &pos);
                delete_from_location(pos);
                break;

            case 8:
                printf("\nTo reverse the circular linked list:\n");
                reverse_list();
                break;

            case 9:
                printf("\nTo concatenate two circular linked lists:\n");
                concatenate_linked_lists();
                break;

            case 10:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}
