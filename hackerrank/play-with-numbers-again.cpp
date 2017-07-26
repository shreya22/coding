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

int getfno(int n){
	if(n%2==0){
		// even pair, all 1s
		if(n%4==0) return 0;
		else return 1;
	}
	else{
		if((n-1)%4 == 0) return 1;
		else return 0;
	}
}

int main() {

	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;

		long count=0;
		int whole= n/4;
		int frac= n%4;

		int temp= n-frac;
		count+= whole*2;
		while(frac){
			count+= getfno(++temp);
			frac--;
		}
		cout<<count<<endl;
	}

    return 0;
}
