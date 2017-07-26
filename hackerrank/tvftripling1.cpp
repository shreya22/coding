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

int n;
ll tripleInv(ll *a){
	ll count= 0;
	ll x, y;

	FOR(i, n){
		x=0, y=0;
		for(int j=0; j<i; ++j){
			if(a[j] > a[i]) x++;
		}
		for(int j=i+1; j<n; ++j){
			if(a[j] < a[i]) y++;
		}

		// cout<<"x "<<x<<" y "<<y<<endl;
		count+= x*y;
	}
	return count;
}

int main() {
	cin>>n;

	ll a[n];
	FOR(i, n) scanf("%lld", &a[i]);
	cout<<tripleInv(a);

    return 0;
}
