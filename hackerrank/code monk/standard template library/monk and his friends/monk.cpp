#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define ll long long
#define l long
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define FOR(i, m, n) for(ll i=0; i<m; i+=n)


int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;
		
		
		set<l>::iterator it;
		
		l A[n];
		l B[m];
		
		FOR(i, n, 1)
			cin>>A[i];
			
		FOR(i, m, 1)
			cin>>B[i];
			
		set<l> a (A, A+n); //array A copied to set a
		
		l temp;
		FOR(i, m, 1)
		{
			it= a.find(B[i]);
			if(it == a.end())
				cout<<"NO\n";
			else
				cout<<"YES\n";
				
			a.insert(B[i]);
		}
		
		a.clear();	
		
		
	}
	
	
	return 0;
}
