#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		
		sort(a, a+n);
		for(int i=0; i<n; ++i) cout<<a[n-i-1]<<" ";
		cout<<endl;
		
	}
	
	return 0;
}
