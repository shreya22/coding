#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int n, x, start=0, flag=false;
		long sum=0;
		
		cin>>n>>x;
		
		int cost[n];
		
		for(int i=0; i<n; ++i) cin>>cost[i];
		
		sum= cost[0];
		for(int i=1; i<n; ++i)
		{
			while(sum>x)
			{
				sum -= cost[start];
				start++;
			}
			
			if(sum == x)
			{
				flag=true;
				break;
			}
			
			sum+= cost[i];
		}
		
		while(sum>x)
		{
			sum -= cost[start];
				start++;
		}
		
		if(sum == x)flag=true;
		else flag=false;
		
		if(flag)
		{
			cout<<"YES\n";
		}else
		{
			cout<<"NO\n";
		}
		
	}
	
	return 0;
}
