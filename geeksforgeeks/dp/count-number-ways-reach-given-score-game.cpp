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

int numWays(int n){
	int a[3]= {3, 5, 10};
	int arr[4][n+1];

	FOR1(j, n+1) arr[0][j]= 0;
	FOR(i, 4) arr[i][0]= 1;

	FOR1(i, 4){
		FOR1(j, n+1){
			int x= (j - a[i-1] >= 0)?arr[i][j- a[i-1]]:0;
			int y= arr[i-1][j];

			arr[i][j]= x+y; 
		}
	}

	// FOR(i, 4){
	// 	FOR(j, n) cout<<arr[i][j]<<" ";
	// 	cout<<endl;
	// }

	return arr[3][n];
}

int main() {

	int n;
	cin>>n;

	cout<<numWays(n);

    return 0;
}
