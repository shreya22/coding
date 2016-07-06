#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char x[250001], y[250001];

int fun(int i, int j) {
	if(x[i]==y[j])return 1;
	return 0;
}

int main()
{
	string a, b;
	cin>>a>>b;
	
	int l1, l2;
	
	l1= a.length(); l2= b.length();
	for(int i=1; i<=l1; ++i)x[i]= a[i-1];
	for(int i=1; i<=l2; ++i)y[i]= b[i-1];
	
//	int cnt=0;
	int cnt[l1+1][l2+1];
	
	for(int i=0; i<=l1; ++i)
	{
		for(int j=0; j<=l2; ++j){
			if(i==0 || j==0)cnt[i][j]=0;
			
			cnt[i][j]= max(cnt[i-1][j-1]+fun(i, j), cnt[i][j-1], cnt[i-1][j]);
		}
	}
	
	cout<<cnt[l1][l2];
}
