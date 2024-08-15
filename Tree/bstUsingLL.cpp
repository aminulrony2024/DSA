#include <bits/stdc++.h>
using namespace std;
class Tnode
{
public:
    int data;
    Tnode *lchild;
    Tnode *rchild;
    Tnode(int data)
    {
        this->data = data;
        lchild = rchild = nullptr;
    }
    void Insert(Tnode *root, int key)
    {
        Tnode *r, *t, *p;
        t = root;
        if(root == NULL)
        {
            root = new Tnode(key);
            return;
        }
        while(t)
        {
            r = t;
            if(t -> data == key)
            return;
            else if(t -> data > key)
            t = t -> lchild;
            else
            t = t -> rchild;
        }
        p = new Tnode(key);
        if(key < r -> data )
        r -> rchild = p;
        else
        r -> lchild = p;
    }
};
int main()
{
    Tnode *root = nullptr;
    return 0;
}