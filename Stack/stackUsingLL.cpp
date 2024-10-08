#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *top;

public:
    Node()
    {
        top = NULL;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
    void Display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void Push(int x)
    {
        Node *temp = top;
        top = new Node(x);
        top->next = temp;
    }
    void Pop()
    {
        if (top != NULL)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main()
{
    Node st;
    cout << "Enter the size of the stack : ";
    int n;
    cin >> n;
    int x;
    cin >> x;
    st.top = new Node(x);
    Node *temp;
    for (int i = 1; i < n; ++i)
    {
        cin >> x;
        temp = st.top;
        st.top = new Node(x);
        st.top->next = temp;
    }
    cout << "Element of the stack are : ";
    st.Display();
    cout << endl
         << "Enter new element to be inserted in the stack :";
    cin >> x;
    st.Push(x);
    cout << "Element of the stack after adding new element : ";
    st.Display();
    return 0;
}