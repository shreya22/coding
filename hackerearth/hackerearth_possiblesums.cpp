#include <iostream>
using namespace std;

int totalsum(int a[], int n)
{
	int sum[10005];
	for(int i=0; i<10005; ++i) sum[i]= -1;
	
	sum[0]= 0;
	
	int num=0;
	
	for(int i=0; i<n; ++i)
	{
		num++;
		sum[i]= 1;
		for(int j=i+1; j<n; ++j)
		{
			if(sum[a[i] + a[j]] == -1)
			{
				sum[a[i] + a[j]]= 1;
				num++;
			}
		}
	}
	return num;
}

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		
		cout<<totalsum(a, n);
	}
	
	
	
	return 0;
}
