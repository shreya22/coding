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

void printLevelOrderSpiral(Node *root, int level, bool flag)
{
    if(level==1) cout<<root->data;
    else {
        if(!flag){
            printLevelOrderSpiral(root->left, level-1, flag);
            printLevelOrderSpiral(root->right, level-1, flag);
        }else{
            printLevelOrderSpiral(root->right, level-1, flag);
            printLevelOrderSpiral(root->left, level-1, flag);
        }
    }
}

int getHeight(Node *root)
{
    if(root==NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right))+1;
}

int levelOrderSpiral(Node *root)
{
    bool flag=0;
    FOR1(i, getHeight(root)+1)
    {
        printLevelOrderSpiral(root, i, flag);
        flag= !flag;
    }
}

int main() {

    Node *root= newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    levelOrderSpiral(root);

    return 0;
}
