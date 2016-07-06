#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#define MAX 100001
#define temp 0
#define perm 1


int a[MAX];
int len[MAX];
int state[MAX];
int n;

void createadj();
void bfs(int s);
using namespace std;

vector< vector<int> > adj;
queue<int> que;

int main()
{
	string s;
	cin>>s;
	
	for(int i=0; i<s.length(); ++i)
		a[i] = (int)s[i] - 48;
		
	n= s.length();
	
	createadj();
	
	bfs(0);
	cout<<len[n-1];
	
	return 0;
}

void createadj()
{
	for(int i = 0; i<n; ++i ){
        vector<int> p;       //Row-Vector       
        p.resize(n);            //Length of Row-Vector is n
        adj.push_back(p);         
    }
    
    for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
			adj[i][j] = 0;
	}
	
	
	//initialising length of each vertex to 0
	for(int i=0; i<n; ++i)
		len[i] = 0;

	//initialise status of each vertex to temp
	for(int i=0; i<n; ++i)
		state[i]= temp;
		
	//making undirected edges for consecutive vertices
	for(int i=0; i<(n-1); ++i)
	{
		adj[i][i+1]= 1;
		adj[i+1][i]= 1;
	}
	
	//making undirected edges for same value vertices
	for(int i=0; i<(n-1); ++i)
	{
		for(int j=i+1; j<n; ++j)
		{
			if(a[i] == a[j])
			{
				adj[i][j] = 1;
				adj[j][i]= 1;
			}
		}
		
	}

	
}//end of createadj


void bfs(int s)
{
	que.push(s);
	state[s]= perm;
	
		
	while(!que.empty())
	{
		s= que.front(); //cout<<s<<"  ";
		que.pop();
		
		for(int i=0; i<n; ++i)
		{
			
			if((adj[s][i] == 1) && (state[i]== temp))
			{
				que.push(i);
				state[i]= perm;
				len[i] = len[s] + 1;
			
			}
		}
	}
	
}

