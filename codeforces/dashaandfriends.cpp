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

int n, l;

bool fun(int *a, int *b, int index){

	if(index == n) return false;
	int temp= b[index];
	
	int i=0;
	for(int j=index; j<n; ++j){
		if(a[i++] != b[j]-temp) return false;
	}
	for(int j=0; j<index; ++j){
		if(a[i++] != b[j]+l-temp) return false;
	}

	return true;
}

bool rec(int *a, int *b){
	FOR(i, n){
		if(fun(a, b, i)) return true;
	}
	return false;
}

int main() {

	cin>>n>>l;
	int a[n], b[n];
	FOR(i, n) cin>>a[i];
	FOR(i, n) cin>>b[i];

	int temp= a[0];
	FOR(i, n) {
		a[i]= a[i]- temp;
	}
	if(rec(a, b)) cout<<"YES\n";
	else cout<<"NO\n";

    return 0;
}
