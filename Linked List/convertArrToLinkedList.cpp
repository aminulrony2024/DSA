#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node
{
public:
    ll data;
    Node *next;
    Node(ll data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertArray2LL(vector<ll> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (ll i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int main()
{
    vector<ll> arr = {5, 9, 8, 2};
    Node *head = convertArray2LL(arr);
    Node *node = head;
    cout<<"Elements of the linked list : ";
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
    return 0;
}