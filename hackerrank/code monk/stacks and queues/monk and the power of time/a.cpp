#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

#define ll long long
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define FOR(i, m, n) for(ll i=0; i<m; i+=n)


int main() {
	// your code goes here
	
	int n;
	cin>>n;
	
	stack<ll> b;
	queue<ll> a;
	
	int x, y;
	FOR(i, n, 1)
	{
		cin>>x;
		a.push(x);
	}
	
	int temp; 
	temp= a.front(); cout<<temp;
	a.pop();
	temp= a.front(); cout<<temp;
	a.push(8);
	temp= a.front(); cout<<temp;
	//temp= a.rear(); cout<<temp;

	
	//cout<<sum;
	
	return 0;
}
