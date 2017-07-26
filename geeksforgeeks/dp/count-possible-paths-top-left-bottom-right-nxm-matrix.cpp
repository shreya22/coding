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

int numPaths(int m, int n){
	int a[m][n];

	FOR(i, m) a[i][n-1]= 1;
	FOR(j, n) a[m-1][j]= 1;

	FORrev(i, m-1){
		FORrev(j, n-1){
			a[i][j]= a[i+1][j] + a[i][j+1];
		}
	}

	// FOR(i, m){
	// 	FOR(j, n) cout<<a[i][j]<<" ";
	// 	cout<<endl;
	// }
	return a[0][0];
}

int main() {

	int m, n;
	cin>>m>>n;

	cout<<"number of paths: "<<numPaths(m, n)<<endl;

    return 0;
}

// same problem can be solved in O(1) time
// we have to make total of m+n-2 moves. m-1 rightwards, n-1 downwards.
// let right- 0 and down- 1
// so m+n-2 places have to be filled by 0s and 1s. If we fill by 1s only, rest are 0s.
// solution concats to (m+n-2)C(m-1) OR (m+n-2)C(n-1)