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

void inorder(Node *root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void mirrorTree(Node *root)
{
    if(root==NULL) return;

    Node *temp= new Node;
    temp= root->left;
    root->left= root->right;
    root->right= temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main() {

    Node *root= newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    inorder(root); cout<<endl;
    mirrorTree(root);
    inorder(root);

    return 0;
}
