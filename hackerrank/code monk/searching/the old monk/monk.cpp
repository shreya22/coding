#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long
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
		
		vector<ll> a(n), b(n);
		FOR(i, n, 1)
			scanf("%lld", &a[i]);
		
		FOR(i, n, 1)
			scanf("%lld", &b[i]);
			
		int ans=0;
		FOR(i, n, 1)
		{
			int l=0, h=n-1, temp=-1, mid;
			while(l<=h)
			{
				mid= (l+h)/2;
				if(a[i] <= b[mid])
				{
					temp=mid;
					l=mid+1;
				}
				else
				{
					h=mid-1;
				}
			}
			ans= max(temp-i, ans);
		}
		
		cout<<ans<<endl;
			
	}
	
	return 0;
}
