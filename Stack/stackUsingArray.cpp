#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
    int size;
    int top;
    int *S;
};
int main()
{
    Stack st;
    cout<<"Enter the size of the stack : ";
    cin>>st.size;
    st.S = new int[st.size];
    st.top = -1;
    return 0;
}