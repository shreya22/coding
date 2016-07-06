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
		string a, b="";
		cin>>a;
		
		char temp;
		int l= a.size();
		
		int i=0, j=0;
		for(int i=0; i<l; ++i)
		{
			if(i==0) b[j]= a[i];
			else
			{
				if(a[i] == b[j]);
				else
				{
					j++;
					b[j]= a[i];
				}
			}
		}
		
		for(int p=0; p<=j; ++p)
			cout<<b[p];
			
		cout<<endl;
		
	}
	
	return 0;
}
