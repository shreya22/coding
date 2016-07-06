#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

#define ll long long
#define l long int
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define FOR(i, m, n) for(ll i=0; i<m; i+=n)


int main() {
	// your code goes here
	
	l a, b;
	cin>>a>>b;
	
	string len;
	cin>>len;
	
	int i=0, x= len.length();
	
	ll sum=0;
	
	while(x--)
	{
		if(len[i] == '1')
		{
			sum += pow(a, pow(2, i));
			sum= sum%b;
		}
		
		i++;
	}
	
	
	cout<<sum;
	
	return 0;
}
