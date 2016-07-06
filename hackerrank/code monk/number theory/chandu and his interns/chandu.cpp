#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

#define ll long long
#define l long 
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define FOR(i, m, n) for(ll i=0; i<m; i+=n)


int main() {
	// your code goes here
	
	int n;
	cin>>n;
	
	l x;
	int cnt=2, tmp=0, p=0;
	FOR(i, n, 1)
	{
		cin>>x;
		for(int j=2; j<= sqrt(x); ++j)
		{
			if(x%j == 0)
			{
				tmp=j;
				p=1;
				break;
			}
		}
		
		if(p==1)
		{
			if(tmp*tmp == x)
				cnt+= 1;
			else
				cnt+= 2;
		}
		
		if(cnt<=3)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	
		
		//cout<<cnt<<endl;
			
		p=0;
		tmp=0;
		cnt=2;
		
	}
	
	return 0;
}
