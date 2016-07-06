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
		string a;
		cin>>a;
		
		char temp;
		
		int l= a.size();
		for(int i=0; i<l/2; ++i)
		{
			temp= a[i];
			a[i] = a[l-i-1];
			a[l-i-1]= temp;
		}
		
		cout<<a<<endl;
	}
	
	return 0;
}
