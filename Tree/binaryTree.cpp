#include <bits/stdc++.h>
using namespace std;
class Tnode
{
public:
    int data;
    Tnode *lchild;
    Tnode *rchild;
    Tnode() {}
    Tnode(int data1)
    {
        data = data1;
        lchild = nullptr;
        rchild = nullptr;
    }
};
class Node
{
public:
    Tnode *data;
    Node *next;
    Node()
    {
        next = nullptr;
        data = nullptr;
    }
};
class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = rear = nullptr;
    }
    bool isFull()
    {
        Node *new_node = new Node;
        if (new_node == NULL)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }
    void Enqueue(Tnode *new_node)
    {
        Node *temp = nullptr;
        temp->data = new_node;
        temp->next = nullptr;
        if (isFull())
        {
            cout << "Queue is full";
        }
        else
        {
            if (isEmpty())
            {
                front = rear = temp;
            }
            else
            {
                rear = temp;
            }
        }
    }
    void Dequeue()
    {
    }
};
class Tree
{
public:
    Tnode *root = nullptr;
    void createTree()
    {
        Tnode *p = nullptr;
        Tnode *t = nullptr;
        int x;
        cout << "Enter the root : ";
        cin >> x;
        root = new Tnode(x);
        Queue Q;
    }
};
int main()
{
    return 0;
}