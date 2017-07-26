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
		int x, y;
		cin>>x>>y;

		long long a, b, sum;
		if(x==y) cout<<0<<endl;
		else{
			a= pow((y+1)/2, 2);
			b= pow((x)/2, 2);
			sum =a-b;
			cout<<sum<<endl;
		}
	}

    return 0;
}
