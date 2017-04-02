#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>

#define MAX 100001
#define temp 0
#define perm 1
#define infinity 100000000
#define nil -1

void dijkastra(int s);
int min_temp();
void create_graph();

	int n, m; //n- no of vertices, m- no of edges
long long pathlen[MAX];
int status[MAX];
using namespace std;

vector< vector<int> > adj;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{

		create_graph();
		int s, v;
		cin>>s>>v;

		dijkastra(s);

		if(pathlen[v] == infinity)
			cout<<"NO\n";
		else
			cout<<pathlen[v]<<endl;







	}

	return 0;
}

void create_graph()  //directed graph
{

	cin>>n>>m;

	/* Row-Wise creation of array */
    for(int i = 0; i<=n; ++i ){
        vector<int> p;       //Row-Vector
        p.resize(n);

		for(int j=0; j<=n; ++j)
			p.push_back(0);
		         //Length of Row-Vector is n
        adj.push_back(p);

    }

    for(int i=1; i<=n; ++i)
    {
    	for(int j=1; j<=n; ++j)
    		adj[i][j]= 0;
    }


	int s, d, wt;
	for(int i=1; i<=m; ++i)
	{
		cin>>s>>d>>wt;
		adj[s][d]= wt;
	}



}

void dijkastra(int s)
{
	for(int i=1; i<=n; ++i)
	{
		pathlen[i]= infinity;
		status[i]= temp;
	}

	int current;

	pathlen[s]= 0;
	while(1)
	{

		current= min_temp();
	//	cout<<current<<" ";
		if(current == nil) return;

		status[current]= perm;

		for(int i=1; i<=n; ++i)
		{
			if((adj[current][i] != 0) && (status[i] == temp)){
				if((pathlen[current]+adj[current][i]) < pathlen[i])
				{
					pathlen[i] = pathlen[current] + adj[current][i];
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

	for(int i=1; i<=n; ++i)
	{
		if((status[i] == temp) && (pathlen[i] < min))
		{
			min= pathlen[i];
			k=i;
		}
	}
	return k;
}


