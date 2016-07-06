#include<iostream>
#include<cstdio>

#define MAX 100
int n;
int adj[MAX][MAX];
int queue[MAX], front= -1, rear= -1;

void insert_queue(int v);
int del_queue();
int isEmpty_queue();
int indegree(int v);
void create_graph();

using namespace std;
int main()
{
	int v, count, topo_order[MAX], indeg[MAX];
	create_graph();
	
	//find indegree of each vertex
	for(int i=0; i<n; ++i)
	{
		indeg[i]= indegree(i);
		if(indeg[i] == 0)
			insert_queue(i);
	}
	
	count=1;
	while(!isEmpty_queue())
	{
		v= del_queue();
		topo_order[count++]= v;
		
		for(int i=0; i<n; ++i)
		{
			if(adj[v][i] == 1)
			{
				indeg[i] = indeg[i]-1;
				adj[v][i]= 0;
				
				if(indeg[i] == 0)
					insert_queue(i);
			}
			
		} 
		
	}
	
	if(count < n)
	{
		cout<<"graph contains cycle!";
		return 0;
	}
	
	cout<<"vertices in topological order are: \n";
	for(int i=1; i<=n; ++i)
		cout<<topo_order[i]<<" ";
	cout<<endl;
		
	
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
	
		if(s<0 || s>=n || d<0 || d>=n)
		{
			cout<<"invalid vertex";
			i--;
		}else{
			adj[s][d]= 1;
		}
		
	}
	
	cout<<endl;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
			cout<<adj[i][j]<<" ";
			cout<<endl;
	}
}//end of create_graph()


int indegree(int v)
{
	int in_deg= 0;
	for(int i=0; i<n; ++i)
		if(adj[i][v] == 1)
			in_deg++;
			
	return in_deg;
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



int isEmpty_queue()
{
	if((front == -1) || (front>rear))
	{
		return 1;
	}
	return 0;
}
