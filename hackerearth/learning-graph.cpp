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

int n, m, k;
bool customSort( const pair<int, int>&a, const pair<int, int>&b){
	return a.first <= b.first;
}

int main() {

	cin>>n>>m>>k;
	int nodeVal[n+1];
	FOR1(i, n+1) cin>>nodeVal[i];

	priority_queue< pair<int, int>, vector< pair<int, int> >, customSort > graph[n];

	int x, y;
	FOR(i, m){
		cin>>x>>y;
		graph[x].push(make_pair(nodeVal[y], y));
	}

	FOR1(i, n+1){
		if(graph[i].size()<k) cout<<"-1\n";
		else{
			FOR(j, k-1) graph[j].pop();
			// cout<<graph[i].top()<<endl;
			cout<<"aa\n";
		}
	}

    return 0;
}
