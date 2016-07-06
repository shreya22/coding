#include <iostream>
#include<cstdio>
using namespace std;

long long int max(long long a, long long b)
{
	if(a>b) return a;
	else return b;
}

long long total(long long a[], int n)
{
	long long val[n];
	for(int i=0; i<n; ++i) val[i]= 0;
	
	val[0]= a[0];
	val[1]= max(val[0], a[1]);
	
	for(int i=2; i<n; ++i)
	{
		val[i]= max(val[i-1], val[i-2] + a[i]);
	}
	return val[n-1];
}


int main() {
	// your code goes here
	
	int t;
	cin>>t;
	for(int m=1; m<=t; ++m)
	{
		
		int n;
		scanf("%d", &n);
		
		if(n==0) cout<<"0\n";
		else
		{
			long long a[n];
		for(int i=0; i<n; ++i)
			scanf("%lld", &a[i]);
			
		long long x= total(a, n);
		cout<<"Case "<<m<<": "<<x<<endl;
		}
		
	}
	
	
	return 0;
}
