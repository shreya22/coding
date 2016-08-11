#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <cctype> //toupper, tolower
#include <vector>
#include <cstdio>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)

struct Tree{
    int data;
    int leftnode; int rightnode;
};

vector<Tree> v;
vector<int> v_preorder, v_postorder, v_inorder;

void makenode(int data)
{
    Tree temp;
    temp.data= data;
    temp.leftnode= -1;
    temp.rightnode= -1;

    v.push_back(temp);
    return;
}

void setleft(int index, int data)
{
    v[index].leftnode= v.size();

    Tree newnode;
    newnode.data= data;
    newnode.leftnode= -1;
    newnode.rightnode= -1;

    v.push_back(newnode);
    return;
}

void setright(int index, int data)
{
    v[index].rightnode= v.size();

    Tree newnode;
    newnode.data= data;
    newnode.leftnode= -1;
    newnode.rightnode= -1;

    v.push_back(newnode);
    return;
}

void insert(int data)
{
    if(v.size() == 0){
        //make a new node
        makenode(data);
        return;
    }

    int i=0;
    while(i < v.size())
    {
        if( data <= v[i].data )
            if(v[i].leftnode == -1)
            {
                setleft(i, data);
                return;
            }
            else
                i= v[i].leftnode;
        else
            if(v[i].rightnode == -1)
            {
                setright(i, data);
                return;
            }
            else
                i= v[i].rightnode;
    }
}

void preorder(int start){

    v_preorder.push_back(v[start].data);
    if(v[start].leftnode != -1)
        preorder(v[start].leftnode);
    if(v[start].rightnode != -1)
        preorder(v[start].rightnode);
}

void inorder(int start){

    if(v[start].leftnode != -1)
        inorder(v[start].leftnode);
    v_inorder.push_back(v[start].data);
    if(v[start].rightnode != -1)
        inorder(v[start].rightnode);
}


void postorder(int start){

    if(v[start].leftnode != -1)
        postorder(v[start].leftnode);
    if(v[start].rightnode != -1)
        postorder(v[start].rightnode);
    v_postorder.push_back(v[start].data);
}


int main() {

    //insert data in tree
    insert(5);
    insert(10);
    insert(3);
    insert(1);

    FOR(i, 4) cout<<v[i].data<<" ";
    cout<<endl;

    cout<<"preorder: ";
    preorder(0);
    FOR(i, v.size()) cout<<v_preorder[i]<<" ";
    cout<<endl;

    cout<<"inorder: ";
    inorder(0);
    FOR(i, v.size()) cout<<v_inorder[i]<<" ";
    cout<<endl;

    cout<<"postorder: ";
    postorder(0);
    FOR(i, v.size()) cout<<v_postorder[i]<<" ";

    return 0;
}
