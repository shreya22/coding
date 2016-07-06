a#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
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
		int n;
		cin>>n;
		
		set<string>::iterator it;
		set<string> s;
		
		string inp;
		
		FOR(i, n, 1)
		{
			cin>>inp;
			s.insert(inp);
		}
		
		for(it = s.begin();it != s.end();++it)
        cout << *it <<endl;
 
	}
    
	
	return 0;
}
