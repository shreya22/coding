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

void dfs(vector<int> *tree, int n, int src){
	stack<int> s;
	bool visited[n+1];

	s.push(src);
	visited[src]= true;

	while(!s.empty()){
		int current= s.top();
		s.pop(); 

		cout<<current<<" ";

		for(int i=0; i<tree[current].size(); ++i){
			if(!visited[tree[current][i]]){
				s.push(tree[current][i]);
				visited[tree[current][i]]= true;
			}
		}
	}

}

int main() {

	int n;
	cin>>n;
	vector<int> tree[n+1];

	int x, y;
	FOR(i, n-1){
		cin>>x>>y;
		tree[x].pb(y);
		tree[y].pb(x);
	}

	dfs(tree, n, 1);


    return 0;
}
