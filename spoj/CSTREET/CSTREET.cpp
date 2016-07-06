#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define MAX 1001
#define nil -1


struct edge{
		int u;
		int v;
		int wt;
		struct edge *link;
	
} *front= NULL;

void makedge(int m);
void insert_pque(int s, int v, int len);
void kruskals();
struct edge *del_pque();
int isEmpty_pque();

	int n;  //no of vertices
	int m;  //no of edges
	long int total;

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int p; //price to cobble each street
		cin>>p;

		cin>>n;
		
		cin>>m;
		total= 0;
		makedge(m); 
		//edges taken input and inserted in priority queue
		
		kruskals();
		
		cout<<total*p<<endl;
	}
	
	return 0;
}

void makedge(int m)
{
	int s, v, len;
	struct edge *t;
	t= new edge;
	
	for(int i=0; i<m; ++i)
	{
		cin>>s>>v>>len;
		insert_pque(s, v, len);
			
	}
	
/*		t= front;
		while(t->link != NULL)
		{
			cout<<t->wt<<" ";
			t= t->link;
		}
		cout<<t->wt<<" ";
		
*/
}

void insert_pque(int s, int v, int len)
{	
	struct edge *tmp, *q;
	tmp= new edge;
	q= new edge;

	tmp->u= s;
	tmp->v= v;
	tmp->wt= len;
	
//	cout<<tmp->u<<" "<<tmp->v<<" "<<tmp->wt<<endl;
	
	if((front == NULL) || (len< front->wt))
	{
		tmp->link= front;
		front=tmp;
	}
	else
	{
		q= front;
	
		while((q->link != NULL) && (q->link->wt < len))
		{
			q= q->link;
		}
		
		tmp->link= q->link;	
		q->link= tmp;
		
	
	}
	
}


void kruskals()
{
	struct edge *tmp;
	int v1, v2, root_v1, root_v2;
	
	int father[n];
	int count=0;
	
	for(int i=0; i<n; ++i)
		father[i]= nil;
		
	while(!isEmpty_pque())
	{
		tmp= del_pque();
		v1= tmp->u;
		v2= tmp->v;
		
		//cout<<v1<<" "<<v2<<endl;
		
		while(v1 != nil)
		{
			root_v1= v1;
			v1= father[v1];
		}
		
		while(v2 != nil)
		{
			root_v2= v2;
			v2= father[v2];
		}
		
		if(root_v1 != root_v2)
		{
		//	insert_pque(v1, v2, tmp->wt);
			father[root_v2] = root_v1;
			
			total+= tmp->wt;
		}
		

	}	
	
//	cout<<"over";
}


struct edge *del_pque()
{
	struct edge *tmp;
	tmp= front;
	
	front= front->link;
	return tmp;
}


int isEmpty_pque()
{
	if(front == NULL)
		return 1;
	return 0;
}
