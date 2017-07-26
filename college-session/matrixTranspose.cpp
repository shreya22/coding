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
	int *a[max(m, n)];

	FOR(i, max(m, n)) 
		a[i]= (int*) malloc(max(m, n)*sizeof(int));

	// FOR(i, max(m, n))
	// 	FOR(j, max(m, n))
	// 		a[i][j]= 0;

	FOR(i, m)
		FOR(j, n)
			cin>>a[i][j];

	int temp;
	FOR(i, m)
		FOR(j, n){
			temp= a[i][j];
			a[i][j]= a[j][i];
			a[j][i]= temp;
		}

	FOR(i, n)
	{
		FOR(j, m)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}

    return 0;
}
