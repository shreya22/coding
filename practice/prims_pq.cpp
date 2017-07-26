#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long
#define mp(i, j) make_pair(i, j)

//stl macros

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pi; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define MAX 100000

int n, m;
void initialize(int *parent, bool *vis, int *key){
	FOR(i, n+1){
		parent[i]= -1;
		vis[i]= false;
		key[i]= MAX;
	}
}

void prims(vector<pi> *a){
	int parent[n+1], key[n+1];
	bool inMST[n+1];
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	long mstSum=0;

	// initializing
	initialize(parent, inMST, key);

	// marking 1st node as visited
	key[1]= 0;
	pq.push(mp(0, 1));

	// cout<<pq.top().first;

	while(pq.size()){
		int current= pq.top().second;
		pq.pop();

		inMST[current]= true;
		vector<pi>::iterator it;
		for(it= a[current].begin(); it!=a[current].end(); ++it){
			int v= (*it).first;
			int weight= (*it).second;

			if(!inMST[v] && key[v]>weight){
				key[v]= weight;
				parent[v]= current;
				pq.push(mp(weight, v));
			}
		}
	}

	FOR1(i, n+1){
		cout<<parent[i]<<" -> "<<i<<endl;
	}

	FOR1(i, n+1) mstSum+= key[i];
	cout<<mstSum;
}

int main() {

	cin>>n>>m;
	vector<pi> a[n+1];
	
	int x, y, w;
	FOR(i, m) {
		cin>>x>>y>>w;
		a[x].pb(make_pair(y, w));
		a[y].pb(make_pair(x, w));
	}

	prims(a);


    return 0;
}
