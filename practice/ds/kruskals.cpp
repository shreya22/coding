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

int n, m;
int id[100001];

void initialize(int n){
	FOR(i, n+1) id[i]= i;
}

int root(int x){
	while(id[x]!=x) {
		id[x]= id[id[x]];
		x= id[x];
	}
	return x;
}

void join(int x, int y){
	int p= root(x);
	int q= root(y);
	id[p]= id[q];
}

int kruskal(pair< int, pair<int, int> >p[]){
	int x, y;
	int minCost=0, cost=0;
	FOR(i, m){
		x= p[i].second.first;
		y= p[i].second.second;
		if(root(x) != root(y)) {
			minCost+= p[i].first;
			join(x, y);
		}
	}
	return minCost;
}

int main() {
	
	cin>>n>>m;

	initialize(n);
	pair< int, pair<int, int> > graph[m];

	int x, y, w;
	FOR(i, m){
		cin>>x>>y>>w;
		graph[i]= make_pair(w, make_pair(x, y));
	}

	// sort the edges in increasing order of weights
	sort(graph, graph+m);
	cout<<kruskal(graph);

    return 0;
}
