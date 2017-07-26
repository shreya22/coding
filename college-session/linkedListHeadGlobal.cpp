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
} *head= NULL;

void createNode(int val)
{
	node *newNode= new node;
	newNode->data= val;
	newNode->next= NULL;
	node *temp= head;

	if(temp == NULL) head= newNode;
	else {
		while(temp->next!=NULL) temp= temp->next;
		temp->next= newNode;
	}

}

int main() {

	int n;
	cin>>n;

	int x;
	FOR(i, n)
	{
		cin>>x;
		createNode(x);
	}

	node *tempNode= head;
	while(tempNode!=NULL)
	{
		cout<<tempNode->data<<" ";
		tempNode= tempNode->next;
	}

    return 0;
}
