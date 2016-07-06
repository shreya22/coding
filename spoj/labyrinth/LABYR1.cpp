#include<iostream>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>

#define MAX 1000
#define temp 0
#define perm 1
#define nil -1

int c, r, count;
int adj[MAX][MAX];
int status[MAX][MAX];
int len[MAX][MAX];
int cnt;

void dfs(int s1, int s2);

using namespace std;

int main()
{
//	int t;
//	cin>>t;
//	while(t--)
//	{
		cin>>c>>r;
		char x, y;
		
		cnt=0;
		
		for(int i=0; i<r; ++i)
		{
			for(int j=0; j<c; ++j)
			{
				cin>>x;
				if(x == '.')
				{
					adj[i][j]= 1;
					status[i][j] = temp;
					len[i][j] = 0;
				}
				else
					adj[i][j]= 0;
			}
		
		}
		
		int s1, s2;
		int flag=0;
		
		for(int i=0; i<r; ++i)
		{
			for(int j=0; j<c; ++j)
			{
				if(adj[i][j] == 1)
				{
					s1= i;
					s2= j;
					
					flag=1;
					break;
				}
			}
			if(flag == 1) break;
		}
		
		dfs(s1, s2);
		
		int max= -1;
		for(int i=0; i<r; ++i)
		{
			for(int j=0; j<c; ++j)
			{
				if(len[i][j] > max)
					max= len[i][j];
			}
		}	
		
		cout<<max<<endl;
		
//	}//end of test cases loop
	
	
	
	
	return 0;
}

void dfs(int s1, int s2)
{
	status[s1][s2]= perm;
	cnt++;
	
	if((s1-1)>=0)
	{
		if((adj[s1-1][s2] == 1) && (status[s1-1][s2] == temp))
		{
			len[s1-1][s2] = len[s1][s2]+1;
			dfs(s1-1, s2);
		}
		
	}
	
	if((s2-1) >=0)
	{
		if((adj[s1][s2-1] == 1) && (status[s1][s2-1] == temp))
		{
			len[s1][s2-1] = len[s1][s2]+1;
			dfs(s1, s2-1);
		}
		
	}
	
	if((s2+1) >=0)
	{
		if((adj[s1][s2+1] == 1) && (status[s1][s2+1] == temp))
		{
			len[s1][s2+1] = len[s1][s2]+1;
			dfs(s1, s2+1);
		}
		
	}
	
	if((s1+1)>=0)
	{
		if((adj[s1+1][s2] == 1) && (status[s1+1][s2] == temp))
		{
			len[s1+1][s2] = len[s1][s2]+1;
			dfs(s1+1, s2);
		}
		
	}
	
	
}


