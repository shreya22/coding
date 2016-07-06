#include<iostream>
#include<cstdio>

#define MAX 100
#define nil -1
#define infinity 9999;

int n;
int front= -1, rear= -1;
int adj[MAX][MAX];
int pred[MAX];
int pathlength[MAX];
int queue[MAX];

void create_graph();
void bford(int s);
void insert_queue(int v);
int del_queue();
void findpath(int s, int d);
int empty_queue();

using namespace std;
int main()
{
	create_graph();
	
	int s, v;
	cout<<endl<<"enter source vertex: ";
	cin>>s;
	
	bford(s);
	
	for(int i=0; i<n; ++i)
		cout<<i<<" "<<pred[i]<<endl;
		
/*	while(1)
	{
		cout<<"enter destination vertex(-1 to quit)";
		cin>>v;
		
		if(v==-1) break;
		
		if(v<0 || v>n)
			cout<<"this vertex dos not exist!"<<endl;
		else if(v==s)
			cout<<"source and destination vertices are same!"<<endl;
		else
			findpath(s, v);
	}
	
*/	
	return 0;
}

void create_graph()  //directed graph
{
	cout<<"enter number of vertices in graph";
	cin>>n;
	
	
	//initialising all edges to 0
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j)
		{
			adj[i][j]= 0;
		}
	}
	
	int max= n*(n-1);
	int s, d, wt;
	for(int i=0; i<max; ++i)
	{
		cout<<"enter source and destination indices, (-1, -1) to quit:";
		cin>>s>>d;
		
		if(s==-1 && d==-1) break;
		
		cout<<"enter weight fr this edge:";
		cin>>wt;
		
		if(s<0 || s>=n || d<0 || d>=n)
		{
			cout<<"invalid vertex";
			i--;
		}else{
			adj[s][d]= wt;
		}
		
	}
	
	cout<<endl;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
			cout<<adj[i][j]<<" ";
			cout<<endl;
	}
}

void bford(int s)
{
	for(int i=0; i<n; ++i)
	{
		pred[i] = nil;
		pathlength[i]= infinity;
	}
	
	pathlength[s]= 0;
	insert_queue(s);
	
	int v;
	while(!empty_queue())
	{
		v= del_queue();
		
		//terminating condition for this loop
	//	if(v==nil) return;
		
		for(int i=0; i<n; ++i)
		{
			if(adj[v][i] != 0)
			{
				if((pathlength[v] + adj[v][i]) < pathlength[i])
				{
					pathlength[i] = pathlength[v] + adj[v][i];
					pred[i] = v;
					
					insert_queue(i);
				}
			}
		}
		
	}
	
}


void insert_queue(int v)
{
	if(rear == MAX-1)
	{
		cout<<"queue overflow!";
	}
	else{
	
		if(front == -1)	
			front= 0;
		rear= rear+1;
		queue[rear] = v; //cout<<"kuch hua!";
	}
}

int del_queue()
{
	int x;
	if((front == -1) || (front > rear))
	{
		cout<<"queue underflow!";
		return 0;
	}
	
	x= queue[front];
	front= front+1;
	
	return x;
	
}

void findpath(int s, int d)
{
	int path[MAX];
	int u;
	int dis=0;
	int cnt=1; int pre;
	
	path[0] = d;
	while(d != s)
	{
		pre= pred[d];
		path[cnt] = pre;
		dis+= adj[pre][d];
		
		d= pre;
		cnt++;
	}
	
	path[cnt] = s;
	
	cout<<"shortest path is: ";
	for(int i=cnt; i>=0; --i)
		cout<<path[i]<<" ";
	cout<<endl;
	
	cout<<"shortest distance is:"<<dis;
}


int empty_queue()
{
	if((front == -1) || (front>rear))
	{
		return 1;
	}
	return 0;
}
