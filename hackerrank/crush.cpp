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

	long n, m;
	cin>>n>>m;
	ll a, b, k;

	map<long, ll> group;
	for(long i=0; i<m; ++i){
		cin>>a>>b>>k;
		for(ll j=a-1; j<b; ++j){
			if(group.find(j) == group.end()) group.insert(pair<long, ll>(j, k));
			else group.find(j)->second += k;
		}
	}

	ll max= 0;
	for(map<long, ll>::iterator it= group.begin(); it!= group.end(); ++it){
		if(it->second>max) max= it->second;
	}  

	cout<<max;


    return 0;
}
