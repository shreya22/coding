#include <iostream>
using namespace std;

int coins(int sum, int a[], int n)
{
	int min[sum+1]; min[0]= 0;
	for(int i=1; i<=sum; ++i)
		min[i]= 10078;
	
	for(int i=1; i<=sum; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			//cout<<"hihjji";
			if(((min[i-a[j]] +1) < min[i]))
			{
				min[i]= min[i-a[j]]+1;
			//	cout<<"hihi";
			}
			//	
		}
		cout<<min[i]<<" ";
	}
	
	return min[sum];
}

int main() {
	// your code goes here
	
	int sum, n;
	cin>>sum>>n;
	
	int a[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];
	
	cout<<coins(sum, a, n);
	
	
	
	
	return 0;
}
