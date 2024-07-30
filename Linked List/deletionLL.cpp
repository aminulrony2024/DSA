#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *createLinkedList()
{
    int n;
    cout << "Enter number of nodes in the linked list : ";
    cin >> n;
    cout << "Enter the nodes : ";
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *mover = head;
    for (int i = 1; i < n; ++i)
    {
        cin >> x;
        mover->next = new Node(x);
        mover = mover->next;
    }
    return head;
}
void printLinkedList(Node *head)
{
    while(head != nullptr)
    {
        cout<< head -> data<<" ";
        head = head -> next;
    }
}
Node *removeFromHead(Node *head)
{
    Node *temp = head;
    head = head -> next;
    delete temp;
    return head;
}
Node *removeLastElement(Node *head)
{
    Node *temp = head;
    if(temp == NULL || temp -> next == NULL)
    return NULL;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;
    return head;
}
int main()
{
    Node *head = createLinkedList();
    head = removeLastElement(head);
    cout<<"Element of the linked list after deleting last element : ";
    printLinkedList(head);
    return 0;
}