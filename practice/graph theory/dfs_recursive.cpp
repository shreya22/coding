#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define MAX 100
#define initial 1
#define visited 2
#define finished 3
#define nil -1

int n; //no of vertices in graph
int adj[MAX][MAX];
int state[MAX]; //will cover states of all vertices

void create_graph();
void df_transversal();
void dfs(int v);

int main()
{
	
	create_graph();
	df_transversal();
	
	
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


void df_transversal()
{
	int v;
	cout<<"enter startig vertex for dfs: ";
	cin>>v;
	
	for(int i=0; i<n; ++i){
		state[i]= initial;
	}
	
	dfs(v);
}

void dfs(int v)
{
	int i;
	cout<<v;
	state[v]= visited;
	
	for(int i=0; i<n; ++i)
	{
		if((adj[v][i]==1) && (state[i] == initial))
		{
			dfs(i);
		}
	}
	state[v]= finished;
}

