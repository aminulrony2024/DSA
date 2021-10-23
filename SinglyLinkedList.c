#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}Node;
Node *head = NULL;

Node *create_node(int data, Node *link)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> link = link;
    return new_node;
}
void prepend()
{
    int value;
    printf("\n\n\nEnter the value which you want to add in the beginning of the node : ");
    scanf("%d",&value);
    Node *new_node = create_node(value,head);
    if(head == NULL)
    {
        printf("Linked list is empty.\n");
    }
    head = new_node;
}

void append()
{
    int value;
    printf("\n\n\nEnter the value which you want to add : ");
    scanf("%d",&value);
    Node *new_node = create_node(value,NULL);
    if(head == NULL)
    {
        printf("The linked list is empty.\n");
    }
    Node *ptr  = NULL;
    ptr = head;
    while(ptr -> link != NULL)
    {
        ptr = ptr -> link;
    }
    ptr -> link = new_node;
}
void print_value()
{
    int count = 0;
    Node *ptr = NULL;
    ptr = head;
    printf("\n\n\nElements of the Linked list are : ");
    while(ptr != NULL)
    {
        printf("%d ",ptr -> data);
        ptr = ptr -> link;
        count++;
    }
    printf("\nTotal node of the linked list = %d\n\n\n\n\n",count);
}
void insert()
{
    int value,pos;
    printf("\n\n\nEnter the position in which you want to add the value : ");
    scanf("%d",&pos);
    printf("Enter the value which you want to add in a certain position :");
    scanf("%d",&value);
    Node *ptr = NULL;
    ptr = head;
    while(pos != 2)
    {
        ptr = ptr -> link;
        pos--;
    }
    Node *new_node = create_node(value,ptr -> link);
    ptr -> link = new_node;
}

void delete_first()
{
    Node *ptr = NULL;
    ptr = head -> link;
    free(head);
    head = ptr;
}

void delete_last()
{
    Node *ptr;
    ptr = head;
    if(head == NULL)
    {
        printf("The linked list is empty.\n");
    }
    else if(head -> link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while(ptr -> link -> link != NULL)
        {
            ptr = ptr -> link;
        }
        free(ptr->link);
        ptr -> link = NULL;
    }
}

void delete_any()
{
    int pos;
    printf("Enter the position which you want to delete : ");
    scanf("%d",&pos);
    Node *ptr = NULL;
    ptr = head;
    if(ptr == NULL)
    {
        printf("The node is empty.\n");
    }
    else if(pos == 1)
    {
        head = ptr -> link; 
        free(ptr);
        ptr = NULL;
    }
    else
    {
        while(pos != 2)
        {
            ptr = ptr -> link;
            pos--;
        }
        Node *temp = ptr -> link;
        ptr -> link = ptr -> link -> link;
        free(temp);
        temp = NULL;
    }
}

void delete_whole()
{
    Node *temp = head;
    while(temp != NULL)
    {
        temp = temp -> link;
        free(head);
        head = temp;
    }
}
void reverse()
{
    Node *next, *prev;
    next = prev = NULL;
    while(head != NULL)
    {
        next = head -> link;
        head -> link = prev;
        prev = head;
        head = next;
    }
    head = prev;
}

void create()
{
    Node *temp = NULL;
    int x;
    printf("\nHow many node's you want to add : ");
    scanf("%d",&x);
    printf("Enter value's of the node :");
    for(int i = 0; i < x; ++i)
    {
        int value;
        printf("\nEnter %d th value : ",i+1);
        scanf("%d",&value);
        if(head == NULL)
        {
            head = create_node(value,NULL);
            temp = head;
        }
        else
        {
            Node *new_node = create_node(value,NULL);
            temp -> link = new_node;
            temp = temp -> link;
        }
    }
}


int main()
{
    int n;
    do
    {
        printf("\n\n1.Create the linked list.\n");
        printf("2.Add node in the beginning.\n");
        printf("3.Add node at a certain position.\n");
        printf("4.Add node in the last.\n");
        printf("5.Display the element's of the linked list.\n");
        printf("6.Delete the first node.\n");
        printf("7.Delete the last node.\n");
        printf("8.Delete node from anywhere.\n");
        printf("9.Delete the whole linked list.\n");
        printf("10.Reverse the linked list.\n");
        printf("11.Exit \n");
        printf("\n\nEnter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 :
            {
                create();
                break;
            }
            case 2 :
            {
                prepend();
                break;
            }
            case 3 :
            {
                insert();
                break;
            }
            case 4 :
            {
                append();
                break;
            }
            case 5 :
            {
                print_value();
                break;
            }
            case 6 :
            {
                delete_first();
                break;
            }
            case 7:
            {
                delete_last();
                break;
            }
            case 8:
            {
                delete_any();
                break;
            }
            case 9:
            {
                delete_whole();
                break;
            }
            case 10:
            {
                reverse();
                break;
            }
            case 11:
            exit(1);
        }
    } while(n != 11);
    return 0;
}