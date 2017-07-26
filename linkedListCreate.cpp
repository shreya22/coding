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

struct node{
	int data;
	struct node *next;
};

node *createNode(node *head, val)
{
	node *temp= new node;
	temp->data= val;
	temp->next= NULL;

	if(head==NULL) head= temp;
	else head->next= temp;

	return head;
}

int main() {

	node *head= new node;
	head= NULL;

	int n;
	cin>>n;

	int x;
	FOR(i, n)
	{
		cin>>x;
		head= createNode(head, x);
	}

	node *tempNode= head;
	while(tempNode!=NULL)
	{
		cout<<tempNode->data<<" ";
		tempNode= tempNode->next;
	}

    return 0;
}
