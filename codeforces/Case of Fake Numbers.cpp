#include <iostream>
#include<cstring>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	
	int diff= (n-a[0])%n;
//	cout<<diff<<endl;
	a[0]= 0;
	
	int p=0, x=0;
	for(int i=1; i<n; ++i)
	{
		if(i%2 == 1)
		{
			x= a[i]%n;
			p= diff-x;
			a[i]= (n- p)%n;
		}
		
		else
		{
			a[i] = (a[i]+diff)%n;
		}
	}
	
	long int cnt=0;
	for(int i=0; i<n; ++i) 
	{
		if(a[i] == i) cnt++;
	}
	
	
	if(cnt== n) cout<<"Yes";
	else cout<<"No";
	
}
