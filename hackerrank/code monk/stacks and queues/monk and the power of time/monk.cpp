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
	
	stack<ll> b, c;
	queue<ll> a;
	
	int x, y;
	FOR(i, n, 1)
	{
		cin>>x;
		a.push(x);
	}
	
	FOR(i, n, 1)
	{
		cin>>y;
		c.push(y);
	}
	
	int t;
	FOR(i, n, 1)
	{
		t= c.top();
		b.push(t);
		c.pop();
	}
//int sum=0;

	
	int p, q, sum=0, cnt=0;
	FOR(i, n, 1)
	{
		cnt=0;
		x= a.front();
		y= b.top();
		
		while(x != y)
		{
			p= x;
			a.pop();
			a.push(p);
			
			x= a.front();
			cnt++;
			//cout<<cnt<<endl;
		}
		sum+= cnt+1;
		
		a.pop();
		b.pop();
	}
/*	
	FOR(i, n, 1)
	{
		cout<<a.front()<<" ";
		a.pop();
	}
	cout<<endl;
	FOR(i, n, 1)
	{
		cout<<b.top()<<" ";
		b.pop();
	}
*/
	
	cout<<sum;
	
	return 0;
}
