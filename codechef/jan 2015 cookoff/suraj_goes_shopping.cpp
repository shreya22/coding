#include <iostream>
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
		for(int i=0; i<n; ++i)
			cin>>a[i];
			
		sort(a, a+n); long int sum=0;
		for(int i=n-1; i>=0; i= i-4)
		{
			sum= sum + a[i];
			if(i>0) sum= sum + a[i-1]; 
		}
		
		cout<<sum<<endl;
		
	}
	
	
	return 0;
}
