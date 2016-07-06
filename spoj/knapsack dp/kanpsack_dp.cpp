#include <iostream>
using namespace std;

int maxval(int a, int b)
{
		return (a>b)?a:b;	
}

int knapsack(int s[], int pr[], int n, int max)
{
	int val[n+1][max+1];
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<=max; ++j)
		{
			if(i==0 || j==0) val[i][j]= 0;
			else if(s[i-1] <= j)
				val[i][j]= maxval(pr[i-1]+ val[i-1][j-s[i-1]], val[i-1][j]);
			else
				val[i][j]= val[i-1][j]; 
				
		}
	}	
	return val[n][max];
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
