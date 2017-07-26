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

int lcs(string a, string b)
{
    int m= a.length(), n= b.length();
    int arr[m+1][n+1];

    FOR(i, m+1)arr[i][0]= 0;
    FOR(j, n+1)arr[0][j]= 0;

    FOR1(i, m+1){
        FOR1(j, n+1){
            if(a[i]== b[j]) arr[i][j]= arr[i-1][j-1]+1;
            else arr[i][j]= max(arr[i-1][j], arr[i][j-1]);
        }
    }

    return arr[m][n];
}

int main() {

    string a, b;
    cin>>a>>b;

    cout<<lcs(a, b);

    return 0;
}
