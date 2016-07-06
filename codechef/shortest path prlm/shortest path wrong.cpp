#include <iostream>
#include<algorithm>
using namespace std;

int mini(int a, int b, int c){
	return min(min(a, b), c);
	}

int main() {
	// your code goes here
	
	int x, y;
	cin>>x;
	while(x!=0){
			cin>>y;
	int a[x][y]; long sum[x][y];
	for(int i=0; i<x; ++i)
	{
		for(int j=0; j<y; ++j)
		{
			cin>>a[i][j];
		}
	}
	

	
	sum[0][0]= a[0][0];
	for(int i=1; i<x; ++i)sum[i][0]= a[i][0]+ sum[i-1][0];
	for(int j=1; j<y; ++j)sum[0][j]= a[0][j]+ sum[0][j-1];
	
	
	for(int i=1; i<x; ++i)
	{
		for(int j=1; j<y; ++j) 
			sum[i][j]= min(sum[i-1][j], sum[i][j-1]) + a[i][j];
	}
	
/*		for(int i=0; i<x; ++i)
		{
			for(int j=0; j<y; ++j) cout<<sum[i][j]<<" "; cout<<endl;
		} */
	
	
	cout<<sum[x-1][y-1]<<endl; 
		
		
		cin>>x;
	}
	
	return 0;
}
