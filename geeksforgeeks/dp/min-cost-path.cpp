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
    int way[m][n];
    int arr[m][n];

    FOR(i, m)
        FOR(j, n)
            cin>>way[i][j];

    int d1, d2;
    cout<<"destination: ";
    cin>>d1>>d2;

    arr[0][0]= way[0][0];
    FOR1(i, d1+1) arr[i][0]= arr[i-1][0]+ way[i][0];
    FOR1(j, d2+1) arr[0][j]= arr[0][j-1]+ way[0][j];

    FOR1(i, d1+1){
        FOR1(j, d2+1){
            arr[i][j]= min(arr[i-1][j-1], min(arr[i][j-1], arr[i-1][j])) + way[i][j];
        }
    }

    FOR(i, m){
        FOR(j, n) cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    cout<<"min cost path is: "<<arr[d1][d2]<<endl;

    return 0;
}
