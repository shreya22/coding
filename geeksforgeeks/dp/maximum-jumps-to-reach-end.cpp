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
#define MAXVAL 1000000;

int minPathOne(int arr[], int n){
	int pathLength[n];
	// FOR(i, n) pathLength[i]= MAXVAL;

	int temp;

	pathLength[0]= 0;
	FOR1(i, n)
	{
		temp= MAXVAL;
		for(int j=0; j<i; ++j){
			if(arr[j] + pathLength[j] >= i){
				temp= min(temp, pathLength[j]+1);
			}
		}
		pathLength[i]= temp;
	}
	return pathLength[n-1];
}


int main() {

	int n;
	cin>>n;
	int arr[n];
	FOR(i, n) cin>>arr[i];

	cout<<minPathOne(arr, n);

    return 0;
}
