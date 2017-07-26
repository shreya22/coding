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

int makeString(string s, char a, char b){
	int flag=0;
	string tempStr= "";

	FOR(i, s.length()) if(s[i] == a || s[i]== b) tempStr+=s[i];
	FOR1(i, tempStr.length()){
		if (tempStr[i] == tempStr[i-1]) return 0;
	}

	return tempStr.length();
}

int main() {

	int n;
	cin>>n;
	string s;
	cin>>s;

	set<char> charSet;
	FOR(i, n) charSet.insert(s[i]);

	int len=0;
	FOR(i, charSet.size()-1)
	{
		for(int j=i+1; j<charSet.size(); ++j)
		{	
			int temp= makeString(s, s[i], s[j]);
			if(temp > len) len= temp;
		}
	}

	cout<<len;

    return 0;
}
