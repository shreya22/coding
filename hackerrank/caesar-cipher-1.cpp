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

	int n;
	cin>>n;
	char arr[n];
	FOR(i, n) cin>>arr[i];
	int k; cin>>k;

	FOR(i, n)
	{
		if(arr[i]>='a' && arr[i]<='z'){
			if(char(int(arr[i])+k) > 'z') arr[i]= char(int('a')+ int(arr[i]) + k - int('z') -1);
			else arr[i]= char(int(arr[i])+k);
		}else if(arr[i]>='A' && arr[i]<='Z'){
			if(char(int(arr[i])+k) > 'Z') arr[i]= char(int('A')+ int(arr[i]) + k - int('Z') -1);
			else arr[i]= char(int(arr[i])+k);
		}else;
	}

	FOR(i, n) cout<<arr[i];

    return 0;
}
