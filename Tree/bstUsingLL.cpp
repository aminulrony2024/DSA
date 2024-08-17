#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int data)
    {
        this->data = data;
        lchild = rchild = nullptr;
    }
};
class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }
    Node *getRoot()
    {
        return root;
    }
    void Insert(int key)
    {
        Node *r, *t, *p;
        t = root;
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }
        while (t != nullptr)
        {
            r = t;
            if (key == t->data)
                return;
            else if (key < t->data)
            {
                t = t->lchild;
            }
            else
            {
                t = t->rchild;
            }
        }
        p = new Node(key);
        if (key < r->data)
            r->lchild = p;
        else
            r->rchild = p;
    }
    void Inorder(Node *p)
    {
        if (p)
        {
            Inorder(p->lchild);
            cout << p->data << " ";
            Inorder(p->rchild);
        }
    }
    int Height(Node *p)
    {
        int x;
        int y;
        if (p == nullptr)
        {
            return 0;
        }
        x = Height(p->lchild);
        y = Height(p->rchild);
        return x > y ? x + 1 : y + 1;
    }
};
int main()
{
    BST T;
    cout << "Total nodes of the binary search tree : ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        T.Insert(x);
    }
    cout << "In order Traversal of the binary search tree : ";
    T.Inorder(T.getRoot());
    cout << endl
         << "Height of the tree is : " << T.Height(T.getRoot());
    return 0;
}