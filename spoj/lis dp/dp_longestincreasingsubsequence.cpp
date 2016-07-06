#include <iostream>
using namespace std;

int lis(int a[], int n)
{
	int ans[n];
	for(int i=0; i<n; ++i) ans[i]= 1;
	
	for(int i=1; i<n; ++i)
	{
		for(int j=0; j<i; ++j)
		{
			if(a[j]<a[i] && (ans[j]+1)>ans[i])
				ans[i]=ans[j]+1; 
		}
		
	}
	int max=0;
	for(int i=0; i<n ;++i) 
		if(max<ans[i]) max= ans[i];
		
	return max;
	
}

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];
		
	cout<<lis(a, n);
	
	
	return 0;
}
