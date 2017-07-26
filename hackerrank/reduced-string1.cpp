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

	string s;
	cin>>s;
	stack<char> charStack;

	FOR(i, s.length())
	{
		if(charStack.size() == 0) charStack.push(s[i]);
		else if(s[i] == charStack.top()) charStack.pop();
		else charStack.push(s[i]);
	}

 	string temp="";
 	while(charStack.size() != 0){
 		temp+= charStack.top(); 
 		charStack.pop();
 	}

 	if(temp.length() == 0) cout<<"Empty String";
 	else
 		FORrev(i, temp.length()) cout<<temp[i];

    return 0;
}
