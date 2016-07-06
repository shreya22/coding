#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int n, w, cnt=1;
		cin>>n>>w;
		int a[n][2], b[n], j=0;
		for(int i=0; i<n; ++i)
		{
			cin>>a[i][0];
			cin>>a[i][1]; b[i]= a[i][1];
		}
		
		sort(b, b+n);
		
	//	for(int i=0; i<n; ++i) cout<<b[i]<<" ";
	//	cout<<endl;
		
		int c=0;
		for(int i=1; i<n; ++i)
		{
			if(b[i]!= b[i-1])
			{
			//	cout<<"ji\n";
				if(b[i]-b[c] >w)
				{
					c=i;
					cnt++;
				}
			}
		}
	//	cnt++;
		cout<<cnt<<endl;
		
		
	}
	
	
	return 0;
}
