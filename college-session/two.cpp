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

	int *p= (int*)malloc(n*sizeof(int));
	FOR(i, n) cin>>p[i];

	int maximum= p[0];
	FOR1(i, n){
		maximum= max(p[i], maximum);
	}

	cout<<maximum;

    return 0;
}
