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
#define MAX 100000
int n, m;

void initialize(int *p, int *a, bool *v){
	FOR(i, n+1){
		p[i]= -1;
		a[i]= MAX;
		v[i]= false;
	}
}

int minKey(int *key, bool *vis){
	int temp= MAX, index;
	FOR(i, n+1){
		if(key[i]<temp && vis[i]== false){
			temp= key[i];
			index= i;
		}
	}
	return index;
}

void prims(vector< pair<int, int> > *a){
	int parent[n+1];
	int key[n+1];
	bool visited[n+1];
	initialize(parent, key, visited);

	vector< pair<int, int> > edges;
	key[1]= 0;

	FOR(i, n){
		int current= minKey(key, visited);
		visited[current]= true;
		
		FOR(j, a[current].size()){
			if(a[current][j].second < key[a[current][j].first] && !visited[a[current][j].first]){
				parent[a[current][j].first] = current;
				key[a[current][j].first]= a[current][j].second;
			}
		}
		edges.pb(make_pair(parent[current], current));
	}

	cout<<"prims is: \n";
	FOR1(i, n) cout<<edges[i].first<<" -> "<<edges[i].second<<endl;
}

int main() {
	cin>>n>>m;
	vector< pair<int, int> > a[n+1];
	
	int x, y, w;
	FOR(i, m) {
		cin>>x>>y>>w;
		a[x].pb(make_pair(y, w));
		a[y].pb(make_pair(x, w));
	}

	prims(a);

    return 0;
}
