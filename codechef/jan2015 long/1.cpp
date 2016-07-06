#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		long int n, k;
		cin>>n>>k;
		long int a[n], b[n];
		long long div=0, profit=0, temp=0;
		
		for(int i=0; i<n; ++i) cin>>a[i];
		
		for(int i=0; i<n; ++i)
		{
			cin>>b[i];
			div= k/a[i];
			
			temp= div*b[i];
			if(temp>profit) profit= temp;
		}
		
		cout<<profit<<endl;
		
		
	}
	
	
	return 0;
}
