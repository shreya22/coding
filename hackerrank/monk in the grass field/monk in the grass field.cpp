#include <iostream>
#include<cstdio>
#include<algorithm>
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
		int n, k;
		cin>>n>>k;
		
		ll a[n][n], r[n], c[n];
		
		FOR(i, n, 1)
		{
			r[i]=0;
			c[i]=0;
		}
		
		FOR(i, n, 1)
		{
			FOR(j, n, 1)
			{
				cin>>a[i][j];
				
				r[i]+= a[i][j];
				c[j] += a[i][j];
			}
		}
		
		sort(r, r+n);
		sort(c, c+n);
		
		ll dis=0, temp=0;
		for(int i=0; i<k; ++i)
		{
			temp= min(r[0], c[0]);
			dis += temp;
			if( temp == r[0])
			{
				r[0]+= n;
				sort(r, r+n);
				
				FOR(j, n, 1) c[j]+=1;
			}else
			{
				c[0]+= n;
				sort(c, c+n);
				
				FOR(j, n, 1) r[j]+=1; 
			}
			
			//FOR(j, n, 1) cout<<r[j]<<" ";cout<<endl;
			//FOR(j, n, 1) cout<<c[j]<<" "; cout<<endl;
		}
		
		cout<<dis<<endl;
	}
	
	
	return 0;
}
