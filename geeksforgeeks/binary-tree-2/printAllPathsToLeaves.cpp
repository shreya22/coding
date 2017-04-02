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

void printPathsRec(Node *root, int arr[], int pathLen)
{
    if(root==NULL) return;
    arr[pathLen]= root->data;
    pathLen++;

    if(root->left == NULL && root->right==NULL){
        FOR(i, pathLen) cout<<arr[i]<<" ";
        cout<<endl;
    }
    else{
        printPathsRec(root->left, arr, pathLen);
        printPathsRec(root->right, arr, pathLen);
    }

}

void printPaths(Node *root)
{
    int path[1000];
    printPathsRec(root, path, 0);
}

int main() {

    Node *root= newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    printPaths(root);

    return 0;
}
