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

	int m, n;
	cin>>m>>n;

	char *s1= (char*)malloc(m*sizeof(char));
	char *s2= (char*)malloc(n*sizeof(char));
	FOR(i, m) cin>>s1[i];
	FOR(i, n) cin>>s2[i];
	

    return 0;
}
