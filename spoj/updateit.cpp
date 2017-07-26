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

int n, u;

int getSum(int *a, int index){
	int sum=0;
	while(index){
		sum+= a[index];
		index-= index& -index;
	}
	return sum;
}

void update(int *a, int index, int val){
	while(index<=n){
		a[index]+= val;
		index+= index & -index;
	}
}

int main() {

	int t;
	cin>>t;
	while(t--){
		cin>>n>>u;

		int a[n+1];
		FOR(i, n+1) a[i]= 0;

		int l, r, val;
		FOR(i, u){
			// cin>>l>>r>>val;
			scanf("%d %d %d", &l, &r, &val);
			update(a, l+1, val);
			update(a, r+2, -val);
		}

		// FOR1(i, n+1)cout<<a[i]<<" ";
		// cout<<endl;

		int q, index;
		cin>>q;
		while(q--){
			cin>>index;
			printf("%d\n", getSum(a, index+1));
		}
	}

    return 0;
}
