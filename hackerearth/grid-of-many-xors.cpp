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
#define MAX 10000

void initialize(int *parent, bool *vis, int *key, int n){
	FOR(i, n+1){
		parent[i]= -1;
		vis[i]= false;
		key[i]= MAX;
	}
}

void prims(vector<pi> *a, int n){
	int parent[n+1], key[n+1];
	bool inMST[n+1];
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	long mstSum=0;

	// initializing
	initialize(parent, inMST, key, n);

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

	// FOR1(i, n+1){
	// 	cout<<parent[i]<<" -> "<<i<<endl;
	// }

	FOR1(i, n+1) mstSum+= key[i];
	cout<<mstSum<<endl;

	// FOR1(i, n+1) cout<<key[i]<<" ";
	// cout<<endl;
}

int main() {

	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;

		int r1, r2, c1, c2;
		cin>>r1>>r2;
		cin>>c1>>c2;

		int a[n+1][m+1];
		FOR1(i, n+1)
			FOR1(j, m+1)
				cin>>a[i][j];

		vector<pi> e[m*n+1];

		// number of node- [n*(i-1)+j]

		FOR1(i, n+1){
			FOR1(j, m+1){
				pair<int, int> p;

				int n1= m*(i-1)+j, n2;
				
				if( (i-1)>0 ){
					n2= m*(i-2)+j;
					p= mp( n2, a[i][j] ^ a[i-1][j] );
					e[n1].pb(p);
				}

				if( (j-1)>0 ){
					n2= m*(i-1)+j-1;
					p= mp( n2, a[i][j] ^ a[i][j-1] );
					e[n1].pb(p);
				}

				if( (i+1)<=n ){
					n2= m*(i)+j;
					p= mp( n2, a[i][j] ^ a[i+1][j] );
					e[n1].pb(p);
				}

				if( (j+1)<=m ){
					n2= m*(i-1)+j+1;
					p= mp( n2, a[i][j] ^ a[i][j+1] );
					e[n1].pb(p);
				}
			}
		}

		prims(e, m*n);
	}

    return 0;
}
