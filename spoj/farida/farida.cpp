#include <iostream>
using namespace std;

long long total(long long a[], int n)
{
	long long max=0, val[n];
	for(int i=0; i<n; ++i) val[i]=a[i];
	
	for(int i=2; i<n; ++i)
	{
		for(int j=0; j<(i-1); ++j)
		{
			if(val[j]+a[i] > val[i])
				val[i] = val[j]+ a[i];
		}
	}
	
	for(int i=0; i<n; ++i)
		if(max<val[i]) max= val[i];
	
	return max;
}


int main() {
	// your code goes here
	
	int t;
	cin>>t;
	for(int m=1; m<=t; ++m)
	{
		
		int n;
		cin>>n;
		long long a[n];
		for(int i=0; i<n; ++i)
			cin>>a[i];
			
		long long x= total(a, n);
		cout<<"Case "<<m<<": "<<x<<endl;
		
	}
	
	
	return 0;
}
