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
	
	int q;
	cin>>q;
	
	stack<ll> stk;

	long int val;
	
	FOR(i, q, 1)
	{
		
		int a, b;
		cin>>a;
		
		if(a == 1)
		{
			//customer query
			
			
			if(!stk.size())
				cout<<"No Food\n";
			else
			{
				val= stk.top();
				cout<<val<<endl;
				stk.pop();
			}
			
			
			//cout<<"customer\n";
		}
		else
		{
			//chef's query
			 
			cin>>b;
			stk.push(b);
			
			//cout<<"chef\n";
		}
		
		
	}
	
	
	
	return 0;
}
