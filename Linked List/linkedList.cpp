#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Node {
    public:
    ll data;
    Node* next;
    Node(ll data1)
    {
        data = data1;
        next = nullptr;
    }
};
int main()
{
    vector<ll> arr = {5,9,8,2};
    Node* y = new Node(arr[0]);
    cout<<y -> data<<endl;
}