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

void bfs(vector<int> *tree, int n, int s){
	queue<int> q;
	bool visited[n+1];
	int level[n+1];

	q.push(s);
	visited[s]= true;
	level[s]= 0;

	while(!q.empty()){
		int current= q.front();
		q.pop(); 

		cout<<current<<" ";

		for(int i=0; i<tree[current].size(); ++i){
			if(!visited[tree[current][i]]){
				q.push(tree[current][i]);
				visited[tree[current][i]]= true;
				level[tree[current][i]]= level[current]+1;
			}
		}
	}

	cout<<endl<<"levels are: ";
	FOR1(i, n+1) cout<<i<<" "<<"level: "<<level[i]<<endl;
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

	bfs(tree, n, 1);


    return 0;
}
