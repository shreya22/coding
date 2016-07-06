#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define max(a, b) (a>=b?a:b)
#define FOR(i, m, n) for(int i=0; i<m; i+=n)

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int m, n;
		cin>>m>>n;
		
		int a[m], b[n], c[m+n];
		
		FOR(i, m, 1) cin>>a[i];
		FOR(i, n, 1) cin>>b[i];
		
		int j=0, k=0;
		
		FOR(i, m+n, 1)
		{	
			if(j== m){
				c[i] = b[k]; 
				k++;
			}
			else if(k== n)
			{
				c[i] = a[j]; 
				j++;
			}
			else
			{
				c[i] = max(a[j],b[k]);
				if(c[i] == a[j]) j++;
				else k++;
			}
		}
		
		FOR(i, m+n, 1) cout<<c[i]<<" ";
		cout<<endl;
		
	}
	
	
	return 0;
}
