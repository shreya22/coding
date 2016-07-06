#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define MAX 100001

int pathlen[MAX];
int adj[MAX];
int n;
int cnt=1;

void creategraph();
void dfs(int s);

using namespace std;
vector< vector<int> > A;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
	
	/* Row-Wise creation of array */    
    for(int i = 0; i<n; ++i ){
        vector<int> p;       //Row-Vector       
        p.resize(n);            //Length of Row-Vector is n
        A.push_back(p);         
    }

	creategraph();
	
	dfs(0);
	for(int i=0; i<n; ++i)
	{
		if(pathlen[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
	}
	
	return 0;
}

void creategraph()
{
	for(int i=0; i<n; ++i)
	{
		pathlen[i]= 0;
	}
	
	 for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            A[i][j]=0;
        }
    }
    

	int e;
	cin>>e;
	
	int s, v; //source and vertex
	while(e--)
	{
		scanf("%d%d", &s, &v);
		A[s][v]= 1;
		A[v][s]= 1;
	}
	
	
}//end of creategraph

void dfs(int s)
{
	pathlen[s]= 1;
	for(int i=0; i<n; ++i)
	{
		if(A[s][i] == 1)
		{
			if(pathlen[i] == 0)
			{
			//	pathlen[i]= 1;
				dfs(i);
			}
		}
	}
}
