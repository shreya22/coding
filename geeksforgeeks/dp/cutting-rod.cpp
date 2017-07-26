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

int cuttingRod(int str[], int n)
{
	int cr[n+1]; cr[0]= 0;
	FOR1(i, n+1){
		int maxval= -1;
		for(int j=0; j<i; ++j){
			maxval= max(maxval, str[j] + cr[i-j-1]);
		}
		cr[i]= maxval;
	}

	return cr[n];
}

int main() {

	int n;
	cin>>n;

	int str[n];
	FOR(i, n) cin>>str[i];

	cout<<cuttingRod(str, n);

    return 0;
}
