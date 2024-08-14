#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(){}
    Node(int data1)
    {
        data = data1;
        lchild = nullptr;
        rchild = nullptr;
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
    void Enqueue()
    {

    }
    void Dequeue()
    {

    }
    bool isFull()
    {
        Node *new_node = new Node;
        if(new_node == NULL)
        return true;
        else
        return false;
    }
    bool isEmpty()
    {
        if(front == rear)
        return true;
        else 
        return false;
    }
};
class Tree
{
    public:
    Node *root = nullptr;
    void createTree()
    {
        Node *p = nullptr;
        Node *t = nullptr;
        int x;
        cout<<"Enter the root : ";
        cin>>x;
        root = new Node(x);
        Queue Q;
    }
};
int main()
{
    return 0;
}

