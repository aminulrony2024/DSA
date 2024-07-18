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
Node *removeFromHead(Node *head)
{
    Node *temp = head;
    head = head -> next;
    delete temp;
    return head;
}
int main()
{
    Node *head = createLinkedList();
    head = removeFromHead(head);
    Node *node = head;
    cout << "Elements of the Linked List after removing from head are : ";
    while(node != nullptr)
    {
        cout<< node -> data<<" ";
        node = node -> next;
    }
    return 0;
}