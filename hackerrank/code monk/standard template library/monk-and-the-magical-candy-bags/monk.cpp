#include <iostream>
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
	
	int t; //cout<<"test";
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		
		l temp;
		
		priority_queue<l> p;
		FOR(i, n, 1)
		{
			cin>>temp;
			p.push(temp);
		}
		
		ll sum=0;
		FOR(i, k, 1)
		{
			temp= p.top();
			sum+= temp;
			temp/= 2;
			p.pop(); p.push(temp);
		}
		
		cout<<sum<<endl;
	
	
	}
	
	return 0;
}
