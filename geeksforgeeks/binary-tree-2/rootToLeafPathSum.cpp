#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int n; //global variable

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

int rootToLeafPathSum(Node *root, int sum)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data + sum == n) return 1;
        else return 0;
    }

    return rootToLeafPathSum(root->left, sum+ root->data) || rootToLeafPathSum(root->right, sum+ root->data);
}

int main() {

    Node *root= newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    n= 8;

    if(rootToLeafPathSum(root, 0)) cout<<"path found!";
    else cout<<"path not found";

    return 0;
}
