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

int numberOfWays(int n){
	int ways[n];
	ways[0]= 1;
	ways[1]= 2;

	int x, y;
	for(int i=2; i<n; ++i){
		ways[i]= ways[i-2] + ways[i-1];
	}
	return ways[n-1];
}

int main() {

	int n;
	cin>>n;
	cout<<numberOfWays(n)<<endl;

    return 0;
}
