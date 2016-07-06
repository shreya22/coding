#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include<cstdio>

//#define int a[10000];

using namespace std;
int main()
{
	
	int a[10000]= {0};
	int t;
	cin>>t;
	while(t--)
	{
		int index= 0;
		int n, m;
		cin>>n;m=n;
		
		if(n==0) cout<<"0\n";
		else
		{
				for(int i=0; m>0; ++i)
		{
			a[index++] = m%10;
			m= m/10; 
		}

		
	
		
		int len= index;
		
		int p=0, q=0; index=0;
		for(int i= n-1; i>=2; --i)
		{
			index= 0;
			for(int j=0; j<len; ++j)
			{
				p= a[index]*i+q;
				a[index]= p%10; 
				index++;
				q= p/10;
			}
			
			while(q)
			{
				a[index]= q%10; 
				index++;
				q= q/10;
				len++;
			}
	
		} 
		
		for(int i=0; i<len; ++i)
		cout<<a[len-i-1];
		cout<<endl;
		}
	}
	
	return 0;
}
