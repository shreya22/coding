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
#define FOR1(i, m, n) for(ll i=1; i<=m; i+=n)

int main() {
	// your code goes here
	
	int a[10]; 
	int t;
	cin>>t;
	while(t--)
	{
		FOR(i, 10, 1)a[i]=0;
		
		int n;
		cin>>n;
		
		int x;
		FOR(i, n, 1)
		{
			cin>>x;
			x= x%10;
			
			a[x]++;
		}
		
		int sum=0;
		FOR(i, 10, 1)
		{
			if(a[i]!= 0) a[i]-= 1;
			sum+= a[i];
		}
		
		cout<<sum<<endl;
	}
	
	return 0;
}
