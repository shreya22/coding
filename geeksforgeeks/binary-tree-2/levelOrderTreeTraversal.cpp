#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n+1; ++i)

struct node{
    int data;
    node *left, *right;
};

node* newNode(int data){
    node *temp= new node;
    temp->data= data;
    temp->left= NULL;
    temp->right= NULL;
    return temp;
}

int max(int x, int y){
    return (x>y)?x:y;
}

int getHeight(node *root){
    if(root==NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) +1;
}

void printLevelOrderTraversal(node *root, int level)
{
    if(level == 1) {
        cout<<root->data<<" ";
        return;
    }
    printLevelOrderTraversal(root->left, level-1);
    printLevelOrderTraversal(root->right, level-1);
}

void printLevelOrder(node *root){
    int h= getHeight(root);
    FOR1(i, h) {
        printLevelOrderTraversal(root, i);
        cout<<endl;
    }
}

int main()
{
    node *root= newNode(1);
    root->left= newNode(2);
    root->right= newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    printLevelOrder(root);


    return 0;
}
