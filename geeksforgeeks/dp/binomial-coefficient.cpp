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

int binomalCoefficient(int n, int k)
{
    int arr[n+1][k+1];
    FOR(i, n+1){
        FOR(j, min(i, k)+1){
            if(j==0 || j==i)
                arr[i][j]= 1;
            else
                arr[i][j]= arr[i-1][j-1] + arr[i-1][j];
        }
    }

    return arr[n][k];
}

int main() {

    int n, k;
    cin>>n>>k;
    cout<<"binomal coefficient nCk: "<<binomalCoefficient(n, k)<<endl;

    return 0;
}
