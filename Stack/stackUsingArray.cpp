#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
    int size;
    int top;
    int *S;
    public:
    void Push(int x)
    {
        if(top == size - 1)
        cout<<"The Stack is full";
        else
        {
            top++;
            S[top] = x;
        }
    }
    void Pop()
    {
        if(top != -1)
        {
            top--;
        }
    }
};
int main()
{
    Stack st;
    cout<<"Enter the size of the stack : ";
    cin>>st.size;
    st.S = new int[st.size];
    st.top = -1;
    cout<<"Enter the element of the stack : ";
    for(int i = 0; i < st.size; i++)
    {
        int x;
        cin>>x;
        st.Push(x);
    }
    cout<<"Elements of the stack are : ";
    for(int i = 0; i < st.size; i++)
    cout<<st.S[i]<<" ";
    return 0;
}