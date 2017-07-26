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

int rootNode[100001];
int n, m;

void initialize(int n){
	FOR(i, n+1) rootNode[i]= i;
}

int root(int x){
	while(rootNode[x]!= x){
		rootNode[x]= rootNode[rootNode[x]];
		x= rootNode[x];
	}
	return x;
}

void join(int x, int y){
	int p= root(x);
	int q= root(y);
	rootNode[p]= rootNode[q];
}

bool checkCycles(pair<int, int> p[]){
	bool cycle= false;
	FOR(i, m){
		int x= p[i].first;
		int y= p[i].second;
		if(root(x) == root(y)) cycle= true;
		else join(x, y);
	}
	return cycle;
}

int main() {

	cin>>n>>m;
	pair<int, int> p[m];
	initialize(n);

	int x, y;
	FOR(i, m){
		cin>>x>>y;
		p[i]= make_pair(x, y);
	}

	if(checkCycles(p)) cout<<"cycle detected!\n";
	else cout<<"no cycle found\n";

    return 0;
}
