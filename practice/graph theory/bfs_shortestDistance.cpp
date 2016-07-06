#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
#define nil -1

int n; //no of vertices in graph
int adj[MAX][MAX];
int state[MAX]; //will cover states of all vertices
int distance[MAX];
int pred[MAX];

void create_graph();
void bf_transversal();
void bfs(int v);

int queue[MAX], rear= -1, front=-1;

void insert_queue(int v);
int del_queue();
int empty_queue();

int main()
{
	
	create_graph();
	bf_transversal();
	
	while(1)
	{
		cout<<"print destination vertex (-1 to quit)";
		int c;
		cin>>c;
		if(c==-1) break;
		
		if(distance[v] == 9999)
		{
			cout<<"no path to destination vertex exists";
			continue;
		}
		else{
			cout<<"shortest distance is: "<<distnce[v];
		}
	}
	
	return 0;
}

void create_graph()  //directed graph
{
	cout<<"enter number of vertices in graph";
	cin>>n;
	
	
	//initialising al edges to 0
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j)
		{
			adj[i][j]= 0;
		}
	}
	
	int max= n*(n-1);
	int s, d;
	for(int i=0; i<max; ++i)
	{
		cout<<"enter source and destination indices, (-1, -1) to quit:";
		cin>>s>>d;
		
		if(s==-1 && d==-1) break;
		
		if(s<0 || s>=n || d<0 || d>=n)
		{
			cout<<"invalid vertex";
			i--;
		}else{
			adj[s][d]= 1;
		}
		
	}
	
	
}


void bf_transversal()
{
	int v;
	cout<<"enter startig vertex for bfs: ";
	cin>>v;
	
	for(int i=0; i<n; ++i){
		state[i]= initial;
		pred[v]= nil;
		distance[v]= 9999;
	}
	
	bfs(v);
}

void bfs(int v)
{
	insert_queue(v);
	state[v]= waiting;
	distance[v] = 0;
	
	while(!empty_queue())
	{
		v= del_queue();
		cout<<v;
		
		for(int i=0; i<n; ++i)
		{
			if((adj[v][i]==1) && (state[i] == initial))
			{
				insert_queue(i);
				state[i]= waiting;
				pred[i]= v;
				distance[i]= distance[v+1];
			}
		}
		
	}
}

void insert_queue(int v)
{
	if(rear == MAX-1)
	{
		cout<<"space overflow!";
	}
	else
	{
		if(front == -1)
			front = 0;
			
		rear= rear+1;
		queue[rear]= v;
	}
	
}

int del_queue()
{
	if((front == -1) || (front > rear))
	{
		cout<<"queue underflow!";
		return 0;
	}
	
	int del;
	del= queue[front];
	front++;
	
	return del;
}

int empty_queue()
{
	if((front == -1) || (front>rear))
	{
		return 1;
	}
	return 0;
}
