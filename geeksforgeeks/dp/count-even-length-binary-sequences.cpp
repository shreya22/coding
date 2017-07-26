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


// O(n^2)
int combinationsCount(int n){
	int comb[n+1][n+1];
	comb[0][0]= 0;
	FOR1(i, n+1) comb[i][0]= 1;
	FOR1(i, n+1) comb[i][i]= 1;

	FOR1(i, n+1){
		for(int j=1; j<i; ++j){
			comb[i][j]= comb[i-1][j-1] + comb[i-1][j];
		}
	}

	int sum=0;
	FOR(i, n+1) sum+= comb[n][i] * comb[n][i];
	return sum;
}
// O(n)
int combinationsCountBetter(int n){
	int sum=1;
	int ncr= 1;
	FOR1(i, n+1){
		ncr = ncr * (n+1-i)/i;   
		sum+= ncr*ncr;
	}
	return sum;
}

int main() {

	int n;
	cin>>n;
	cout<<combinationsCountBetter(n)<<endl;

    return 0;
}
