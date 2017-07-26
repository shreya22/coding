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

int m, n;

int maxSize(int arr[m][n])
{
	int sizeArr[m][n];
	FOR(i, n) sizeArr[0][i]= arr[0][i];
	FOR(i, m) sizeArr[i][0]= arr[i][0];

	FOR1(i, m){
		FOR1(j, n){
			if(arr[i][j] == 0) sizeArr[i][j]= 0;
			else sizeArr[i][j]= min(arr[i-1][j], arr[i][j-1], arr[i-1][j-1])+1;
		}
	}

	int maxSizeVal= -1;
	FOR(i, m)
		FOR(j, n)
			if(sizeArr[i][j] > maxSizeVal) maxSizeVal= sizeArr[i][j];

	return maxSizeVal;
}

int main() {

	cin>>m>>n;
	int arr[m][n];
	FOR(i, m)
		FOR(j, n)
			cin>>arr[i][j];

	cout<<maxSize(arr);

    return 0;
}
