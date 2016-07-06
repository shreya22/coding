#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char x[2001], y[2001];
	string a, b;
int cnt[2001][2001];

int mini(int i, int j, int k) {
	return min(min(i, j), k);
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		
	cin>>a>>b;
	
	int l1, l2;
	
	l1= a.length(); l2= b.length();
	for(int i=1; i<=l1; ++i)x[i]= a[i-1];
	for(int i=1; i<=l2; ++i)y[i]= b[i-1];
	
	
	
	for(int i=0; i<=l1; ++i){
		for(int j=0; j<=l2; ++j){
			if(i==0) cnt[i][j]= j;
			else if(j==0) cnt[i][j]= i;
			else{
				if(x[i]==y[j]) cnt[i][j]= cnt[i-1][j-1];
				else cnt[i][j]= mini(cnt[i-1][j-1]+1, cnt[i-1][j]+1, cnt[i][j-1]+1);
			}
		}
	}
	
	cout<<cnt[l1][l2]<<endl;
	}
	

}
