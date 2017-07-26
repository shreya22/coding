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

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		int arr[n];
		FOR(i, min(2, n)){
			arr[i]= i+1;
		}
		for(int i=2; i<n; ++i){
			if(arr[i-2] + arr[i-1] < 500) arr[i]= arr[i-2] + arr[i-1] + 1;
			else arr[i]= arr[i-2] + arr[i-1] - 1;
		}

		FOR(i, n) cout<<arr[i]<<" ";
		cout<<endl;
	}

    return 0;
}
