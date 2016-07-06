#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>

using namespace std;

map<long long, long long> a;

int main() {
	// your code goes here
	
	long long n;
	while(cin>>n)
	{
	//	long long a[n+1];
		for(int i=0; i<=n; ++i)
			a[i]= i;
		
		for(int i=1; i<=n; ++i)
		{
			if(a[i] < (a[i/2] + a[i/3] + a[i/4]))
				a[i] = a[i/2] + a[i/3] + a[i/4];
		}
		
		cout<<a[n]<<endl;
		
	}
	
	
	return 0;
}
