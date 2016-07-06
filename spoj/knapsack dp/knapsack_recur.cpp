#include <iostream>
using namespace std;

int maxval(int a, int b)
{
		return (a>b)?a:b;	
}

int knapsack(int s[], int val[], int n, int max)
{
	if(n==0) return 0;
	if(max == 0) return 0;
	
	if(s[n-1] > max) return knapsack(s, val, n-1, max);
	
	return maxval(val[n-1] + knapsack(s, val, n-1, max-s[n-1]), knapsack(s, val, n-1, max));
}

int main() {
	// your code goes here
	
	int size, n;
	cin>>size>>n;
	
	int s[n], val[n], ans;
	for(int i=0; i<n; ++i)
	{
		cin>>s[i]>>val[i];
	}
	
	ans= knapsack(s, val, n, size);
	cout<<ans;
	
	return 0;
}
