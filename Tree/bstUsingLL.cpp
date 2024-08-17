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
    Node *InPre(Node *p)
    {
        if (p)
            while (p->rchild)
            {
                p = p->rchild;
            }
        return p;
    }
    Node *InSucc(Node *p)
    {
        if (p)
            while (p->lchild)
            {
                p = p->lchild;
            }
        return p;
    }
    Node *Delete(Node *p, int key)
    {
        Node *q;

        if (p == nullptr)
        {
            return nullptr;
        }

        if (p->lchild == nullptr && p->rchild == nullptr)
        {
            if (p == root)
            {
                root = nullptr;
            }
            delete p;
            return nullptr;
        }

        if (key < p->data)
        {
            p->lchild = Delete(p->lchild, key);
        }
        else if (key > p->data)
        {
            p->rchild = Delete(p->rchild, key);
        }
        else
        {
            if (Height(p->lchild) > Height(p->rchild))
            {
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }
            else
            {
                q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }
        return p;
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
         << "Delete a node in the bst : ";
    int v;
    cin >> v;
    T.Delete(T.getRoot(), v);
    cout << "After deleting, inorder traversal of the bst is : ";
    T.Inorder(T.getRoot());
    return 0;
}