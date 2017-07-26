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

	int l= s.length();
	char arr[l];

	int flag=0, i;
	for(i=0; i<l/2; ++i) arr[i] = s[i];

	int rev= (l%2==0)?l/2:l/2+1; cout<<rev<<endl;
	for(int j=rev; j<l; ++j){ 

		i--;
		if(arr[i] != s[j]){ 
			flag=1;
			break;
		}
	}

	if(flag==1) cout<<"not a palindrome";
	else cout<<"palindrome!";

    return 0;
}
