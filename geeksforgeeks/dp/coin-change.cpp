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

int coinChange(int den[], int m, int n){
    int arr[m][n+1];
    FOR(i, n+1) arr[i][0]= 1;

    int x, y;

    FOR(i, m){
        FOR1(j, n+1){
            // arr[i][j]= arr[i][j-1] + arr[i][j- den[i]];

            x= (j- den[i] >= 0)?(arr[i][j-den[i]]):0;
            y= (i>=1)?arr[i-1][j]:0;
            arr[i][j]= x+y;
        }
    }

    return arr[m-1][n];
}

int main() {

    int n, m; // m- no of denominations of coins available, n- total value to break
    cin>>n>>m;

    int den[m];
    FOR(i, m) cin>>den[i];

    cout<<"no of ways to form n: "<<coinChange(den, m, n)<<endl;

    return 0;
}
