#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	
	long n;
	cin>>n;
	
	long int sum=0, temp=0, c=0, a[10];
	while(n){
		a[c]= n%10;
		n=n/10;
		c++;
	}
/*	for(int i=0; i<c/2; ++i){
		temp= a[i];
		a[i]= a[c-1];
		a[c-1]= temp;
	}  */
	
	for(int i=0; i<c; ++i) {
		if(a[i]==4) a[i]=0;
		else a[i]= 1;
	}
	
	for(int i=0; i<c; ++i)
	{
		sum= sum + a[i]*pow(2, i);
	}
	sum++;
//	cout<<sum<<endl;
	for(int i=1; i<c; ++i)sum+= pow(2, i);
	cout<<sum;
	
	
	return 0;
}
