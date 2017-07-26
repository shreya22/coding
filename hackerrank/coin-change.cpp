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

ll coinChange(int c[], int n, int m){
    ll arr[n+1][m];

    FOR(j, m) arr[0][j]= 1;
    FOR1(i, n+1){
        FOR(j, m){
            ll x, y;
            x= (i - c[j] >= 0)?arr[i-c[j]][j]:0;
            y= (j-1 >= 0)?arr[i][j-1]:0;

            arr[i][j]= x+y;
        }
    }

    return arr[n][m-1];
}

int main() {

    int n, m;
    cin>>n>>m;
    int c[m];
    FOR(i, m) cin>>c[i];

    cout<<coinChange(c, n, m);

    return 0;
}
