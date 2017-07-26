// Consider a complete binary tree with 
// N
// N leaves. Every node of the tree stores a positive value. The tree has been built in such a way that every internal node of the tree has a value that is xor of the values of it's two children.

// You are given 
// N
// N integers, denoting the values of the 
// N
// N leaves. Find and print the value at the root node.

// It can be proven that this value can be uniquely determined.


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
		queue<ll> q;

		ll temp;
		FOR(i, n) {
			cin>>temp;
			q.push(temp);
		}

		while(q.size() >=2){
			ll x, y;
			x= q.front(); q.pop();
			y= q.front(); q.pop();
			q.push(x ^ y);
		}
		temp= q.front();
		cout<<temp<<endl;		
	}

    return 0;
}
