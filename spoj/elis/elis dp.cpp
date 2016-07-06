#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	int a[n]; int b[n];
	
	for(int i=0; i<n; ++i){
		 cin>>a[i];
		 b[i]= 0;
	}
	
	int flag=0, x=0, max=0;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<i; ++j)
		{
			if(a[i]>a[j])
			{
				if(b[j]>b[i]) {
					x= b[j];
					max= (max>x)?max:x;
				}
			}
		}
		b[i]= max+1;
		max= 0;
		
		cout<<b[i]<<" ";
	}
	cout<<endl;
	int temp=0;
	for(int i=0; i<n; ++i) temp= (temp>b[i])?temp:b[i];
	cout<<temp<<endl;
	
	return 0;
}
