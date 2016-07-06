#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define FOR(i, m, n) for(ll i=0; i<m; i+=n)

int bSearch(int a[], int x, int y, int n)
{
	if(x==y)
	{
		if(a[x]==n) return true;
		else return false;
	}
	
	int mid= (x+y)/2;
	if(a[mid] == n) return true;
	else
		if(a[mid] > n) 
			return (bSearch(a, x, mid, n));
		else
			return bSearch(a, mid+1, y, n);
	
}

int main() {
	// your code goes here
	
	int n, q;
	cin>>n>>q;
	int a[n], b[q];
	
	FOR(i, n, 1) cin>>a[i];
	FOR(i, q, 1) cin>>b[i];
	
	sort(a, a+n);
	
	FOR(i, q, 1)
	{
		if(bSearch(a, 0, n-1, b[i])) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	
	return 0;
}
