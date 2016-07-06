#include<iostream>
#include<cstdio>

#define MAX 100
#define temp 0
#define perm 1
#define infinity 9999
#define nil -1

void findpath(int s, int v);
void dijkastra(int s);
int min_temp();
void create_graph();

int n;
int adj[MAX][MAX];
int pred[MAX];
int pathlength[MAX];
int status[MAX];
using namespace std;

int main()
{
	create_graph();
	int s, v;
	cout<<"enter source vertex: ";
	cin>>s;
	
	dijkastra(s);
	
	while(1)
	{
		cout<<"enter destination vertex (-1 to quit)";
		cin>>v;
		
		if(v==-1) break;
		if(v<0 || v>n) 
			cout<<"this vertex does not exist!"<<endl;
			
		else if(v==s)
			cout<<"source and destination vertices are same!"<<endl;
		else if(pathlength[v] == infinity)
			cout<<"no path from source to destination vertex exists!"<<endl;
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

void dijkastra(int s)
{
	int current;
	
	for(int i=0; i<n; ++i)
	{ 
		pred[i] = nil;
		pathlength[i]= infinity;
		status[i]= temp;
	}
	
	pathlength[s] = 0;
	while(1)
	{
		//search for temporary vertex with minimum pathlength
		current= min_temp();
		
	//	cout<<current<<"  "<<endl;
		
		if(current == nil)
			return;
			
		status[current]= perm;
		
		for(int i=0; i<n; ++i)
		{
	//		cout<<adj[current][i]<<" ";
			
			if((status[i]== temp) && (adj[current][i] != 0))
			{
				if((adj[current][i] + pathlength[current]) < pathlength[i])
				{
					pathlength[i]= adj[current][i] + pathlength[current];
					pred[i]= current;
				}
			}
		}
	}
}
//end of dijkastra

int min_temp()
{
	int min= infinity;
	int k= nil;
	
	for(int i=0; i<n; ++i)
	{
		if((status[i] == temp) && (pathlength[i] < min))
		{
			min= pathlength[i];
			k=i;
		}
	}
	return k;
}


void findpath(int s, int v)
{
	int u;
	int path[MAX]; //stores the shortest path
	int shortdis=0;
	int count=0;
	
	while(v!= s)
	{
		count++;
		path[count]= v;
		u= pred[v];
		shortdis+= adj[u][v];
		v= u;
	}
	
	count++;
	path[count] = s;
	
	cout<<"shortest path is: ";
	for(int i=count; i>=1; i--)
		cout<<path[i]<<" ";
	cout<<endl;
	
	cout<<"shortest distance is:"<<shortdis;	
}

