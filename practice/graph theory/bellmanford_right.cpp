#include<iostream>
#include<cstdio>

#define MAX 100
#define nil -1
#define infinity 9999
#define t 1
#define f 0


int n;
int front= -1, rear= -1;
int adj[MAX][MAX];
int pred[MAX];
int pathlength[MAX];
int queue[MAX];
int isPresInQueue[MAX];

void initialise_queue();
void create_graph();
int bford(int s);
void insert_queue(int v);
int del_queue();
void findpath(int s, int d);
int empty_queue();


using namespace std;
int main()
{
	create_graph();
	
	int s, v, flag;
	cout<<endl<<"enter source vertex: ";
	cin>>s;
	
	flag= bford(s);
	
	if(flag == -1)
	{
		cout<<"negative cycle in graph!";
		return 0;
	}
	
//	for(int i=0; i<n; ++i)
//		cout<<i<<" "<<pred[i]<<endl;
		
	while(1)
	{
		cout<<"enter destination vertex(-1 to quit)";
		cin>>v;
		
		if(v==-1) break;
		
		if(v<0 || v>n)
			cout<<"this vertex dos not exist!"<<endl;
		else if(v==s)
			cout<<"source and destination vertices are same!"<<endl;
		else if(pathlength[v] == infinity)
			cout<<"no path from source to destination vertex!";
		else
			findpath(s, v);
	}
	
	
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

int bford(int s)
{
	for(int i=0; i<n; ++i)
	{
		pred[i] = nil;
		pathlength[i]= infinity;
		isPresInQueue[i] = f;
	}
	
	initialise_queue();
	
	pathlength[s]= 0;
	insert_queue(s);
	isPresInQueue[s]= t;
	
	int v, k=0;
	while(!empty_queue())
	{
		v= del_queue();
		isPresInQueue[v]= f;
		
		if(s==v)
			k++;
			
		if(k>n)
			return -1; //negative cycle! :(
			
					
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
					
					if(isPresInQueue[i] = f)
					{
						insert_queue(i);
						isPresInQueue[i]= t;	
					}
				}
			}
		}
		
	}
	return 1;
}

void initialise_queue()
{
	int i;
	for(i=0; i<MAX; ++i)
	{
		queue[i] = 0;
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
	int cnt=0; int pre;
	

	while(d != s)
	{
		cnt++;
		path[cnt] = d;
		pre= pred[d];
		dis+= adj[pre][d];
		
		d= pre;
		
	}
	cnt++;
	path[cnt] = s;
	
	cout<<"shortest path is: ";
	for(int i=cnt; i>1; --i)
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
