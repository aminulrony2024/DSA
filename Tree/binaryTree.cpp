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
                rear->next = temp;
                rear = temp;
            }
        }
    }
    Tnode *Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is underflow" << endl;
        }
        else
        {
            if (front == rear)
            {
                Tnode *t = front->data;
                front = rear = nullptr;
                return t;
            }
            else
            {
                Tnode *t = front->data;
                Node *temp = front;
                front = front->next;
                delete temp;
                return t;
            }
        }
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
        Q.Enqueue(root);
        while (!Q.isEmpty())
        {
            p = Q.Dequeue();
            cout << "Enter the left child (enter -1 to ignore ) of " << p->data << " :";
            cin >> x;
            if (x != -1)
            {
                t = new Tnode(x);
                p->lchild = t;
                Q.Enqueue(t);
            }
            cout << "Enter the right child (enter -1 to ignore ) of " << p->data << " :";
            cin >> x;
            if (x != -1)
            {
                t = new Tnode(x);
                p->rchild = t;
                Q.Enqueue(t);
            }
        }
    }
};
int main()
{
    return 0;
}