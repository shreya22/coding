#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; ++i)
#define FOR1(i, n) for(int i=1; i<n; ++i)
#define FORrev(i, n) for(int i=n-1; i>=0; --i)
#define pb push_back
#define ll long long

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int main() {

	string s, ss="", temp;
	cin>>s;

	int i=1, cnt=1;

	while(s.length()!= ss.length())
	{
		while(s[i]!='\0'){
			if(s[i] != s[i-1]){
				if(cnt%2!=0) ss+=s[i-1];
				cnt=1;
			}else cnt++;
			i++; 
		}
		if(cnt%2!=0) ss+= s[i-1];

		if(s.length() == ss.length()) break;

		s= ss;
		ss= "";
		i=1; cnt=1;
	}
	

	if(ss.length()==0) cout<<"Empty String";
	else cout<<ss;

    return 0;
}
