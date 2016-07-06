#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;


int main() {
	// your code goes here
	
	int n;
	cin>>n;
	int c;
	cin>>c;
	int a[c][2];
	for(int i=0; i<c; ++i)
		for(int j=0; j<2; ++j)
			cin>>a[i][j];
			
	int x= n-c;
	long long int y= x*(x-1)*(x-2)/6;
	long long z= pow(2, c);
	
	long long ans= y*z;
	cout<<ans;
	
	
	return 0;
}
