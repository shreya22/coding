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
    int s[n];
    FOR(i, n) cin>>s[i];
    int d, m;
    cin>>d>>m;

    int p=0, q=m-1, tempSum=0, count=0;
    FOR(i, m) tempSum+= s[i];

    while(q<n)
    {
        if(tempSum == d) count++;
        p++; q++;
        tempSum= tempSum - s[p-1] + s[q];
    }
    cout<<count;

    return 0;
}
