#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *node= new Node;
    node->data= data;
    node->left= NULL;
    node->right= NULL;
    return node;
}

bool checkForChildrenSumProp(Node *root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
    if((root->data == ((root->left==NULL)?0:root->left->data + (root->right==NULL)?0:root->right->data))
        && checkForChildrenSumProp(root->left) && checkForChildrenSumProp(root->right))
            return true;

    else return false;
}

int main() {

    Node *root= newNode(10);
    root->left= newNode(8);
    root->right= newNode(2);
    root->left->left=newNode(3);
    root->left->right=newNode(5);
    root->right->left=newNode(2);
    root->right->right=newNode(2);

    if(checkForChildrenSumProp(root)) cout<<"children sum property followed!\n";
    else cout<<"property not followed!\n";

    return 0;
}
