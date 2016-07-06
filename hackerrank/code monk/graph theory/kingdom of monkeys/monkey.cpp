#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
 
#define ll long long
#define l long
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define FOR(i, m, n) for(ll i=0; i<m; i+=n)
#define FOR1(i, m, n) for(ll i=1; i<=m; i+=n)

int n, m;
bool v[100000];
vector<int> adj[100000];
vector<int> a;

void initialize()
{
	//setting all visited nodes to false
	FOR1(i, n, 1)
		v[i]= false;
		
	//resetting adj matrix
	FOR(i, 100000, 1)
		{
			adj[i].clear();
		}
	
	FOR(i, a.size(), 1)
		a.clear();
}

ll dfs(int x)
{
	ll sum=a[x-1];
	
	v[x]= true;
	FOR(i, adj[x].size(), 1)
	{
		if(v[adj[x][i]]== false)
		{
			//cout<<"starting dfs for node "<<adj[x][i]<<endl;
			sum+= dfs(adj[x][i]); 
			//cout<<"sum= "<<sum<<" ";
		}
	}
	//cout<<"initial sum= "<<sum<<" ";
	return sum;
}
 
int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		
		initialize();
		
		int x, y;
		FOR(i, m, 1)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		ll temp;
		FOR(i, n, 1)
		{
			cin>>temp;
			a.push_back(temp);
		}
		
		ll maximum=0, tmp;
		FOR1(i, n, 1)
		{
			if(v[i] == false)
			{
				//cout<<"entered for dfs node "<<i<<endl;
				tmp= dfs(i);
				//cout<<tmp<<" tmp\n";
				maximum= max(maximum, tmp);
			}
		}
		cout<<maximum<<endl;
		
	}
	
	return 0;
}
