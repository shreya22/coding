#include <iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
 
#define ll long long
#define l long
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define FOR(i, m, n) for(ll i=0; i<m; i+=n)
#define FOR1(i, m, n) for(ll i=1; i<=m; i+=n)

int main() {
	// your code goes here
	
	set<string> str;
	set<string>::iterator it;
	//string s;
	char s[100000];
	
	int n;
	cin>>n;
	FOR(i, n, 1)
	{
		scanf("%s", &s);
		//cin>>s;
		str.insert(s);
	}
	
	cout<<str.size()<<endl;
	for(it= str.begin(); it!= str.end(); it++)
	{
		//printf("%s", it);
		cout<<*it<<endl;
	}
	
	return 0;
}
