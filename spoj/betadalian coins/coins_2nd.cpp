#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>

using namespace std;

map<long long, long long> a;

long long dp(long long n)
{
	if(n==0) return 0;
	
	if(a[n] != 0) return a[n];
	
	long long temp = dp(n/2) + dp(n/3) + dp(n/4);
	if(n<temp) a[n]= temp;
		else a[n]= n;
		
	return  a[n];
}

int main() {
	// your code goes here
	

	long long n;
	while(cin>>n)
	{
	//	long long a[n+1];
		cout<<dp(n)<<endl;
		
	}
	
	
	return 0;
}
