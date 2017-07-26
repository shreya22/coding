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
long n;

long prefixXor(long *a, long x){
	long index= x;
	long val=0;
	while(index){
		val= val^a[index];
		index-= index & -index;
	}
	return val;
}

long xora(long *a, long x, long y){
	return prefixXor(a, y) - prefixXor(a, x-1);
}

void update(long *a, long x, long y){
	long index= x;
	while(index <=n){
		a[index]= a[index]^y;
		index+= index & -index;
	}
}

long * makeBIT(long *a){
	long *b;
	b[0]= 0;
	FOR1(i, n+1) b[i]= 0;
	FOR1(i, n+1){
		update(b, i, a[i]);
	}
	return b;
}

int main() {

	cin>>n;
	long a[n+1];
	a[0]= -1;
	FOR1(i, n+1) cin>>a[i];

	int q;
	cin>>q;
	long x, y, flag;

	long *arr;
	makeBIT(a);

	FOR(i, q){
		cin>>flag>>x>>y;
		// if(flag==0) cout<<xora(arr, x, y);
		// else update(arr, x, y);
	}

    return 0;
}
