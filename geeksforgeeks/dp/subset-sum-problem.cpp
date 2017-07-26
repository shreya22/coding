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

bool subsetSum(int a[], int n, int sum){
	bool arr[n+1][sum+1];
	FOR1(i, sum+1) arr[0][i]= false;
	FOR(i, n+1) arr[i][0]= true;

	FOR1(i, n+1){
		FOR1(j, sum+1){
			arr[i][j]= arr[i-1][j];
			if(a[i-1] <= j) arr[i][j]= arr[i-1][j] || arr[i-1][j-a[i-1]]; 
		}
	}

	FOR(i, n+1){
		FOR(j, sum+1)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}

	return arr[n][sum];
}

int main() {

	cin>>n;

	int arr[n];
	FOR(i, n) cin>>arr[i];

	int sum; cin>>sum;
	if(subsetSum(arr, n, sum)) cout<<"true";
	else cout<<"false";
	cout<<endl;

    return 0;
}
