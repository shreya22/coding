#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

//stl macros

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define MAX 100001
int n, m;

int minKey(int *key, bool *vis){
	int val=MAX, index;
	FOR(i, n+1){
		if(key[i]<val && vis[i]== false){
			val= key[i];
			index= i;
		}
	}
	return index;
}

int findCost(vector<int> g[MAX]){
	bool vis[n+1]; 
	int parent[n+1], key[n+1];
	FOR(i, n+1){
		vis[i]= false;
		parent[i]= -1;
		key[i]= MAX;
	}
	bool newSet[n+1][n+1];
	FOR(i, n+1)
		FOR(j, n+1) newSet[i][j]= false;

	// random selecting 1 as start node in prims
	key[1]= 0;
	FOR(i, n){
		int current= minKey(key, vis);
		vis[current]= true;

		FOR(i, n+1){
			if(g[current][i]<key[i] && vis[i]==false){
				key[i]= g[current][i];
				parent[i]= current;
			}
		}
		if(parent[current]!= -1){
			int p= parent[current];
			newSet[p][current]= 1;
			newSet[current][p]= 1;
		}
	}

	ll sum=0;
	FOR1(i, n+1){
		FOR1(j, n+1){
			if(g[i][j] != MAX && newSet[i][j]==false) sum+= g[i][j];
		}
	}
	return sum/2;
}

int main() {

	cin>>n>>m;
	vector<int> g[MAX];
	FOR(i, n+1)
		FOR(j, n+1) g[i].pb(MAX);

	int x, y, w;
	FOR(i, m){
		cin>>x>>y>>w;
		g[x][y]= w;
		g[y][x]= w;
	}

	cout<<findCost(g);

    return 0;
}
