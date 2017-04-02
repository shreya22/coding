#include<iostream>
#include<cstdio>

#define MAX 100
#define nil -1
#define infinity 9999
#define temp 0
#define perm 1
struct edge
{
	int u;
	int v;
};

int n;
int adj[MAX][MAX];
int pred[MAX];
int status[MAX];
int length[MAX];

void create_graph();
void maketree(int r, struct edge tree[MAX]);
int min_temp();

using namespace std;

int main()
{
	int wt_tree= 0;
	int root;
	struct edge tree[MAX];

	create_graph();

	cout<<"enter root vertex:";
	cin>>root;

	maketree(root, tree);

	cout<<"edges to be included in spanning tree are:\n";
	for(int i=1; i<n; ++i)
	{
		cout<<tree[i].u<<" "<<tree[i].v<<endl;
		wt_tree += adj[tree[i].u][tree[i].v];
	}

	cout<<"weight of spanning tree: "<<wt_tree<<endl;



	return 0;
}


void create_graph()
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
			adj[d][s]= wt;
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

void maketree(int r, struct edge tree[MAX])
{
	int current, count=0;
	for(int i=0; i<n; ++i)
	{
		pred[i] = nil;
		length[i]= infinity;
		status[i]= temp;
	}

	length[r]= 0;
	while(1)
	{
		current= min_temp();

		if(current == nil)
		{
			if(count == n-1)
				return;
			else{
				cout<<"graph not connected, no spanning tree possible!";
				return;
			}
		}

		status[current]= perm;

		if(current != r)
		{
			count++;
			tree[count].u= pred[current];
			tree[count].v= current;
		}

		for(int i=0; i<n; ++i)
		{
			if((adj[current][i] > 0) && (status[i] == temp))
			{
				if(adj[current][i] < length[i])
				{
					pred[i]= current;
					length[i]= adj[current][i];
				}
			}
		}
	}

}


int min_temp()
{
	int min= infinity;
	int k=-1;
	for(int i=0; i<n; ++i){
		if(status[i] == temp && length[i]<min){
			min= length[i];
			k=i;
		}
	}

	return k;
}



